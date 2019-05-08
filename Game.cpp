#include <SDL_image.h>
#include <algorithm>
#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "BGSpriteComponent.h"
#include "Slime.h"
#include "Map.h"
//------------------------------------------------------
//コンパイルまえに初期化する
//------------------------------------------------------
Game::Game()
	:m_Window(nullptr),
	m_Renderer(nullptr),
	m_IsRunning(true),
	m_UpdatingActor(false)
{
}
//------------------------------------------------------
//初期化する処理
//------------------------------------------------------
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
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
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
//------------------------------------------------------
//毎フレーム更新する処理
//------------------------------------------------------
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
//------------------------------------------------------
//インプットの処理「キーボードなど」
//------------------------------------------------------
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
	mSlime->ProcessKeyboard(state);
}
//------------------------------------------------------
//時刻を更新する処理
//------------------------------------------------------
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
	
	//Update all actor
	m_UpdatingActor = true;
	for (auto actors : m_actor)
	{
		//Update time from game to actor
		actors->Update(deltaTime);
	}
	//After updated actor return it to false
	m_UpdatingActor = false;
	//Move pending actor to m_actor(si=o we can delete after)
	for (auto pendings : m_pendingActor)
	{
		m_actor.emplace_back(pendings);
	}
	m_pendingActor.clear();

	std::vector<Actor*>deadActors;
	//if actors are dead put them in deadActor 
	for (auto actors : m_actor)
	{
		if (actors->GetState() == Actor::Dead)
		{
			deadActors.emplace_back(actors);
		}
	}
	for (auto deadactor : deadActors)
	{
		delete deadactor;
	}
	
}
//------------------------------------------------------
//出力を生成する
//------------------------------------------------------
void Game::GenerateOutput()
{
	//windowの色
	SDL_SetRenderDrawColor(m_Renderer, 
		0, //R
		0, //G
		0, //B
		255); //Alpha
	//Clear the current rendering target with color
	SDL_RenderClear(m_Renderer);
	// Draw all sprite components
	for (auto sprite : m_sprites)
	{
		sprite->Draw(m_Renderer);
	}
	//Update the screen
	SDL_RenderPresent(m_Renderer);
}
//------------------------------------------------------
//ifstream インプットファイルをロードする
//------------------------------------------------------
void Game::LoadData()
{
	// Create player
	mSlime = new Slime(this);
	mSlime->SetSize(glm::vec2(32.0f, 32.0f));
	mSlime->SetFrame(8);
	mSlime->SetScale(1.5f);
	mSlime->SetPos(glm::vec2( 0.0f, WINDOW_HEIGHT - mSlime->GetSize().y-42));
	
	// Create actor for the background (this doesn't need a subclass)
	Actor* temp = new Actor(this);
	temp->SetPos(glm::vec2(0.0f, 0.0f));
	// Create the "far back" background
	BGSprite* bg = new BGSprite(temp);
	bg->SetScreenSize(glm::vec2(WINDOW_WIDTH,WINDOW_HEIGHT));
	std::vector<SDL_Texture*> bgtexs = {
		GetTexture("Assets/background/plx-1.png")
	};
	bg->SetBGTextures(bgtexs);
	//Create the closer background
	bg = new BGSprite(temp);
	bg->SetScreenSize(glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	bgtexs = {
		GetTexture("Assets/background/plx-2.png"),
		GetTexture("Assets/background/plx-2.png")
	};
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(-100.0f);
	//Create 3rd layer
	bg = new BGSprite(temp);
	bg->SetScreenSize(glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	bgtexs = {
		GetTexture("Assets/background/plx-3.png"),
		GetTexture("Assets/background/plx-3.png")
	};
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(-100.0f);
	//4th layer
	//Create 3rd layer
	bg = new BGSprite(temp);
	bg->SetScreenSize(glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	bgtexs = {
		GetTexture("Assets/background/plx-4.png"),
		GetTexture("Assets/background/plx-4.png")
	};
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(-100.0f);
	// 5th layer
	bg = new BGSprite(temp, 50);
	bg->SetScreenSize(glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT));
	bgtexs = {
		GetTexture("Assets/background/plx-5.png"),
		GetTexture("Assets/background/plx-5.png")
	};
	bg->SetBGTextures(bgtexs);
	bg->SetScrollSpeed(-100.0f);
	
	
	
}
//------------------------------------------------------
//Clear loaded files 
//------------------------------------------------------
void Game::UnloadData()
{
	// Delete actors
	// Because ~Actor calls RemoveActor, have to use a different style loop
	while (!m_actor.empty())
	{
		delete m_actor.back();
	}

	// Destroy textures
	for (auto i : Texture)
	{
		SDL_DestroyTexture(i.second);
	}
	Texture.clear();
}
//------------------------------------------------------
//テキスチャーを取得
//------------------------------------------------------
SDL_Texture* Game::GetTexture(const std::string& filename)
{
	SDL_Texture* tex = nullptr;
	// Is the texture already in the map?
	auto iter = Texture.find(filename);
	if (iter != Texture.end())
	{
		tex = iter->second;
	}
	else
	{
		// Load from file
		SDL_Surface* surf = IMG_Load(filename.c_str());
		if (!surf)
		{
			SDL_Log("Failed to load texture file %s", filename.c_str());
			return nullptr;
		}

		// Create texture from surface
		tex = SDL_CreateTextureFromSurface(m_Renderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", filename.c_str());
			return nullptr;
		}

		Texture.emplace(filename.c_str(), tex);
	}
	return tex;
}
//------------------------------------------------------
//Shut down windows
//Deallocate memory. Work like ~Game()
//------------------------------------------------------
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
//------------------------------------------------------
//Add Actor
//------------------------------------------------------
void Game::AddActor(class Actor* actor)
{
	// If we're updating actors, need to add to pending
	if (m_UpdatingActor)
	{
		m_pendingActor.emplace_back(actor);
	}
	else
	{
		m_actor.emplace_back(actor);
	}
}
//------------------------------------------------------
//Clear Actor
//------------------------------------------------------
void Game::RemoveActor(class Actor* actor)
{
	// Is it in pending actors?
	auto iter = std::find(m_pendingActor.begin(), m_pendingActor.end(), actor);
	if (iter != m_pendingActor.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, m_pendingActor.end() - 1);
		m_pendingActor.pop_back();
	}

	// Is it in actors?
	iter = std::find(m_actor.begin(), m_actor.end(), actor);
	if (iter != m_actor.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, m_actor.end() - 1);
		//Delete last element 
		m_actor.pop_back();
	}
}
//------------------------------------------------------
//Add sprite Function
//------------------------------------------------------
void Game::AddSprite(class SpriteComponent* spr)
{
	// Find the insertion point in the sorted vector
	// (The first element with a higher draw order than me)
	int myDrawOrder = spr->GetDrawOrder();
	auto iter = m_sprites.begin();
	for (;iter != m_sprites.end();++iter)
	{
		//If mydraworder is less than draw order from iter 
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	m_sprites.insert(iter, spr);
}
//------------------------------------------------------
//Remove Sprite Function
//------------------------------------------------------
void Game::RemoveSprite(class SpriteComponent* spr)
{
	// (We can't swap because it ruins ordering from draworder) 
	auto iter = std::find(m_sprites.begin(), m_sprites.end(), spr);
	m_sprites.erase(iter);
}
//------------------------------------------------------
//Add tile
//------------------------------------------------------
void Game::AddTile(int srcX, int srcY, int xPos, int yPos)
{

}