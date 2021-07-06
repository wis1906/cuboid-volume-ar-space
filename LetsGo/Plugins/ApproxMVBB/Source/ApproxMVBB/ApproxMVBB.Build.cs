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
        // ���Ĵٵ� ��� ���Ӽ�
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

        bool isLibrarySupported = false;

        // ApproxMVBB ���
        string ApproxMVBBPath = Path.Combine(ThirdPartyPath, "ApproxMVBB");
        // Library ���
        string LibPath = "";

        // Ÿ�� �÷��� Ȯ�� �� Library ��� ����
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(ApproxMVBBPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }

        // ���̺귯�� ���� �ε�
        if (isLibrarySupported)
        {
            // Includes ���� ��� �߰�
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ApproxMVBBPath, "Includes") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ApproxMVBBPath, "Includes"), "eigen3") });

            // Library ��� �߰�
            PublicLibraryPaths.Add(LibPath);

            // lib ���� �ε�
            PublicAdditionalLibraries.Add("ApproxMVBB.lib");

            // dll ���� �ε�
            PublicDelayLoadDLLs.Add("ApproxMVBB.dll");

        }
    }
}
