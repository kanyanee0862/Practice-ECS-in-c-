#include "Actor.h"
#include "Game.h"
#include "Component.h"
//------------------------------------------------------
//Constructor : initialize when compile 
//------------------------------------------------------
Actor::Actor(class Game* game)
	:mPosition(0.0f,0.0f),
	mSize(0.0f,0.0f),
	mScale(0.0f),
	mRotation(0.0f),
	mState(Active),
	mGame(game)
{
	//呼ばれたアクターの初期化を代入
	mGame->AddActor(this);
}
//------------------------------------------------------
//Deallocate memory
//------------------------------------------------------
Actor::~Actor()
{
	//Remove Actor in class Game
	mGame->RemoveActor(this);
	//全部消すまでループする
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}
//------------------------------------------------------
//もしアクターが生きていれば、更新する
//------------------------------------------------------
void Actor::Update(float deltaTime)
{
	//Update only when active
	if (mState == Active)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}
//------------------------------------------------------
//this->Actorのコンポネントを更新する処理
//------------------------------------------------------
void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}
//------------------------------------------------------
//アクター更新する処理
//Will override by inherited class
//Overridable
//------------------------------------------------------
void Actor::UpdateActor(float deltaTime)
{

}
//------------------------------------------------------
//コンポネントを追加・削除
//------------------------------------------------------
void Actor::AddComponent(class Component* component)
{
	// Find the insertion point in the sorted vector
	// (The first element with a order higher than me)
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (;
		iter != mComponents.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	mComponents.insert(iter, component);
}
//------------------------------------------------------
//------------------------------------------------------
void Actor::RemoveComponent(class Component* component)
{
	//**
	//*Returns an iterator to the first element in the range[first, last) 
	//*that compares equal to val.If no such element is found, 
	//*the function returns last.
	//*
	//*		template <class InputIterator, class T>
	//*		InputIterator find(InputIterator first, InputIterator last, const T& val);
	//**
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}