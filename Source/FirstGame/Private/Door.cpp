// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "BossActor.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    //�������ǵ�Ĭ�����
    DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrameMesh"));
    Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
    DoorTimelineComp = CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimelineComp"));

    //���ð�
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
    // ����ʱ�������ߵ�����������������ŵ������λ��
    FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
    Door->SetRelativeRotation(DoorNewRotation);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
    //���������󶨵�UpdateTimelineComp���������
    UpdateFunctionFloat.BindDynamic(this, &ADoor::UpdateTimelineComp);

    //����и������ߣ�����ͼ��󶨵����ǵĸ��º���
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

