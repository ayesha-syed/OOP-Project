
#include "orange.hpp"
// Orange implementation will go here.

void Orange::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of orange.
}

Orange::Orange()
{
    Fruit({218, 123, 40, 40}, {0, 0, 50, 60}); // default constructor
}

Orange::Orange(int x, int y)
{
    srcRect = {218, 123, 40, 40};
    moverRect = {(x + 180), y, 30, 40}; // it will display orange on x, y location, the size is 30 width, 40 height
}
//return current position
SDL_Rect Orange ::find_pos()
{
    return moverRect;
}
//falling function
void Orange::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
