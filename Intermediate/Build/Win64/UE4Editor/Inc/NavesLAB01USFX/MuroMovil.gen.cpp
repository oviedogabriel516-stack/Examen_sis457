// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavesLAB01USFX/MuroMovil.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMuroMovil() {}
// Cross Module References
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuroMovil_NoRegister();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuroMovil();
	NAVESLAB01USFX_API UClass* Z_Construct_UClass_AMuro();
	UPackage* Z_Construct_UPackage__Script_NavesLAB01USFX();
// End Cross Module References
	void AMuroMovil::StaticRegisterNativesAMuroMovil()
	{
	}
	UClass* Z_Construct_UClass_AMuroMovil_NoRegister()
	{
		return AMuroMovil::StaticClass();
	}
	struct Z_Construct_UClass_AMuroMovil_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMuroMovil_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMuro,
		(UObject* (*)())Z_Construct_UPackage__Script_NavesLAB01USFX,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMuroMovil_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MuroMovil.h" },
		{ "ModuleRelativePath", "MuroMovil.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMuroMovil_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMuroMovil>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMuroMovil_Statics::ClassParams = {
		&AMuroMovil::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMuroMovil_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMuroMovil_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMuroMovil()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMuroMovil_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMuroMovil, 1417386046);
	template<> NAVESLAB01USFX_API UClass* StaticClass<AMuroMovil>()
	{
		return AMuroMovil::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMuroMovil(Z_Construct_UClass_AMuroMovil, &AMuroMovil::StaticClass, TEXT("/Script/NavesLAB01USFX"), TEXT("AMuroMovil"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMuroMovil);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
