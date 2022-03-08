
#include "danger.hpp"

void Corona::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of cororna.
}

//default
Corona::Corona()
{
    srcRect = {271, 398, 43, 43};
    moverRect = {0, 0, 50, 60};
}

Corona::Corona(int x, int y)
{
    srcRect = {271, 398, 43, 43};
    moverRect = {x, y, 30, 40}; // it will display corona on x, y location, the size of corona is 30 width, 40 height
}
//return current position
SDL_Rect Corona ::find_pos()
{
    return moverRect;
}
//falling function
void Corona::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    if (moverRect.y <= 550)
    {
        srcRect = srcRect_0;
        moverRect.y = moverRect.y + 1;
    }
    if (moverRect.y >= 550)
    {
        check = true; // checks if object has touched bottom of screen, if so, it is destroyed
    }

    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
