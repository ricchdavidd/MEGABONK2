using UnrealBuildTool;
public class Riftbound : ModuleRules {
    public Riftbound(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new [] {"Core", "CoreUObject", "Engine", "InputCore", "NetCore"});
    }
}
