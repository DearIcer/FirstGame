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
	// ���ڱ��������ʲ��ı���
    UPROPERTY(EditInstanceOnly)
    UCurveFloat* DoorTimelineFloatCurve;

protected:

    UFUNCTION()
    void BossDiedEventFunction();

    UPROPERTY(EditInstanceOnly,BlueprintReadWrite)
    class ABossActor* BossActorReference;

    //��ʾ�ŵ����������
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* DoorFrame;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* Door;

    //���ڶ�����������ж��������ʱ�������
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    UTimelineComponent* DoorTimelineComp;

    //���ڴ������ǵĸ��¹���¼��ĸ�����ǩ��
    FOnTimelineFloat UpdateFunctionFloat;

    //����ʹ��ʱ����ͼ����������λ�õĺ���
    UFUNCTION()
    void UpdateTimelineComp(float Output);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
