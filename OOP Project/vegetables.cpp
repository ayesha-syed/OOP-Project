#include "vegetables.hpp"
//constructors
vegetable::vegetable(SDL_Rect src, SDL_Rect mr) : srcRect(src), moverRect(mr) {} // construtors
vegetable::vegetable() {}
//draw function
void vegetable::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{ // draw fucntion
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
