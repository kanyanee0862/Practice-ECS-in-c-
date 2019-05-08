#pragma once

class Component
{
public:
	//コンストラクタ
	Component(class Actor* owner, int updateOrder = 100);
	//デストラクタ
	virtual ~Component();
	//時間より更新する
	virtual void Update(float deltaTime);
	//Get update order from a component
	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	//アクターオーナー
	class Actor* mOwner;
	//Update order
	int mUpdateOrder;
};
