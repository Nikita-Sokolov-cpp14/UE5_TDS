// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMADamageActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class MY_TDS_API ALMADamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Damage = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float SphereRadius = 100.0f;

	// Sets default values for this actor's properties
	ALMADamageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
