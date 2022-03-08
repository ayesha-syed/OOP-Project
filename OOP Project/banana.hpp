#include <SDL.h>
#include "fruits.hpp"

// child class Banana inherited from parent class: Fruit
class Banana : public Fruit
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {141, 133, 41, 23};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of banana are below
    Banana();
    Banana(int x, int y);
};
