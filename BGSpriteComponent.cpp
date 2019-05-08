#include "BGSpriteComponent.h"
#include "Actor.h"
//------------------------------------------------------
//Set default draw order to 10,because it's in background
//------------------------------------------------------
BGSprite::BGSprite(class Actor* owner, int drawOrder)
	:SpriteComponent(owner,drawOrder),
	mScrollSpeed(0.0f)
{
}
//------------------------------------------------------
// Update/draw overriden from parent
//------------------------------------------------------
void BGSprite::Update(float deltaTime) 
{
	//SpriteComponentÇÃçXêVèàóùÇ…éûçèÇìnÇ∑
	SpriteComponent::Update(deltaTime);
	//auto &bg = mBGTextures.begin();bg!=mBGTextures.end;++bg
	for (auto& bg : mBGTextures)
	{
		// Update the x offset
		bg.mOffset.x += mScrollSpeed * deltaTime;
		// If this is completely off the screen, 
		//reset offset to the right of the last bg texture
		if (bg.mOffset.x < -mScreenSize.x)
		{
			bg.mOffset.x = (mBGTextures.size() - 1) * mScreenSize.x-1 ;
		}
	}
}
//------------------------------------------------------
//Rendering
//------------------------------------------------------
void BGSprite::Draw(SDL_Renderer* renderer)
{
	// Draw each background texture
	for (auto& bg : mBGTextures)
	{
		SDL_Rect r;
		// Assume screen size dimensions
		r.w = static_cast<int>(mScreenSize.x);
		r.h = static_cast<int>(mScreenSize.y);
		//Center the rectangle around the position of the owner
		r.x = static_cast<int>(mOwner->GetPos().x  + bg.mOffset.x);
		r.y = static_cast<int>(mOwner->GetPos().y  + bg.mOffset.y);

		// Draw this background
		SDL_RenderCopy(renderer,
			bg.mTexture,
			nullptr,
			&r
		);
	}
}
//------------------------------------------------------
// Set the textures for the background
//------------------------------------------------------
void BGSprite::SetBGTextures(const std::vector<SDL_Texture*>& textures)
{
	int count = 0;
	for (auto tex : textures)
	{
		BGTexture temp;
		temp.mTexture = tex;
		// Each texture is screen width in offset
		temp.mOffset.x = count * mScreenSize.x;
		temp.mOffset.y = 0;
		mBGTextures.emplace_back(temp);
		count++;
	}
}