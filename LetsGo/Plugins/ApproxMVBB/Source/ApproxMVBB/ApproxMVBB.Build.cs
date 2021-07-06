using UnrealBuildTool;
using System.IO;

public class ApproxMVBB : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../ThirdParty/")); }
    }

    public ApproxMVBB(ReadOnlyTargetRules Target) : base(Target)
    {
        // 스탠다드 모듈 종속성
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

        bool isLibrarySupported = false;

        // ApproxMVBB 경로
        string ApproxMVBBPath = Path.Combine(ThirdPartyPath, "ApproxMVBB");
        // Library 경로
        string LibPath = "";

        // 타겟 플랫폼 확인 후 Library 경로 생성
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(ApproxMVBBPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }

        // 라이브러리 파일 로드
        if (isLibrarySupported)
        {
            // Includes 폴더 경로 추가
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ApproxMVBBPath, "Includes") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ApproxMVBBPath, "Includes"), "eigen3") });

            // Library 경로 추가
            PublicLibraryPaths.Add(LibPath);

            // lib 파일 로드
            PublicAdditionalLibraries.Add("ApproxMVBB.lib");

            // dll 파일 로드
            PublicDelayLoadDLLs.Add("ApproxMVBB.dll");

        }
    }
}
