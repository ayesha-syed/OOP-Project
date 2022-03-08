
#include <SDL.h>

class Corona
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {271, 398, 43, 43};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of corona will go here
    Corona();
    Corona(int x, int y);
};
