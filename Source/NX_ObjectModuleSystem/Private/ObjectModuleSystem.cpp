// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectModuleSystem.h"

void UObjectModuleSystem::InitObject(UObject* Object)
{
	ObjectsModules.Add(Object, TArray<UObject*>{});
}

void UObjectModuleSystem::InitObjectWithModules(UObject* Object, TArray<UObject*>* Modules)
{
	ObjectsModules.Add(Object, *Modules);
}




void UObjectModuleSystem::AttachModuleSafe(UObject* Object, UObject* Module)
{
	TArray<UObject*>* LArray = ObjectsModules.Find(Object);
	if (LArray) 
	{
		LArray->Add(Module);
	}
	else 
	{
		ObjectsModules.Emplace(Object, TArray<UObject*>{Module});
	}
}

void UObjectModuleSystem::DetachModuleSafe(UObject* Object, UObject* Module)
{
	TArray<UObject*>* LArray = ObjectsModules.Find(Object);
	if (LArray) {
		LArray->Remove(Module);
		if (LArray->IsEmpty())
		{
			ObjectsModules.Remove(Object);
		}
	}
}

TArray<UObject*>* UObjectModuleSystem::GetModules(UObject* Object)
{
	return ObjectsModules.Find(Object);
}

TArray<UObject*> UObjectModuleSystem::GetModulesCopy(UObject* Object)
{
	TArray<UObject*>* LArray = ObjectsModules.Find(Object);
	if (LArray) {
		TArray<UObject*> LArray2 = *LArray;
		return LArray2;
	}
	return TArray<UObject*>{};
}

UObject* UObjectModuleSystem::GetModuleByClass(UObject* Object, UClass* Class)
{
	TArray<UObject*>* LArray = GetModules(Object);
	if (!LArray) {
		return nullptr;
	}
	for (UObject* x : *LArray) {
		if (x->GetClass() == Class)
			return x;
	}
	return nullptr;
}
