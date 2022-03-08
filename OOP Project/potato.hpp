
#include <SDL.h>
#include "vegetables.hpp"
// child class Potato inherited from parent class: vegetable
class Potato : public vegetable
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {272, 294, 43, 30};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of potato will go here
    Potato();
    Potato(int x, int y);
};
