#include <SDL.h>
#include "otherItems.hpp"

// child class Coke inherited from parent class: Others
class Coke : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {306, 186, 20, 63};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of coke are below
    Coke();
    Coke(int x, int y);
};
