#include <SDL.h>
#include "otherItems.hpp"

// child class Chips inherited from parent class: Others
class Chip : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {292, 109, 42, 57};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of chips are below
    Chip();
    Chip(int x, int y);
};
