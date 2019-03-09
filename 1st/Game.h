/**
 * @file Game.h
 * @brief ���̃N���X�̓��C���E�B���h�E�Y�쐬��I�u�W�F�N�g�̍쐬�Ȃǂ��s��
 * @author Kan
 * @date 2019/3/2
 */
#pragma once
#include <SDL.h>
#include<iostream>
#include<vector>
#include<unordered_map>

class Game
{
public:
	//Constructor
	Game();
	//Initialize 
	bool Initialize();
	//Game Loop
	void GameLoop();
	//Shut down windows
	void ShutDown();
	//Add Actor Function
	void AddActor(class Actor* actor);
	//Remove Actor Function
	void RemoveActor(class Actor* actor);
	//Add sprite Function
	void AddSprite(class SpriteComponent* spr);
	//Remove Sprite Function
	void RemoveSprite(class SpriteComponent* spr);
	//�e�L�X�`���[���擾
	SDL_Texture* GetTexture(const std::string& filename);
private:
	//�C���v�b�g����
	void ProcessInput();
	//�Q�[���X�V����
	void UpdateGame();
	//�A�E�g�v�b�g����
	void GenerateOutput();
	//�f�[�^����
	void LoadData();
	void UnloadData();
	//Texture 
	std::unordered_map <std::string, SDL_Texture*> Texture;
	//�x�N�g���^�ŃN���X�̂Ƀ����o�[��ǉ�
	std::vector<class Actor*> actor;
	std::vector<class Actor*> pendingActor;
	std::vector<class SpriteComponent*> sprites;
	//Use this function to create window
	//���̊֐����g���ăE�B���h�E�𐶐�
	SDL_Window* m_Window;
	//A structure that contain a rendering state
	SDL_Renderer* m_Renderer;
	//Time since start
	Uint32 m_ticksCount;
	//Check if game is running
	bool m_IsRunning;
	//Check if Actor is updating
	bool m_UpdatingActor;
	//Class player
	class Slime* slime;
};