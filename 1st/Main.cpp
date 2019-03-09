#include"SDL.h"
#include<iostream>
int main(int argc, char* argv[])// argc = argument count, argv = argument  
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Quit();
	return 0;
}