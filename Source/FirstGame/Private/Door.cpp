// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "BossActor.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //创建我们的默认组件
    DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComp"));

    //设置绑定
    DoorFrame->SetupAttachment(RootComponent);
    Door->AttachToComponent(DoorFrame, FAttachmentTransformRules::KeepRelativeTransform);
    Door->SetRelativeLocation(FVector(0, 35, 0));
}

void ADoor::BossDiedEventFunction()
{
    DoorTimelineComp->Play();
}

void ADoor::UpdateTimelineComp(float Output)
{
    // 基于时间轴曲线的输出，创建并设置门的新相对位置
    FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
    Door->SetRelativeRotation(DoorNewRotation);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
    //将浮点轨道绑定到UpdateTimelineComp函数的输出
    UpdateFunctionFloat.BindDynamic(this, &ADoor::UpdateTimelineComp);

    //如果有浮点曲线，将其图表绑定到我们的更新函数
    if (DoorTimelineFloatCurve)
    {
        DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
    }

    if (BossActorReference)
    {
        BossActorReference->OnBossDied.BindUObject(this, &ADoor::BossDiedEventFunction);
    }
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

