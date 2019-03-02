#include "Game.h"
//コンパイルまえに初期化する
Game::Game()
:window(nullptr),
renderer(nullptr),
IsRunning(false),
updatingActor(false)
{
}
//初期化する処理
bool Game::Initialize()
{
	//初期化成功するかどうかを確認する
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
	//ウィンドウがうまく動いているかどうかを確認する
	if (!window)
	{
		SDL_Log("Failed to create window : %s", SDL_GetError());
	}
	//ウィンドウの2Dレンダリングコンテキストを生成する
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//2Dレンダリングコンテキストを確認する
	if (!renderer)
	{
		SDL_Log("Failed to create renderer : %s", SDL_GetError());
	}
	if()
}