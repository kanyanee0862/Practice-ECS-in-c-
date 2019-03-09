#include <SDL_image.h>
#include "Game.h"
//�R���p�C���܂��ɏ���������
Game::Game()
	:m_Window(nullptr),
	m_Renderer(nullptr),
	m_IsRunning(true),
	m_UpdatingActor(false)
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
	//SDL�̊֐��A�E�B���h�E���쐬
	m_Window = SDL_CreateWindow("Slime Adventure??",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		600,
		480,
		SDL_WINDOW_SHOWN);
	//�E�B���h�E�����܂������Ă��邩�ǂ������m�F����
	if(!m_Window)
	{
		SDL_Log("Failed to create window : %s", SDL_GetError());
		return false;
	}
	//�E�B���h�E��2D�����_�����O�R���e�L�X�g�𐶐�����
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	//2D�����_�����O�R���e�L�X�g���m�F����
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
		//�C���v�b�g����
		ProcessInput();
		//�Q�[���X�V����
		UpdateGame();
		//�A�E�g�v�b�g����
		GenerateOutput();
	}
}
//�C���v�b�g�̏����u�L�[�{�[�h�Ȃǁv
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
	//�L�[�{�[�h�̏�Ԃ𓾂�
	const uint8_t* state = SDL_GetKeyboardState(NULL);
	//ESC�������ꂽ�����
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_IsRunning = false;
	}
}
void Game::UpdateGame()
{
	//���Ԃ��J�n
	//16�~���b�o�߂�����n�܂�
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksCount + 16));

	float deltaTime = (SDL_GetTicks() - m_ticksCount) / 1000.0f;
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	m_ticksCount = SDL_GetTicks();
}
//�o�͂𐶐�����
void Game::GenerateOutput()
{
	//windows�̐F
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
//ifstream �C���v�b�g�t�@�C�������[�h����
void Game::LoadData()
{

}
//Clear loaded files 
void Game::UnloadData()
{

}
//�e�L�X�`���[���擾
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