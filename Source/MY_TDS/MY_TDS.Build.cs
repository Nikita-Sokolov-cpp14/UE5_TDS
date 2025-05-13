// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MY_TDS : ModuleRules
{
	public MY_TDS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
