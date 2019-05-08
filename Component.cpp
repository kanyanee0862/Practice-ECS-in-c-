#include "Component.h"
#include "Actor.h"
//------------------------------------------------------
//------------------------------------------------------
//コンストラクタ
//------------------------------------------------------
Component::Component(class Actor* owner,int updateOrder)
	:mOwner(owner),
	mUpdateOrder(updateOrder)
{
	//コンポネントをアクターに追加する
	mOwner->AddComponent(this);
}
//------------------------------------------------------
//デストラクタ
//------------------------------------------------------
Component::~Component()
{
	//Deallocate this component
	mOwner->RemoveComponent(this);
}
//------------------------------------------------------
//時間より更新する
//------------------------------------------------------
void Component::Update(float deltaTime)
{

}