#include "Game.h"
//�R���p�C���܂��ɏ���������
Game::Game()
:window(nullptr),
renderer(nullptr),
IsRunning(false),
updatingActor(false)
{
}
//���������鏈��
bool Game::Initialize()
{
	//�������������邩�ǂ������m�F����
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to Initialize SDL:%s", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow(
		"Slime Adventure??", //title
		0,		//x
		0,		//y
		600,	//w
		480,	//h
		0		//flag
	);
	//�E�B���h�E�����܂������Ă��邩�ǂ������m�F����
	if (!window)
	{
		SDL_Log("Failed to create window : %s", SDL_GetError());
	}
	//�E�B���h�E��2D�����_�����O�R���e�L�X�g�𐶐�����
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//2D�����_�����O�R���e�L�X�g���m�F����
	if (!renderer)
	{
		SDL_Log("Failed to create renderer : %s", SDL_GetError());
	}
	if()
}