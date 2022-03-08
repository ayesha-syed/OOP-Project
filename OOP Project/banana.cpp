#include "banana.hpp"
// Banana implementation will go here.

void Banana::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of banana here.
}

Banana::Banana()
{
    Fruit({72, 119, 33, 35}, {0, 0, 50, 60}); // default constructor
}

Banana::Banana(int x, int y)
{
    srcRect = {141, 133, 41, 23};
    moverRect = {x, y, 30, 40}; // it will display Banana on x, y location, the size of juice is 50 width, 60 height
}

//return current position of Banana
SDL_Rect Banana ::find_pos()
{
    return moverRect;
}
//function of falling banana
void Banana::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
