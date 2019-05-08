#pragma once
#include <vector>
#include "glm/glm.hpp"
//Unreal と似ている 
class Actor
{
public:
	//Actorのステータスを確認する変数
	enum States
	{
		Active, 
		Dead, 
		Pending
	};
	//Constructor
	Actor(class Game* game);
	//Destructor
	virtual ~Actor();
	//もしアクターが生きていれば、更新する
	void Update(float deltaTime);
	//this->Actorのコンポネントを更新する処理
	void UpdateComponents(float deltaTime);
	//アクター更新する処理
	virtual void UpdateActor(float deltaTime);
	//Getter&Setter
	//Get/Set Position
	const glm::vec2& GetPos() const { return mPosition; }
	void SetPos(const glm::vec2& pos) { mPosition = pos; }
	//Get/Set Scale
	const float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	//Get/Set rotaion
	const float GetRotation() const { return mRotation; }
	void SetRotaion(float rotation) { mRotation = rotation; }
	//Get/Set State
	const States GetState() const { return mState; }
	void SetState(States state) { mState = state; }
	//Get W/H
	void SetSize (glm::vec2 size) { mSize = size; }
	const glm::vec2 GetSize() const { return mSize; }
	//For Animation
	void SetFrame(uint8_t frame) { mFrame = frame; }
	const uint8_t GetFrame() const { return mFrame; }
	//**
	//*Declarations in a nested class can use 
	//*any members of the enclosing class, 
	//*following the usual usage rules for the non-static members
	//*can access to all member in enclosing class
	//**
	class Game* GetGame() { return mGame; } //Declared nested class 

	//コンポネントを追加・削除
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
private:
	//Actor's Size width height
	glm::vec2 mSize;
	//Actor's position
	glm::vec2 mPosition;
	//Actor's scale
	float mScale;
	//Actor's rotation
	float mRotation;
	//アニメーション何枚
	uint8_t mFrame;
	//Actor'States
	States mState;
	//Nested class 
	class Game* mGame;
	//Componentを追加するためのベクトル型
	std::vector<class Component*> mComponents;
	
};