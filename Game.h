#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "Menu.h"
#include "Level.h"
#include "Input.h"

class Game
{
public:
		Game();
		~Game(void);

		void Init(std::string Title, int w, int h, int posx, int posy, int FLAGS);
		bool isRunning(void);
		void Clean(void);
		void HandleEvents(SDL_Event *e,bool Press);
		void Update(void);
		void Render(void);
private:
		Menu  menu;
		Level level;
        Input input;

        SDL_Window *mWindow;
        SDL_Renderer *mRender;

        std::string Title;

        bool bRunning, bGame, bMenu;    // Variáveis principais de configuração
        int W_Height;
        int W_Width;

};
#endif // DISPLAY_H
