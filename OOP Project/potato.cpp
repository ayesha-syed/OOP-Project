#include "potato.hpp"
// Potato implementation will go here.

void Potato::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of potato.
}

Potato::Potato()
{
    vegetable({272, 294, 43, 30}, {0, 0, 50, 60});
}

Potato::Potato(int x, int y)
{
    srcRect = {272, 294, 43, 30};
    moverRect = {x, y, 30, 40}; // it will display potato on x, y location, the size of is 30 width, 40 height
}
//return current position
SDL_Rect Potato ::find_pos()
{
    return moverRect;
}
//falling function
void Potato::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
