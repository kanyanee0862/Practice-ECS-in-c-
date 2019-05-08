#include "Component.h"
#include "Actor.h"
//------------------------------------------------------
//------------------------------------------------------
//�R���X�g���N�^
//------------------------------------------------------
Component::Component(class Actor* owner,int updateOrder)
	:mOwner(owner),
	mUpdateOrder(updateOrder)
{
	//�R���|�l���g���A�N�^�[�ɒǉ�����
	mOwner->AddComponent(this);
}
//------------------------------------------------------
//�f�X�g���N�^
//------------------------------------------------------
Component::~Component()
{
	//Deallocate this component
	mOwner->RemoveComponent(this);
}
//------------------------------------------------------
//���Ԃ��X�V����
//------------------------------------------------------
void Component::Update(float deltaTime)
{

}