#include <SDL.h>
#pragma once
class vegetable
{ // super class vegetable all the others will from this class
protected:
    SDL_Rect srcRect, moverRect; // the attributes are set to protected.
public:
    vegetable();
    vegetable(SDL_Rect src, SDL_Rect mr);
    void draw(SDL_Renderer *, SDL_Texture *assets);
};
