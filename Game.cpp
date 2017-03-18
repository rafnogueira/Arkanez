
#include "Game.h"


Game::Game(void)
{

}

void Game::Init(std::string Title, int w, int h,int posx,int posy, int FLAGS)
{
	W_Width = w;
	W_Height = h;
	Title = Title;

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	mWindow = SDL_CreateWindow(Title.c_str(), posx,posy, W_Width, W_Height, FLAGS);

	mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (mRender == NULL)
	{
		std::cout << "Erro ao criar render acelerado" << std::endl;
		mRender = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_SOFTWARE);

	}

	menu.Load(*mRender);

	bRunning = true;
	bMenu = true;
	bGame = false;

}
Game::~Game(void)
{

}

void Game::Clean()
{
	SDL_DestroyRenderer(mRender);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

bool Game::isRunning(void)
{
	return bRunning;
}


void Game::HandleEvents(SDL_Event *e, bool Press)
{
	if (e->key.keysym.sym == SDLK_ESCAPE)
	{
		bRunning = Press;
	}
	if (bMenu)
	{
		if (e->key.keysym.sym == SDLK_F2)
		{

		}
		else if (e->key.keysym.sym == SDLK_DOWN || e->key.keysym.sym == SDLK_s)
		{
			menu.OptionDown();
		}
		else if (e->key.keysym.sym == SDLK_UP || e->key.keysym.sym == SDLK_w)
		{
			menu.OptionUp();
		}
		else if (e->key.keysym.sym == SDLK_SPACE || e->key.keysym.sym == SDLK_KP_ENTER)
		{
			if (menu.Select() == 1)
			{
				bGame = true;
				bMenu = false;
				menu.Unload();
				level.Load(*mRender);
				if (level.isLoaded()){std::cout << "Level loaded with sucess" << std::endl;}
			}
			else if (menu.Select() == 0)
			{
				bRunning = false;
				menu.Unload();
			}
		}
	}
}

void Game::Update(void)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			HandleEvents(&e, true);
			break;
		case SDL_KEYUP:
			HandleEvents(&e, false);
			break;
		case SDL_QUIT:
			bRunning = false;
			break;
		}
	}

}

void Game::Render(void)
{
        SDL_RenderClear(mRender);
        SDL_SetRenderDrawColor(mRender, 0, 0, 0, 255);

        if (bMenu == true)
        {
			menu.Draw();
        }

        if (bGame == true)
        {
			level.Draw();
        }
        SDL_RenderPresent(mRender);
}
