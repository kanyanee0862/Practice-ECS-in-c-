#pragma once

class Component
{
public:
	//�R���X�g���N�^
	Component(class Actor* owner, int updateOrder = 100);
	//�f�X�g���N�^
	virtual ~Component();
	//���Ԃ��X�V����
	virtual void Update(float deltaTime);
	//Get update order from a component
	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	//�A�N�^�[�I�[�i�[
	class Actor* mOwner;
	//Update order
	int mUpdateOrder;
};
