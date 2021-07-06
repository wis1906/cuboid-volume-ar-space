using UnrealBuildTool;
using System.IO;

public class ObjectBuilder : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../ThirdParty/")); }
    }

    public ObjectBuilder(ReadOnlyTargetRules Target) : base(Target)
    {
        // ���Ĵٵ� ��� ���Ӽ�
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

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

    }
}
