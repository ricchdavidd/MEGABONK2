using UnrealBuildTool;
public class BrumaferalEditorTarget : TargetRules {
 public BrumaferalEditorTarget(TargetInfo Target) : base(Target) {
  Type=TargetType.Editor; DefaultBuildSettings=BuildSettingsVersion.Latest; ExtraModuleNames.Add("Brumaferal");
 }
}
