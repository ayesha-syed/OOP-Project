#include <SDL.h>
#pragma once
class Others
{ // super class Fruit all the fruit classes will inherit from this class
protected:
    SDL_Rect srcRect, moverRect; // the attributes are set to protected.
public:
    Others();
    Others(SDL_Rect src, SDL_Rect mr);
    void draw(SDL_Renderer *, SDL_Texture *assets);
};
