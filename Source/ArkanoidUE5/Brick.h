// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"




USTRUCT(BlueprintType)
struct FMyStruct2
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	float Score = 0.0f;
};

UCLASS()
class ARKANOIDUE5_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* Box_Collision;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
	class USoundBase* OverlapSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
	class UParticleSystem* DeathParticleSystem;

	//UPROPERTY(VisibleAnywhere)
	//class UParticleSystemComponent* PSC;

	UPROPERTY(EditAnywhere)
	class AArkanoidUE5GameModeBase* mode;

	UPROPERTY(EditAnywhere)
	UMaterial* TestMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInstanceDynamic* MI_TestMaterial = nullptr;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* OffMaterial;

	float SpeedModifierOnBounce = 1.01f;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep,
		const FHitResult& SweepResult);

	void DestroyBrick();


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

