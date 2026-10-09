using UnrealBuildTool;
public class RiftboundEditorTarget : TargetRules {
    public RiftboundEditorTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        ExtraModuleNames.Add("Riftbound");
    }
}
