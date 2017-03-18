#include "Menu.h"


Menu::Menu(void)
{

}
Menu::~Menu(void)
{
    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(SpriteSheet);

}

void Menu::Load(SDL_Renderer &ptrRender)
{
    Menu::ptrRender = &ptrRender;
    if (Menu::ptrRender == NULL)
    {
        std::cout << "Erro ao receber render"<< std::endl;
    }


    SDL_Surface *tmp = IMG_Load("res/background03.bmp");
    Background = SDL_CreateTextureFromSurface(&ptrRender, tmp);
    SDL_FreeSurface(tmp);

    tmp = IMG_Load("res/spritemenu.bmp");
    SpriteSheet =  SDL_CreateTextureFromSurface(&ptrRender,tmp);

    if(SpriteSheet == NULL || Background == NULL)
    {
        std::cout<<"Erro ao carregar sprites do menu"<<std::endl;
    }
	
	SDL_FreeSurface(tmp);

	Sprites[0].srcRect.x = 0;
	Sprites[0].srcRect.y = 0;
	Sprites[0].srcRect.w = 270;
	Sprites[0].srcRect.h = 42;

	Sprites[0].dstRect.w = 270;
	Sprites[0].dstRect.h = 42;
	Sprites[0].dstRect.y = 384;
	Sprites[0].dstRect.x = 377;

	//////////////////////////
	Sprites[1].srcRect.x = 0;
	Sprites[1].srcRect.y = 85;
	Sprites[1].srcRect.w = 270;
	Sprites[1].srcRect.h = 42;

	Sprites[1].dstRect.w = 270;
	Sprites[1].dstRect.h = 42;
	Sprites[1].dstRect.y = Sprites[0].dstRect.y;
	Sprites[1].dstRect.x = 377;

	//////////////////////////
	Sprites[2].srcRect.x = 0;
	Sprites[2].srcRect.y = 42;
	Sprites[2].srcRect.w = 270;
	Sprites[2].srcRect.h = 42;

	Sprites[2].dstRect.h = 42;
	Sprites[2].dstRect.w = 270;
	Sprites[2].dstRect.y = Sprites[1].dstRect.y+100;
	Sprites[2].dstRect.x = 377;
	//////////////////////////
	Sprites[3].srcRect.x = 0;
	Sprites[3].srcRect.y = 127;
	Sprites[3].srcRect.w = 270;
	Sprites[3].srcRect.h = 42;

	Sprites[3].dstRect.h = 42;
	Sprites[3].dstRect.w = 270;
	Sprites[3].dstRect.y = Sprites[2].dstRect.y;
	Sprites[3].dstRect.x = 377;
	
	Option01 = true;
	Option02 = false;
	Loaded = true;
}

void Menu::Unload(void)
{
	SDL_DestroyTexture(SpriteSheet);
	SDL_DestroyTexture(Background);
}

bool  Menu::isLoaded(void)
{
	return Loaded;
}

void Menu::OptionUp(void)
{
	Option01 = true;
	Option02 = false;
}

void Menu::OptionDown(void)
{
	Option01 = false;
	Option02 = true;
}

int Menu::Select(void)
{
	if (Option01)
	{
		return 1;
	}
	if (Option02)
	{
		return 0;
	}
}
void Menu::Draw(void)
{
	SDL_RenderCopy(ptrRender, Background, NULL, NULL);

	if (Option01)
	{
	SDL_RenderCopy(ptrRender, SpriteSheet, &Sprites[1].srcRect, &Sprites[1].dstRect);
	}
	if(!Option01)
	{
	SDL_RenderCopy(ptrRender, SpriteSheet, &Sprites[0].srcRect, &Sprites[0].dstRect);
	}
	if(Option02)
	{
	SDL_RenderCopy(ptrRender, SpriteSheet, &Sprites[3].srcRect, &Sprites[3].dstRect);
	}
	if (!Option02)
	{
		SDL_RenderCopy(ptrRender, SpriteSheet, &Sprites[2].srcRect, &Sprites[2].dstRect);
	}

}
