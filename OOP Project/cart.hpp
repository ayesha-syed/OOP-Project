#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;
class Cart
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {399, 119, 188, 145};

public:
    void move(string direction);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of cart are below
    Cart();
    Cart(int x, int y);
};
