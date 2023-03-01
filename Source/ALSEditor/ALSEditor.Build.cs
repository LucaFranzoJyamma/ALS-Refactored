using UnrealBuildTool;

public class ALSEditor : ModuleRules
{
	public ALSEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		PrivateDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "AnimationModifiers", "AnimationBlueprintLibrary", "ALS"
		});

		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.AddRange(new[]
			{
				"AnimGraph", "AnimGraphRuntime", "BlueprintGraph"
			});
		}
	}
}