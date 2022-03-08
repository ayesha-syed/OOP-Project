#include <SDL.h>
#include "otherItems.hpp"

// child class Bread inherited from parent class: Others
class Cheese : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {147, 27, 45, 35};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of cheese are below
    Cheese();
    Cheese(int x, int y);
};
