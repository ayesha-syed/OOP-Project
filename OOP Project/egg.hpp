
#include <SDL.h>
#include "otherItems.hpp"

// child class Egg inherited from parent class: Others
class Egg : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {296, 30, 31, 40};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of egg will go here
    Egg();
    Egg(int x, int y);
};
