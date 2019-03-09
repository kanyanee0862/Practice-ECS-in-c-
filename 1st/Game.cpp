#include <SDL_image.h>
#include "Game.h"
//コンパイルまえに初期化する
Game::Game()
	:m_Window(nullptr),
	m_Renderer(nullptr),
	m_IsRunning(true),
	m_UpdatingActor(false)
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
	//SDLの関数、ウィンドウを作成
	m_Window = SDL_CreateWindow("Slime Adventure??",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		480,
		SDL_WINDOW_SHOWN);
	//ウィンドウがうまく動いているかどうかを確認する
	if(!m_Window)
	{
		SDL_Log("Failed to create window : %s", SDL_GetError());
		return false;
	}
	//ウィンドウの2Dレンダリングコンテキストを生成する
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//2Dレンダリングコンテキストを確認する
	if(!m_Renderer)
	{
		SDL_Log("Failed to create renderer : %s", SDL_GetError());
		return false;
	}
	//Initialize IMG file
	if(IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}
	
	LoadData();
	
	//Get number in milisecond since intialize
	m_ticksCount = SDL_GetTicks();
	
	return true;
}
void Game::GameLoop()
{
	while (m_IsRunning)
	{
		//インプット処理
		ProcessInput();
		//ゲーム更新処理
		UpdateGame();
		//アウトプット処理
		GenerateOutput();
	}
}
//インプットの処理「キーボードなど」
void Game::ProcessInput()
{
	//The SDL_Event structure is the core of all event handling in SDL.
	//SDL_Event is a union of all event structures used in SDL.
	//Using it is a simple matter of knowing which event type corresponds to which union member.
	SDL_Event event;

	//SDL_PollEvent() removes the next event from the event queue.
	//If there are no events on the queue it returns 0,
	//otherwise it returns 1. We use a while loop to process each event in turn.
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		}
	}
	//キーボードの状態を得る
	const uint8_t* state = SDL_GetKeyboardState(NULL);
	//ESCが押されたら閉じる
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_IsRunning = false;
	}
}
void Game::UpdateGame()
{
	//時間を開始
	//16ミリ秒経過したら始まる
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksCount + 16));

	float deltaTime = (SDL_GetTicks() - m_ticksCount) / 1000.0f;
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	m_ticksCount = SDL_GetTicks();
}
//出力を生成する
void Game::GenerateOutput()
{
	//windowsの色
	SDL_SetRenderDrawColor(m_Renderer, 
		0, //R
		0, //G
		0, //B
		255); //Alpha
	//Clear the current rendering target with color
	SDL_RenderClear(m_Renderer);
	//Update the screen
	SDL_RenderPresent(m_Renderer);
}
//ifstream インプットファイルをロードする
void Game::LoadData()
{

}
//Clear loaded files 
void Game::UnloadData()
{

}
//テキスチャーを取得
SDL_Texture* Game::GetTexture(const std::string& filename)
{
	return 0;
}
//Shut down windows
//Deallocate memory. Work like ~Game()
void Game::ShutDown()
{
	UnloadData();
	//Unload images
	IMG_Quit();
	//Destroy rendering context
	SDL_DestroyRenderer(m_Renderer);
	//Destroy window
	SDL_DestroyWindow(m_Window);
	//Clean up all intialized system in SDL
	SDL_Quit();
}
//Add Actor
void Game::AddActor(class Actor* actor)
{

}
//Clear Actor
void Game::RemoveActor(class Actor* actor)
{

}
//Add sprite Function
void Game::AddSprite(class SpriteComponent* spr)
{

}
//Remove Sprite Function
void Game::RemoveSprite(class SpriteComponent* spr)
{

}