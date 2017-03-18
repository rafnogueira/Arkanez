
#ifndef TEXTRENDER_H
#define TEXTRENDER_H

#include "Globals.h"


class TextRender
{
public:
    TextRender();
    ~TextRender();

    void LoadFont(std::string src, int size);
    void DrawText(SDL_Renderer *prtRender,std::string  &msg,int x,int y);

private:
    SDL_Color Color; //cor do texto a ser desenhado
    SDL_Rect  dst;

    TTF_Font *font;
    SDL_Surface *message;
    SDL_Texture *txtTexture;

};

#endif // TEXTRENDER_H
