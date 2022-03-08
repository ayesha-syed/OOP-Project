#include "cart.hpp"

void Cart::draw(SDL_Renderer *gRenderer, SDL_Texture *assets)
{
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}

Cart::Cart()
{
    srcRect = {399, 119, 188, 145};

    moverRect = {0, 500, 200, 100};
}

Cart::Cart(int x, int y)
{
    srcRect = {399, 119, 188, 145};

    moverRect = {0, 500, 200, 100};
}
SDL_Rect Cart ::find_pos()
{
    return moverRect;
}

void Cart::move(string direction)
{
    if (direction == "right" && moverRect.x < 800)
    {
        moverRect.x += 50;
    }
    if (direction == "left" && moverRect.x > 0)
    {
        moverRect.x -= 50;
    }
}
