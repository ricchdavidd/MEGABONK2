using UnrealBuildTool;
public class Brumaferal : ModuleRules {
 public Brumaferal(ReadOnlyTargetRules Target) : base(Target) {
  PCHUsage=PCHUsageMode.UseExplicitOrSharedPCHs;
  PublicDependencyModuleNames.AddRange(new string[]{"Core","CoreUObject","Engine","InputCore","ProceduralMeshComponent"});
 }
}
