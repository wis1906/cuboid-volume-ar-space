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
        // ���Ĵٵ� ��� ���Ӽ�
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

        bool isLibrarySupported = false;

        // OpenCV ���
        string OpenCVPath = Path.Combine(ThirdPartyPath, "OpenCV");
        // Library ���
        string LibPath = "";

        // Ÿ�� �÷��� Ȯ�� �� Library ��� ����
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(OpenCVPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }

        // ���̺귯�� ���� �ε�
        if (isLibrarySupported)
        {
            // Includes ���� ��� �߰�
            PublicIncludePaths.AddRange(new string[] { Path.Combine(OpenCVPath, "Includes") });

            // Library ��� �߰�
            PublicLibraryPaths.Add(LibPath);

            // lib ���� �ε�
            PublicAdditionalLibraries.Add("opencv_world410.lib");

            // dll ���� �ε�
            PublicDelayLoadDLLs.Add("opencv_world410.dll");
            PublicDelayLoadDLLs.Add("opencv_ffmpeg410_64.dll");

        }

        PublicDefinitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isLibrarySupported ? 1 : 0));
    }
}
