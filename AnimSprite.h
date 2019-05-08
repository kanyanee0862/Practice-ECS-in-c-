#pragma once
#include "SpriteComponent.h"
#include <vector>
class AnimSprite:public SpriteComponent
{
public:
	//•`‰æ‡ˆÊ‚Í100‚Éİ’è‚µAÅŒã‚É•`‰æ‚·‚é‡ˆÊ
	AnimSprite(class Actor* owner, int drawOrder = 100);
	// Update animation every frame (overriden from component)
	void Update(float deltaTime) override;
	// Set the textures used for animation
	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);
	// Set/get the animation FPS
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
	void SetSpriteFlip(SDL_RendererFlip flip) { spriteFlip = flip; }
private:
	// All textures in the animation
	std::vector<SDL_Texture*> mAnimTextures;
	// Current frame displayed
	float mCurrFrame;
	// Animation frame rate
	float mAnimFPS;
	
};

