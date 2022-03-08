
#include "egg.hpp"
// Egg implementation will go here.

void Egg::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of egg.
}

Egg::Egg()
{
    Others({{296, 30, 31, 40}, {0, 0, 50, 60}});
}

Egg::Egg(int x, int y)
{
    srcRect = {296, 30, 31, 40};
    moverRect = {x, y, 30, 40}; // it will display egg on x, y location, the size of egg is 30 width, 40 height
}
//returns current position
SDL_Rect Egg ::find_pos()
{
    return moverRect;
}
//falling function
void Egg::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
