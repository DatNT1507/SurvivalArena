// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SurvivalArena : ModuleRules
{
	public SurvivalArena(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SurvivalArena",
			"SurvivalArena/Variant_Platforming",
			"SurvivalArena/Variant_Platforming/Animation",
			"SurvivalArena/Variant_Combat",
			"SurvivalArena/Variant_Combat/AI",
			"SurvivalArena/Variant_Combat/Animation",
			"SurvivalArena/Variant_Combat/Gameplay",
			"SurvivalArena/Variant_Combat/Interfaces",
			"SurvivalArena/Variant_Combat/UI",
			"SurvivalArena/Variant_SideScrolling",
			"SurvivalArena/Variant_SideScrolling/AI",
			"SurvivalArena/Variant_SideScrolling/Gameplay",
			"SurvivalArena/Variant_SideScrolling/Interfaces",
			"SurvivalArena/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
