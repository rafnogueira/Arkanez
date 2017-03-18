
#include "Game.h"
#include "TextRender.h"

Game *game = nullptr;


int main(int arc, char *args[])
{
	std::cout << "Argumentos:" << std::endl;
	std::cout << arc << std::endl;
	std::cout << args << std::endl;

	game = new Game();

	//game->Init("Arkanez 1.0", 1024, 768, 100, 100, SDL_WINDOW_FULLSCREEN);
	game->Init("Arkanez 1.0", 1024, 768, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);


	while (game->isRunning())
	{
		game->Update();
		game->Render();
	}


	return 0;
}
