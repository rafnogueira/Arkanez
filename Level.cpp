#include "Level.h"


Level::Level()
{

}

Level::~Level()
{
	SDL_DestroyTexture(SpriteSheet);
}

void Level::Load(SDL_Renderer &ptrRender)
{
	Level::ptrRender = &ptrRender;

	SDL_Surface *tmp = SDL_LoadBMP("res/background03.bmp");
	Background = SDL_CreateTextureFromSurface(&ptrRender,tmp);

	SDL_FreeSurface(tmp);
	
	tmp = SDL_LoadBMP("");

	Loaded = true;
}

void Level::Unload()
{
	SDL_DestroyTexture(Background);
	SDL_DestroyTexture(SpriteSheet);
}

bool Level::isLoaded(void)
{
	return Loaded;
}
void Level::Draw(void)
{
	SDL_SetRenderDrawColor(ptrRender, 255, 255, 255, 255);

	SDL_RenderCopy(ptrRender,Background,NULL,NULL);
}
