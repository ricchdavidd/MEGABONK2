using UnrealBuildTool;
public class BrumaferalTarget : TargetRules {
 public BrumaferalTarget(TargetInfo Target) : base(Target) {
  Type=TargetType.Game; DefaultBuildSettings=BuildSettingsVersion.Latest; ExtraModuleNames.Add("Brumaferal");
 }
}
