// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSurvivalArena_init() {}
	SURVIVALARENA_API UFunction* Z_Construct_UDelegateFunction_SurvivalArena_OnDeathSignature__DelegateSignature();
	SURVIVALARENA_API UFunction* Z_Construct_UDelegateFunction_SurvivalArena_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SurvivalArena;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SurvivalArena()
	{
		if (!Z_Registration_Info_UPackage__Script_SurvivalArena.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SurvivalArena_OnDeathSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SurvivalArena_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SurvivalArena",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x22C95C57,
				0x895D6078,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SurvivalArena.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SurvivalArena.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SurvivalArena(Z_Construct_UPackage__Script_SurvivalArena, TEXT("/Script/SurvivalArena"), Z_Registration_Info_UPackage__Script_SurvivalArena, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x22C95C57, 0x895D6078));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
