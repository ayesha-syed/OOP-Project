
#include <SDL.h>
#include "vegetables.hpp"
// child class EggPlant inherited from parent class: vegetable
class EggPlant : public vegetable
{
    SDL_Rect srcRect, moverRect;
    SDL_Rect srcRect_0 = {97, 281, 35, 40};

public:
    bool check = false;
    void drop(SDL_Renderer *, SDL_Texture *assets);
    void draw(SDL_Renderer *, SDL_Texture *assets);
    SDL_Rect find_pos();
    // the overloaded constructors of eggPlant will go here
    EggPlant();
    EggPlant(int x, int y);
};
