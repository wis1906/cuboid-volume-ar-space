using UnrealBuildTool;
using System.IO;

public class OpenCV410 : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../ThirdParty/")); }
    }

    public OpenCV410(ReadOnlyTargetRules Target) : base(Target)
    {
        // 스탠다드 모듈 종속성
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

        bool isLibrarySupported = false;

        // OpenCV 경로
        string OpenCVPath = Path.Combine(ThirdPartyPath, "OpenCV");
        // Library 경로
        string LibPath = "";

        // 타겟 플랫폼 확인 후 Library 경로 생성
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(OpenCVPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }

        // 라이브러리 파일 로드
        if (isLibrarySupported)
        {
            // Includes 폴더 경로 추가
            PublicIncludePaths.AddRange(new string[] { Path.Combine(OpenCVPath, "Includes") });

            // Library 경로 추가
            PublicLibraryPaths.Add(LibPath);

            // lib 파일 로드
            PublicAdditionalLibraries.Add("opencv_world410.lib");

            // dll 파일 로드
            PublicDelayLoadDLLs.Add("opencv_world410.dll");
            PublicDelayLoadDLLs.Add("opencv_ffmpeg410_64.dll");

        }

        PublicDefinitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isLibrarySupported ? 1 : 0));
    }
}
