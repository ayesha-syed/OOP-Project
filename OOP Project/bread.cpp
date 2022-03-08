#include "bread.hpp"
// Bread implementation will go here.

void Bread::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of bread here.
}

Bread::Bread()
{
    Others({{76, 30, 46, 29}, {0, 0, 50, 60}});
}

Bread::Bread(int x, int y)
{
    srcRect = {76, 30, 46, 29};
    moverRect = {x, y, 30, 40}; // it will display Bread on x, y location, the size of bread is 30 width, 40 height
}
//returns current position
SDL_Rect Bread ::find_pos()
{
    return moverRect;
}
//falling function
void Bread::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
