using UnrealBuildTool;

public class ALS : ModuleRules
{
	public ALS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "NetCore", "PhysicsCore", "GameplayTags", "AnimGraphRuntime", "ControlRig", "RigVM", "Niagara"
		});
	}
}