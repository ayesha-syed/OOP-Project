#include "apple.hpp"
// Apple implementation will go here.

void Apple::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of Apple here.
}

Apple::Apple()
{
    Fruit({72, 119, 33, 35}, {0, 0, 50, 60}); // default constructor
}

// it will display apple on x, y location, the size of apple is 30 width, 40 height
Apple::Apple(int x, int y)
{
    srcRect = {72, 119, 33, 35};
    moverRect = {x, y, 30, 40};
}

// returns current position of apple
SDL_Rect Apple ::find_pos()
{
    return moverRect;
}
//function of falling Apple
void Apple::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
