
#include <SDL.h>
#include "otherItems.hpp"

// child class Chocolate inherited from parent class: Others
class Chocolate : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {218, 21, 43, 48};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of chocolate will go here
    Chocolate();
    Chocolate(int x, int y);
};
