
#include <SDL.h>

class PickHeart
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {186, 401, 40, 36};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of heart will go here
    PickHeart();
    PickHeart(int x, int y);
};
