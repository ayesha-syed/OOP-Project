#include <SDL.h>
#include "cart.hpp"
#include "heart.hpp"
#include "juice.hpp"
#include "coke.hpp"
#include "bread.hpp"
#include "cheese.hpp"
#include "chocolate.hpp"
#include "banana.hpp"
#include "apple.hpp"
#include "egg.hpp"
#include "carrot.hpp"
#include "chips.hpp"
#include "potato.hpp"
#include "orange.hpp"
#include "eggPlant.hpp"
#include "danger.hpp"
#include "bonus.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "music.hpp"
#pragma once
using namespace std;

/** \brief 
 * cart object created
 * lists and pointers for all items here
 */
class SupplyCollector
{

    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    Music mouseclick;
    Cart cart;
    Heart heart;

    list<Juice *> Jlist; // all the other objects are implented through list and pointers

    list<Cheese *> CHlist;

    list<Coke *> CKlist;

    list<Bread *> Blist;

    list<Chocolate *> CHOClist;

    list<Apple *> Aplist;

    list<Banana *> Banlist;

    list<Carrot *> Carlist;

    list<Chip *> Chilist;

    list<Egg *> Elist;

    list<EggPlant *> EPlist;

    list<Orange *> Olist;

    list<Potato *> Plist;

    list<Corona *> Corlist;

    list<PickHeart *> Piclist;

public:
    SupplyCollector(SDL_Renderer *, SDL_Texture *);
    void drawObjects();
    void moveCart(string direction);
    void createObject();
    enum States
    {
        RUNNING,
        LOST,
        WON
    };
    int Score = 0;
    int Life = 5;
};
