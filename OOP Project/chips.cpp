#include "chips.hpp"
// Chips implementation will go here.

void Chip::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of chips here.
}

Chip::Chip()
{
    Others({{292, 109, 42, 57}, {0, 0, 50, 60}});
}

Chip::Chip(int x, int y)
{
    srcRect = {292, 109, 42, 57};
    moverRect = {x, y, 30, 40}; // it will display chips on x, y location, the size of chips is 30 width, 40 height
}

//return current location
SDL_Rect Chip ::find_pos()
{
    return moverRect;
}
//falling function
void Chip::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
