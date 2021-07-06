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
        // 스탠다드 모듈 종속성
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "RHI", "RenderCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore" });

        bool isLibrarySupported = false;

        // ObjectBuilder 경로
        string ObjectBuilderPath = Path.Combine(ThirdPartyPath, "ObjectBuilder");
        // Library 경로
        string LibPath = "";

        // 타겟 플랫폼 확인 후 Library 경로 생성
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            LibPath = Path.Combine(ObjectBuilderPath, "Libraries", "Win64");
            isLibrarySupported = true;
        }

        // 라이브러리 파일 로드
        if (isLibrarySupported)
        {
            // Includes 폴더 경로 추가
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ObjectBuilderPath, "Includes") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "pcl-1.8") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "boost-1_64") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "eigen3") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "flann") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "OpenNI2") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "Qhull") });
            PublicIncludePaths.AddRange(new string[] { Path.Combine(Path.Combine(ObjectBuilderPath, "Includes"), "VTK") });

            // Library 경로 추가
            PublicLibraryPaths.Add(LibPath);

            // lib 파일 로드
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
