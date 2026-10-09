using UnrealBuildTool;
public class RiftboundTarget : TargetRules {
    public RiftboundTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        ExtraModuleNames.Add("Riftbound");
    }
}
