#include <SDL.h>
#include "fruits.hpp"
// child class Apple inherited from parent class: Fruit
class Apple : public Fruit
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {72, 119, 33, 35};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of apple are below
    Apple();
    Apple(int x, int y);
};
