#pragma once
#include <vector>
#include "glm/glm.hpp"
//Unreal �Ǝ��Ă��� 
class Actor
{
public:
	//Actor�̃X�e�[�^�X���m�F����ϐ�
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
	//�����A�N�^�[�������Ă���΁A�X�V����
	void Update(float deltaTime);
	//this->Actor�̃R���|�l���g���X�V���鏈��
	void UpdateComponents(float deltaTime);
	//�A�N�^�[�X�V���鏈��
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

	//�R���|�l���g��ǉ��E�폜
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
	//�A�j���[�V��������
	uint8_t mFrame;
	//Actor'States
	States mState;
	//Nested class 
	class Game* mGame;
	//Component��ǉ����邽�߂̃x�N�g���^
	std::vector<class Component*> mComponents;
	
};