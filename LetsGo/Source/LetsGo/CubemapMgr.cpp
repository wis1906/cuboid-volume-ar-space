#include "CubemapMgr.h"

using namespace std;
using namespace cv;

ACubemapMgr::ACubemapMgr()
{
	PrimaryActorTick.bCanEverTick = true;

	FString path = mainST::getInst()->cubemapDataFilePath;
	cubeProjector = new CubemapProjector(TCHAR_TO_UTF8(*path), mainST::getInst()->panoramaWidth, mainST::getInst()->panoramaHeight);
}

void ACubemapMgr::BeginPlay()
{
	Super::BeginPlay();
	initTexture(cubeProjector->imageData->sz);
}

void ACubemapMgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ACubemapMgr::getFrame()
{
	bool isPlaying = cubeProjector->readFrame();
	if (!isPlaying)
		return false;

	//Update Texture
	updateTextureAll();

	//Update VideoFrame(For Blueprint)
	OnNextVideoFrame();
	return true;
}

void ACubemapMgr::initTexture(Size sz)
{
	//Init Texture
	TopTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	TopTexture->UpdateResource();
	BottomTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	BottomTexture->UpdateResource();
	RearTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	RearTexture->UpdateResource();
	LeftTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	LeftTexture->UpdateResource();
	FrontTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	FrontTexture->UpdateResource();
	RightTexture = UTexture2D::CreateTransient(sz.width, sz.height);
	RightTexture->UpdateResource();
}

void ACubemapMgr::updateTextureAll()
{
	//Update Texture
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->TopImg, TopTexture);
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->BottomImg, BottomTexture);
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->RearImg, RearTexture);
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->LeftImg, LeftTexture);
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->FrontImg, FrontTexture);
	updateTextureAtOneTime(cubeProjector->imageData->sz, &cubeProjector->imageData->RightImg, RightTexture);
}
void ACubemapMgr::updateTextureAtOneTime(Size sz, Mat* image, UTexture2D* texture)
{
	CData.Init(FColor(0, 0, 0, 255), sz.width * sz.height);
	if (image->data)
	{
		// Copy Mat data to Data array
		for (int y = 0; y < sz.height; y++)
		{
			for (int x = 0; x < sz.width; x++)
			{
				int i = x + (y * sz.height);
				CData[i].B = image->data[i * 3 + 0];
				CData[i].G = image->data[i * 3 + 1];
				CData[i].R = image->data[i * 3 + 2];
			}
		}

		FTexture2DMipMap& Mip = texture->PlatformData->Mips[0];
		void* pData = Mip.BulkData.Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(pData, CData.GetData(), CData.Num() * 4);
		Mip.BulkData.Unlock();
		texture->UpdateResource();
	}
}