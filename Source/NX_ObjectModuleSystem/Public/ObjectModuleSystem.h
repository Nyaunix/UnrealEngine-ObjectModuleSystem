// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Containers/Array.h"

#include "UObject/NoExportTypes.h"
#include "ObjectModuleSystem.generated.h"

UCLASS(Blueprintable)
class NX_OBJECTMODULESYSTEM_API UObjectModuleSystem : public UObject
{
	GENERATED_BODY()
	
public:	
	//Init
	UFUNCTION(BlueprintCallable, Category = "ObjectModuleSystem")
	void InitObject(UObject* Object);

	void InitObjectWithModules(UObject* Object, TArray<UObject*>* Modules);


	//Main
	UFUNCTION(BlueprintCallable, Category = "ObjectModuleSystem")
	void AttachModuleSafe(UObject* Object, UObject* Module);

	UFUNCTION(BlueprintCallable, Category = "ObjectModuleSystem")
	void DetachModuleSafe(UObject* Object, UObject* Module);

	

	//Getters
	TArray<UObject*>* GetModules(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "ObjectModuleSystem")
	TArray<UObject*> GetModulesCopy(UObject* Object);

	UFUNCTION(BlueprintCallable, Category = "ObjectModuleSystem", meta = (DeterminesOutputType = "Class"))
	UObject* GetModuleByClass(UObject* Object, UClass* Class);

protected:
	TMap<UObject*, TArray<UObject*>> ObjectsModules;
};
