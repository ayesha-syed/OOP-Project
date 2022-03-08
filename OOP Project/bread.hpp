#include <SDL.h>
#include "otherItems.hpp"

// child class Bread inherited from parent class: Others
class Bread : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {76, 30, 46, 29};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of bread are below
    Bread();
    Bread(int x, int y);
};
