
#include "eggPlant.hpp"
// EggPlant implementation will go here.

void EggPlant::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of eggPlant.
}

EggPlant::EggPlant()
{
    vegetable({97, 281, 35, 40}, {0, 0, 50, 60});
}

EggPlant::EggPlant(int x, int y)
{
    srcRect = {97, 281, 35, 40};
    moverRect = {x, y, 30, 40}; // it will display eggPlant on x, y location, the size is 30 width, 40 height
}
//return current position
SDL_Rect EggPlant ::find_pos()
{
    return moverRect;
}
//falling function
void EggPlant::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
