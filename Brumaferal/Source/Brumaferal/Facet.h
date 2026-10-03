#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Materials/MaterialInterface.h"

// Each face owns its vertices so normals remain flat and silhouettes stay crisp.
struct FFacet {
 TArray<FVector> V,N;
 TArray<int32> I;
 TArray<FVector2D> UV;
 TArray<FLinearColor> C;
 void Tri(FVector A,FVector B,FVector D,FLinearColor Color){
  if(FVector::CrossProduct(B-A,D-A).SizeSquared()<.001)return;
  int32 K=V.Num(); FVector Normal=FVector::CrossProduct(B-A,D-A).GetSafeNormal();
  V.Append({A,B,D}); I.Append({K,K+2,K+1}); N.Append({Normal,Normal,Normal});
  C.Append({Color,Color,Color}); UV.Append({FVector2D(0,0),FVector2D(1,0),FVector2D(0,1)});
 }
 void Quad(FVector A,FVector B,FVector D,FVector E,FLinearColor Color){Tri(A,B,D,Color);Tri(A,D,E,Color);}
 void Box(FVector P,FVector S,FLinearColor Color){
  FVector A=P+FVector(-S.X,-S.Y,-S.Z),B=P+FVector(S.X,-S.Y,-S.Z),D=P+FVector(S.X,S.Y,-S.Z),E=P+FVector(-S.X,S.Y,-S.Z);
  FVector Z(0,0,2*S.Z);
  Quad(A,E,D,B,Color*.75f);Quad(A+Z,B+Z,D+Z,E+Z,Color*1.08f);
  Quad(A,B,B+Z,A+Z,Color*.86f);Quad(B,D,D+Z,B+Z,Color*.9f);Quad(D,E,E+Z,D+Z,Color);Quad(E,A,A+Z,E+Z,Color*.8f);
 }
 void Cone(FVector P,float R,float Top,float Height,FLinearColor Color,int32 Sides=7){
  for(int32 S=0;S<Sides;S++){
   float A=2*PI*S/Sides,B=2*PI*(S+1)/Sides;
   FVector A0=P+FVector(FMath::Cos(A)*R,FMath::Sin(A)*R,0),B0=P+FVector(FMath::Cos(B)*R,FMath::Sin(B)*R,0);
   FVector A1=P+FVector(FMath::Cos(A)*Top,FMath::Sin(A)*Top,Height),B1=P+FVector(FMath::Cos(B)*Top,FMath::Sin(B)*Top,Height);
   auto Shade=Color*(.83f+.17f*FMath::Sin(A+1));
   Quad(A0,B0,B1,A1,Shade);Tri(P,B0,A0,Shade);Tri(P+FVector(0,0,Height),A1,B1,Color);
  }
 }
 void Crystal(FVector P,float R,float H,FLinearColor Color){Cone(P,R,0,H,Color,5);Cone(P-FVector(0,0,H*.6f),0,R,H*.6f,Color*.8f,5);}
 void Apply(UProceduralMeshComponent* Mesh,bool Collision=false,bool Glow=false){
  Mesh->ClearAllMeshSections();Mesh->CreateMeshSection_LinearColor(0,V,I,N,UV,C,TArray<FProcMeshTangent>(),Collision);
  auto* Mat=LoadObject<UMaterialInterface>(nullptr,Glow?TEXT("/Game/Art/M_Glow.M_Glow"):TEXT("/Game/Art/M_Facet.M_Facet"));
  if(!Mat)Mat=LoadObject<UMaterialInterface>(nullptr,TEXT("/Engine/EngineDebugMaterials/VertexColorMaterial.VertexColorMaterial"));
  Mesh->SetMaterial(0,Mat);Mesh->SetCollisionEnabled(Collision?ECollisionEnabled::QueryAndPhysics:ECollisionEnabled::NoCollision);
 }
};
