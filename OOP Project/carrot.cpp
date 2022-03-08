#include "carrot.hpp"
// Carrot implementation will go here.

void Carrot::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of Carrot here.
}

Carrot::Carrot()
{
    vegetable({184, 282, 37, 48}, {0, 0, 50, 60});
}

Carrot::Carrot(int x, int y)
{
    srcRect = {184, 282, 37, 48};
    moverRect = {x, y, 30, 40}; // it will display Carrot on x, y location, the size of carrot is 30 width, 40 height
}

//returns current position
SDL_Rect Carrot ::find_pos()
{
    return moverRect;
}
//falling function
void Carrot::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
