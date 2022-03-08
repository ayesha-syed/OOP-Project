
#include "chocolate.hpp"
// Chocolate implementation will go here.

void Chocolate::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of chocolate.
}

Chocolate::Chocolate()
{
    Others({{218, 21, 43, 48}, {0, 0, 50, 60}});
}

Chocolate::Chocolate(int x, int y)
{
    srcRect = {218, 21, 43, 48};
    moverRect = {x, y, 30, 40}; // it will display chocolate on x, y location, the size of chocolate is 30 width, 40 height
}
//return current location
SDL_Rect Chocolate ::find_pos()
{
    return moverRect;
}
//falling function
void Chocolate::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
