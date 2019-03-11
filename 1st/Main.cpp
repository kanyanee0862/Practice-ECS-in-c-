#include"SDL.h"
#include<iostream>
#include "Game.h"
int main(int argc, char* argv[])// argc = argument count, argv = argument  
{
	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.GameLoop();
	}
	game.ShutDown();
	return 0;
}