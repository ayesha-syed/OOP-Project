#include "bonus.hpp"

void PickHeart::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    drop(gRenderer, assets); // draws all the assets of heart.
}

PickHeart::PickHeart()
{
    srcRect = {186, 401, 40, 36};
    moverRect = {0, 0, 50, 60}; // it will display heart  on x = 30, y = 40 location, the size of Bread is 50 width, 60 height
}

PickHeart::PickHeart(int x, int y)
{
    srcRect = {186, 401, 40, 36};
    moverRect = {x, y, 30, 40}; // it will display heart on x, y location, the size of juice is 50 width, 60 height
}

//returns current position
SDL_Rect PickHeart ::find_pos()
{
    return moverRect;
}
//falling function
void PickHeart::drop(SDL_Renderer *gRenderer, SDL_Texture *assets)
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
