#include <SDL.h>
#pragma once
class Fruit
{ // super class Fruit all the fruit classes will inherit from this class
protected:
    SDL_Rect srcRect, moverRect; // the attributes are set to protected.
public:
    Fruit();
    Fruit(SDL_Rect src, SDL_Rect mr);
    void draw(SDL_Renderer *, SDL_Texture *assets);
};
