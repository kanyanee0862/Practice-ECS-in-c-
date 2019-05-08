#pragma once
#include<SDL.h>
#include "Component.h"
class SpriteComponent :public Component
{
public:
	//Constructor/Destructor
	//Update順位を得、少なければ少ないほど、更新が早くなる
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();
	//描画処理
	virtual void Draw(SDL_Renderer* renderer);
	//テキスチャーを設置する
	virtual void SetTexture(SDL_Texture* texture);
	//描画順位を得る
	int GetDrawOrder() const { return mDrawOrder; }
	//テキスチャーの高さ
	int GetTexHeight() const { return mTexHeight; }
	//テキスチャーの幅
	int GetTexWidth() const { return mTexWidth; }
protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
	SDL_RendererFlip spriteFlip;
};