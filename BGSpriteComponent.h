#pragma once
#include"glm/glm.hpp"
#include "SpriteComponent.h"
#include <vector>
class BGSprite:public SpriteComponent
{
public:
	//Set default draw order to 10,because it'sÅ@background
	BGSprite(class Actor* owner, int drawOrder = 10);
	// Update/draw overriden from parent
	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	// Set the textures used for the background
	void SetBGTextures(const std::vector<SDL_Texture*>& textures);
	// Get/set screen size and scroll speed
	void SetScreenSize(const glm::vec2& size) { mScreenSize = size; }
	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
	float GetScrollSpeed() const { return mScrollSpeed; }
private:
	// Struct to encapsulate each bg image and its offset
	struct BGTexture
	{
		SDL_Texture* mTexture;
		glm::vec2 mOffset;
	};
	std::vector<BGTexture> mBGTextures;
	glm::vec2 mScreenSize;
	float mScrollSpeed;
};