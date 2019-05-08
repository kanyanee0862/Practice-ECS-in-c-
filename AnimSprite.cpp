#include "AnimSprite.h"
#include "Actor.h"
#include<iostream>
//Constructor
AnimSprite::AnimSprite(class Actor* owner, int drawOrder)
	:SpriteComponent(owner,drawOrder),
	mCurrFrame(0.0f),
	mAnimFPS(24.0f)	
{
}
// Update animation every frame (overriden from component)
void AnimSprite::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);

	//ˆê–‡ˆÈã‚Å‚ ‚ê‚Î
	if (mAnimTextures.size() > 0)
	{
		// Update the current frame based on frame rate
		// and delta time
		mCurrFrame += mAnimFPS * deltaTime;
		if (mAnimTextures.size() > 1)
		{
			// Wrap current frame if needed
			while (mCurrFrame >= mAnimTextures.size())
			{
				mCurrFrame -= mAnimTextures.size();
			}
			// Set the current texture
			SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
		}
		else
		{
			//width 32 frame 8
			//Should change src data
			SetTexture(mAnimTextures[0]);
		}
		
	}
}
// Set the textures used for animation
void AnimSprite::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	mAnimTextures = textures;
	if (mAnimTextures.size() > 0)
	{
		// Set the active texture to first frame
		mCurrFrame = 0.0f;
		SetTexture(mAnimTextures[0]);
		
	}
}
