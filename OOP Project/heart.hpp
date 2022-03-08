#include <SDL.h>
#include <iostream>
#include <string>
using namespace std;
class Heart
{
    SDL_Rect moverRect = {880, 55, 30, 30};
    SDL_Rect srcRect = {186, 401, 40, 36};

public:
    void draw(SDL_Renderer *, SDL_Texture *assets);
    Heart(){};
};