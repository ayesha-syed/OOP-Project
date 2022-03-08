#include "fruits.hpp"

//constructors
Fruit::Fruit(SDL_Rect src, SDL_Rect mr) : srcRect(src), moverRect(mr) {} // construtors
Fruit::Fruit() {}
//draw function
void Fruit::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{ // draw function
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
