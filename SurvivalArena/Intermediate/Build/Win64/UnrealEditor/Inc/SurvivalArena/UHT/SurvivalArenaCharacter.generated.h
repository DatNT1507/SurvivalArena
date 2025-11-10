// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SurvivalArenaCharacter.h"

#ifdef SURVIVALARENA_SurvivalArenaCharacter_generated_h
#error "SurvivalArenaCharacter.generated.h already included, missing '#pragma once' in SurvivalArenaCharacter.h"
#endif
#define SURVIVALARENA_SurvivalArenaCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ASurvivalArenaCharacter **************************************************
#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


SURVIVALARENA_API UClass* Z_Construct_UClass_ASurvivalArenaCharacter_NoRegister();

#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASurvivalArenaCharacter(); \
	friend struct Z_Construct_UClass_ASurvivalArenaCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SURVIVALARENA_API UClass* Z_Construct_UClass_ASurvivalArenaCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ASurvivalArenaCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/SurvivalArena"), Z_Construct_UClass_ASurvivalArenaCharacter_NoRegister) \
	DECLARE_SERIALIZER(ASurvivalArenaCharacter)


#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ASurvivalArenaCharacter(ASurvivalArenaCharacter&&) = delete; \
	ASurvivalArenaCharacter(const ASurvivalArenaCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASurvivalArenaCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASurvivalArenaCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ASurvivalArenaCharacter) \
	NO_API virtual ~ASurvivalArenaCharacter();


#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_21_PROLOG
#define FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ASurvivalArenaCharacter;

// ********** End Class ASurvivalArenaCharacter ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SurvivalArena_SurvivalArena_Source_SurvivalArena_SurvivalArenaCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
