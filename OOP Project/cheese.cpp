#include "cheese.hpp"
// Cheese implementation will go here.

void Cheese::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of cheese.
}

Cheese::Cheese()
{
    Others({{147, 27, 46, 29}, {0, 0, 50, 60}});
}

Cheese::Cheese(int x, int y)
{
    srcRect = {147, 27, 46, 29};
    moverRect = {x, y, 30, 40}; // it will display Cheese on x, y location, the size of cheese is 30 width, 40 height
}
//return current location
SDL_Rect Cheese ::find_pos()
{
    return moverRect;
}
//falling function
void Cheese::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    if (moverRect.y <= 550)
    {
        srcRect = srcRect_0;
        moverRect.y = moverRect.y + 1;
    }
    if (moverRect.y > 550)
    {
        check = true; // checks if object has touched bottom of screen, if so, it is destroyed
    }

    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
