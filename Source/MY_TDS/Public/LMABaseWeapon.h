// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMABaseWeapon.generated.h"

class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FAmmoWeapon
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Clips;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool Infinite;
};

UCLASS()
class MY_TDS_API ALMABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALMABaseWeapon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Fire();
	void StopFire();
	void ChangeClip();

	FAmmoWeapon GetCurrentAmmoWeapon() const { return CurrentAmmoWeapon; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	USkeletalMeshComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TraceDistance = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoWeapon AmmoWeapon{20, 0, true};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float shootsPerMinute = 500.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Shoot();

	void DecrementBullets();

	bool IsCurrentClipEmpty() const;

private:
	FAmmoWeapon CurrentAmmoWeapon;

	FTimerHandle ShootTimerHandle;
	
	float TimeOneShoot = 60 / shootsPerMinute;
};
