// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Door.generated.h"

UCLASS()
class FIRSTGAME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();
	// 用于保留曲线资产的变量
    UPROPERTY(EditInstanceOnly)
    UCurveFloat* DoorTimelineFloatCurve;

protected:

    UFUNCTION()
    void BossDiedEventFunction();

    UPROPERTY(EditInstanceOnly,BlueprintReadWrite)
    class ABossActor* BossActorReference;

    //表示门的网格体组件
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* DoorFrame;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* Door;

    //用于对门网格体进行动画处理的时间轴组件
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UTimelineComponent* DoorTimelineComp;

    //用于处理我们的更新轨道事件的浮点轨道签名
    FOnTimelineFloat UpdateFunctionFloat;

    //用于使用时间轴图表更新门相对位置的函数
    UFUNCTION()
    void UpdateTimelineComp(float Output);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
