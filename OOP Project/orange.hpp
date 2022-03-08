
#include <SDL.h>
#include "fruits.hpp"

// child class Orange inherited from parent class: Fruit
class Orange : public Fruit
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {218, 123, 40, 40};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of orange will go here
    Orange();
    Orange(int x, int y);
};
