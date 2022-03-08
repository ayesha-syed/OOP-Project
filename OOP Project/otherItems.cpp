#include "otherItems.hpp"

//constructors
Others::Others(SDL_Rect src, SDL_Rect mr) : srcRect(src), moverRect(mr) {} // construtors
Others::Others() {}
//draw function
void Others::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{ // draw fucntion
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
