#pragma once
#include "Actor.h"
#include "AnimSprite.h"
class Slime :public Actor
{
public:
	
	//Constructor
	Slime(class Game* game);
	void UpdateActor(float deltaTime) override;
	//This function for process keyboard in SDL
	void ProcessKeyboard(const uint8_t* state);
	float GetLRSpeed() const { return mLRSpeed; }
	float GetJumpSpeed() const { return mjumpSpeed; }
	
private:
	//v = gt
	//Gravity
	const float gravity = 9.8f / 60.0f / 60.0f;
	//Speed when player go right or left
	float mLRSpeed;
	//Speed when player jump
	float mjumpSpeed;
	//Fall speed
	float mfallSpeed;
	//Animesprtie
	AnimSprite* asc;
};