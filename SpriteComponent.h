#pragma once
#include<SDL.h>
#include "Component.h"
class SpriteComponent :public Component
{
public:
	//Constructor/Destructor
	//Update���ʂ𓾁A���Ȃ���Ώ��Ȃ��قǁA�X�V�������Ȃ�
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();
	//�`�揈��
	virtual void Draw(SDL_Renderer* renderer);
	//�e�L�X�`���[��ݒu����
	virtual void SetTexture(SDL_Texture* texture);
	//�`�揇�ʂ𓾂�
	int GetDrawOrder() const { return mDrawOrder; }
	//�e�L�X�`���[�̍���
	int GetTexHeight() const { return mTexHeight; }
	//�e�L�X�`���[�̕�
	int GetTexWidth() const { return mTexWidth; }
protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
	SDL_RendererFlip spriteFlip;
};