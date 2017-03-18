#pragma once

#include "Globals.h"

class Level
{
public:
	Level(void);
	~Level(void);
	void Load(SDL_Renderer &ptrRender);
	void Draw(void);
	void Unload(void);
	bool isLoaded(void);
private: 
	SDL_Renderer *ptrRender;
	SDL_Texture *Background;
	SDL_Texture *SpriteSheet;

	bool Loaded;
};