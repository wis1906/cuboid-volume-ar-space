using UnrealBuildTool;
using System.IO;

public class LetsGo : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }
    public LetsGo(ReadOnlyTargetRules Target) : base(Target)
    {
        bEnableExceptions = true;
        bUseRTTI = true;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "ShaderCore" });


        LoadOpenCV(Target);
        LoadApproxMVBB(Target);
        LoadObjectBuilder(Target);
    }

    public bool LoadOpenCV(ReadOnlyTargetRules Target)
    {
        // Start OpenCV linking here!
        bool isLibrarySupported = false;
        // Create OpenCV Path 
        string OpenCVPath = Path.Combine(ThirdPartyPath, "OpenCV");
        // Get Library Path 
        string LibPath = "";

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(OpenCVPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
        }

        if (isLibrarySupported)
        {
            //Add Include path 
            PublicIncludePaths.AddRange(new string[] { Path.Combine(OpenCVPath, "Includes") });

            // Add Library Path 
            PublicLibraryPaths.Add(LibPath);

            //Add Static Libraries
            PublicAdditionalLibraries.Add("opencv_world410.lib");

            //Add Dynamic Libraries
            PublicDelayLoadDLLs.Add("opencv_world410.dll");
            PublicDelayLoadDLLs.Add("opencv_ffmpeg410_64.dll");
        }

        PublicDefinitions.Add(string.Format("WITH_OPENCV_BINDING={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }


    public bool LoadApproxMVBB(ReadOnlyTargetRules Target)
    {
        // Start OpenCV linking here!
        bool isLibrarySupported = false;
        // Create OpenCV Path 
        string ApproxMVBBPath = Path.Combine(ThirdPartyPath, "ApproxMVBB");
        // Get Library Path 
        string LibPath = "";

        // Ÿ�� �÷��� Ȯ�� �� Library ��� ����
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(ApproxMVBBPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
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

        return isLibrarySupported;
    }

    public bool LoadObjectBuilder(ReadOnlyTargetRules Target)
    {
        // Start OpenCV linking here!
        bool isLibrarySupported = false;
        // ObjectBuilder ���
        string ObjectBuilderPath = Path.Combine(ThirdPartyPath, "ObjectBuilder");
        // Library ���
        string LibPath = "";

        // Ÿ�� �÷��� Ȯ�� �� Library ��� ����
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(ObjectBuilderPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }
        else
        {
            string Err = string.Format("{0} dedicated server is made to depend on {1}. We want to avoid this, please correct module dependencies.", Target.Platform.ToString(), this.ToString());
            System.Console.WriteLine(Err);
        }

        // ���̺귯�� ���� �ε�
        if (isLibrarySupported)
        {
            // Includes ���� ��� �߰�
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ObjectBuilderPath, "Includes") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "pcl-1.8") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "boost-1_64") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "eigen3") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "flann") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "OpenNI2") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "Qhull") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "VTK") });

            // Library ��� �߰�
            PublicLibraryPaths.Add(LibPath);

            // lib ���� �ε�
            PublicAdditionalLibraries.Add("object_builders_lib.lib");
            PublicAdditionalLibraries.Add("qhullstatic.lib");
            PublicAdditionalLibraries.Add("qhull_p.lib");
            PublicAdditionalLibraries.Add("pcl_common_release.lib");
            PublicAdditionalLibraries.Add("pcl_features_release.lib");
            PublicAdditionalLibraries.Add("pcl_filters_release.lib");
            PublicAdditionalLibraries.Add("pcl_io_ply_release.lib");
            PublicAdditionalLibraries.Add("pcl_io_release.lib");
            PublicAdditionalLibraries.Add("pcl_kdtree_release.lib");
            PublicAdditionalLibraries.Add("pcl_keypoints_release.lib");
            PublicAdditionalLibraries.Add("pcl_ml_release.lib");
            PublicAdditionalLibraries.Add("pcl_octree_release.lib");
            PublicAdditionalLibraries.Add("pcl_outofcore_release.lib");
            PublicAdditionalLibraries.Add("pcl_people_release.lib");
            PublicAdditionalLibraries.Add("pcl_recognition_release.lib");
            PublicAdditionalLibraries.Add("pcl_registration_release.lib");
            PublicAdditionalLibraries.Add("pcl_sample_consensus_release.lib");
            PublicAdditionalLibraries.Add("pcl_search_release.lib");
            PublicAdditionalLibraries.Add("pcl_segmentation_release.lib");
            PublicAdditionalLibraries.Add("pcl_stereo_release.lib");
            PublicAdditionalLibraries.Add("pcl_surface_release.lib");
            PublicAdditionalLibraries.Add("pcl_tracking_release.lib");
            PublicAdditionalLibraries.Add("pcl_visualization_release.lib");
        }
        return isLibrarySupported;
    }
}
