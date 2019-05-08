#pragma once
#include "SDL.h"
#include "SpriteComponent.h"
#include <string.h>
#include <vector>

class Map:public SpriteComponent
{
public:
	Map(class Actor* owner, int drawOrder = 50);
	~Map();
private:
	
};