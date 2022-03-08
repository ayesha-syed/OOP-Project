#include <SDL.h>
#include "otherItems.hpp"

// child class Juice inherited from parent class: Others
class Juice : public Others
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {74, 195, 21, 47};
    SDL_Rect srcRect_1 = {144, 190, 21, 54};
    SDL_Rect srcRect_2 = {224, 191, 19, 54};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of juice are below
    Juice();
    Juice(int x, int y);
};
