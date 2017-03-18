
#ifndef MENU_H
#define MENU_H


#include "Globals.h"

class Menu
{
public:
    Menu(void);
    ~Menu(void);
    void Load(SDL_Renderer &pRender);
	void Unload(void);
	bool isLoaded(void);
	void OptionUp(void);
	void OptionDown(void);
	int Select(void);
    void Draw(void); 

private:
    struct dstSprite
	{
		SDL_Rect srcRect;
		SDL_Rect dstRect;
    };

	SDL_Renderer *ptrRender;
    SDL_Texture *Background;
	SDL_Texture *SpriteSheet;
	dstSprite Sprites[4];

	bool Option01, Option02, Loaded;

};

#endif // MENU_H
