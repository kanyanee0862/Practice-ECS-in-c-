#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"
//------------------------------------------------------
//Constructor/Destructor
//Update順位を得、少なければ少ないほど、更新が早くなる
//------------------------------------------------------
SpriteComponent::SpriteComponent(class Actor* owner, int drawOrder)
	:Component(owner),
	mTexture(nullptr),
	mDrawOrder(drawOrder),
	spriteFlip(SDL_FLIP_NONE),
	mTexWidth(0),
	mTexHeight(0)
{
	owner->GetGame()->AddSprite(this);
}
//------------------------------------------------------
//Delete Sprite
//------------------------------------------------------
SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}
//------------------------------------------------------
//描画処理
//------------------------------------------------------
void SpriteComponent::Draw(SDL_Renderer* renderer)
{
	if (mTexture)
	{
		mTexWidth = static_cast<int>(mOwner->GetSize().x);
		mTexHeight = static_cast<int>(mOwner->GetSize().y);
		//SDL rectangle
		SDL_Rect drawRect,srcRect;
		// Scale the width/height by owner's scale
		drawRect.w = static_cast<int>(mTexWidth * (mOwner->GetScale()) );
		drawRect.h = static_cast<int>(mTexHeight * (mOwner->GetScale()) );
		drawRect.x = static_cast<int>(mOwner->GetPos().x);
		drawRect.y = static_cast<int>(mOwner->GetPos().y);
		// Source texture the width/height 
		srcRect.w = static_cast<int>(mOwner->GetSize().x );
		srcRect.h = static_cast<int>(mOwner->GetSize().y );
		srcRect.x = 0;
		srcRect.y = 0;
		
		// Draw (have to convert angle from radians to degrees, and clockwise to counter)
		SDL_RenderCopyEx(
			renderer,				//the SDL_Renderer we always use for rendering
			mTexture,							//the SDL_Texture we want to render
			&srcRect,							//which part of the SDL_Texture to render.null for everything.
			&drawRect,									// where to render it. Used exactly like in SDL_RenderFillRect)
			-glm::radians(mOwner->GetRotation()), //angle of rotation
			nullptr,							//the center of rotation
			spriteFlip );						// flipping of texture ( vertical, horizontal, no flip )
	}

}
//------------------------------------------------------
//テキスチャーを設置する
//------------------------------------------------------
void SpriteComponent::SetTexture(SDL_Texture* texture)
{
	//呼ばれたクラスのテキスチャーをセットする
	mTexture = texture;
	// Set width/height
	SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}