// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/HealthComponent.h"

#ifdef SURVIVALARENA_HealthComponent_generated_h
#error "HealthComponent.generated.h already included, missing '#pragma once' in HealthComponent.h"
#endif
#define SURVIVALARENA_HealthComponent_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Delegate FOnDeathSignature *****************************************************
#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_9_DELEGATE \
SURVIVALARENA_API void FOnDeathSignature_DelegateWrapper(const FMulticastScriptDelegate& OnDeathSignature);


// ********** End Delegate FOnDeathSignature *******************************************************

// ********** Begin Class UHealthComponent *********************************************************
#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execTakeDamage);


SURVIVALARENA_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();

#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend struct Z_Construct_UClass_UHealthComponent_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SURVIVALARENA_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister(); \
public: \
	DECLARE_CLASS2(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SurvivalArena"), Z_Construct_UClass_UHealthComponent_NoRegister) \
	DECLARE_SERIALIZER(UHealthComponent)


#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UHealthComponent(UHealthComponent&&) = delete; \
	UHealthComponent(const UHealthComponent&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHealthComponent) \
	NO_API virtual ~UHealthComponent();


#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_11_PROLOG
#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UHealthComponent;

// ********** End Class UHealthComponent ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_Components_HealthComponent_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
