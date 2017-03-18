#include "TextRender.h"


TextRender::TextRender()
{

}

TextRender::~TextRender()
{
    TTF_CloseFont(font);
}

void TextRender::LoadFont(std::string src,int size)
{
    font = TTF_OpenFont(src.c_str(), size);

    if (font != NULL)
    {
        std::cout << "Fonte carregada!" << std::endl;
    }else
    {
        std::cout << "Erro, Try to put the res folder on executable file" << std::endl;
    }

}

void TextRender::DrawText(SDL_Renderer *prtRender,std::string &msg,int x,int y)
{
    Color.r = 255;
    Color.g = 255;
    Color.b = 255;
    Color.a = 255;

    message = TTF_RenderText_Solid(font, msg.c_str(),Color);
    txtTexture = SDL_CreateTextureFromSurface(prtRender, message);

    int w, h;
    SDL_QueryTexture(txtTexture, NULL,NULL, &w, &h);

    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;

    SDL_RenderCopy(prtRender, txtTexture, NULL, &dst);
    SDL_FreeSurface(message);
    SDL_DestroyTexture(txtTexture);
}