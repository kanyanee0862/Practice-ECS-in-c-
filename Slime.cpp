#include"Slime.h"

#include "Game.h"
#include <iostream>
Slime::Slime(class Game* game)
	:Actor(game),
	mLRSpeed(0.0f),
	mjumpSpeed(0.0f),
	mfallSpeed(10.0f)
{
	//Created Anim Sprite
	asc = new AnimSprite(this);
	std::vector<SDL_Texture*> anims =
	{
		game->GetTexture("Assets/slime.png"),
	};
	asc->SetSpriteFlip(SDL_FLIP_HORIZONTAL);
	asc->SetAnimTextures(anims);
	
}
void Slime::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	//Update position based on speed and delta time
	glm::vec2 Pos = GetPos();
	//xŽ²‚Í‘¬“x‚É‚æ‚è•Ï‰»‚·‚é
	Pos.x += mLRSpeed * deltaTime;
	//yŽ²‚ÍƒWƒƒƒ“ƒv‚©—Ž‚¿‚é‚©‚É‰ž‚¶‚é
	Pos.y += mfallSpeed * deltaTime;
	if (Pos.x < 0.0f)
	{
		Pos.x = 0.0f;
	}
	else if (Pos.x >= 600.0f)
	{
		Pos.x = 600.0f;
	}
	
	
	SetPos(Pos);
}
void Slime::ProcessKeyboard(const uint8_t* state)
{
	mLRSpeed = 0.0f;
	mjumpSpeed = 0.0f;
	if (state[SDL_SCANCODE_LEFT])
	{
		mLRSpeed -= 250.0f;
		asc->SetSpriteFlip(SDL_FLIP_NONE);
	}
	if (state[SDL_SCANCODE_RIGHT])
	{
		mLRSpeed += 250.0f;
		asc->SetSpriteFlip(SDL_FLIP_HORIZONTAL);
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		mjumpSpeed = -500.0f;
		mfallSpeed = mjumpSpeed;
	}
	
}