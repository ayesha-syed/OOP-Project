#include "juice.hpp"
// Juice implementation will go here.

void Juice::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of juice.
}

Juice::Juice()
{
    Others({{74, 195, 21, 47}, {0, 0, 50, 60}});
}

Juice::Juice(int x, int y)
{
    srcRect = {74, 195, 21, 47};
    moverRect = {(x), y, 30, 40}; // it will display Juice on x, y location, the size of juice is 30 width, 40 height
}

SDL_Rect Juice::find_pos()
{
    return moverRect;
}
void Juice::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    int a = rand() % 3 + 0; //this will randomly generate value of a as 1, 2 or 3 and these values will be attributed accordingly to the objects.
    if (a == 0)
    {
        srcRect = srcRect_0;
        moverRect.y = moverRect.y + 3;
    }
    if (a == 1)
    {
        srcRect = srcRect_1;
        moverRect.y = moverRect.y + 1;
    }
    if (a == 2)
    {
        srcRect = srcRect_2;
        moverRect.y = moverRect.y + 1;
    }
    if (moverRect.y > 550)
    {

        check = true; // checks if object has touched bottom of screen, if so, it is destroyed
    }
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}
