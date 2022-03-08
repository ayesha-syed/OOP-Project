#include "coke.hpp"
// Coke implementation will go here.

void Coke::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of coke.
}

Coke::Coke()
{
    Others({{306, 186, 20, 63}, {0, 0, 50, 60}});
}

Coke::Coke(int x, int y)
{
    srcRect = {306, 186, 20, 63};
    moverRect = {x, y, 30, 40}; // it will display Coke on x, y location, the size of coke is 30 width, 40 height
}
//return current position
SDL_Rect Coke ::find_pos()
{
    return moverRect;
}
//falling function
void Coke::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
