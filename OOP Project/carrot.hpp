#include <SDL.h>
#include "vegetables.hpp"
// child class Carrot inherited from parent class: vegetable
class Carrot : public vegetable
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {184, 282, 37, 48};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of carrot are below
    Carrot();
    Carrot(int x, int y);
};
