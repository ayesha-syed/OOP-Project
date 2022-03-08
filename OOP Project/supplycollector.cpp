#include <iostream>
#include "supplycollector.hpp"
#include <stdlib.h>
#include <SDL.h>
#include "music.hpp"
using namespace std;

/** \brief function to draw items on screen
 * linked list is used
 * collision between cart and item is checked
 * item is deleted if check == true
 */
void SupplyCollector::drawObjects()
{
    heart.draw(gRenderer, assets);
    cart.draw(gRenderer, assets);

    mouseclick.LoadingSoundEffect("woosh.wav");

    for (list<Juice *>::iterator it = Jlist.begin(); it != Jlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect juicePos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Jlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&juicePos, &cartPos) == true)
        {
            delete (*it);
            Jlist.remove(*it);
            Score += 20;
            mouseclick.LoadingSoundEffect("booster.wav");
            mouseclick.PlaySoundEffect();
            mouseclick.LoadingSoundEffect("woosh.wav");
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Cheese *>::iterator it = CHlist.begin(); it != CHlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect chPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            CHlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&chPos, &cartPos) == true)
        {
            delete (*it);
            CHlist.remove(*it);
            mouseclick.PlaySoundEffect();
            Score += 5;
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Coke *>::iterator it = CKlist.begin(); it != CKlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect ckPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            CKlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&ckPos, &cartPos) == true)
        {
            delete (*it);
            CKlist.remove(*it);
            mouseclick.PlaySoundEffect();
            Score += 5;
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Bread *>::iterator it = Blist.begin(); it != Blist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect bPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Blist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&bPos, &cartPos) == true)
        {
            delete (*it);
            Blist.remove(*it);
            mouseclick.PlaySoundEffect();
            Score += 5;
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Chocolate *>::iterator it = CHOClist.begin(); it != CHOClist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect chocPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            CHOClist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&chocPos, &cartPos) == true)
        {
            delete (*it);
            CHOClist.remove(*it);
            mouseclick.PlaySoundEffect();
            Score += 5;
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Apple *>::iterator it = Aplist.begin(); it != Aplist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect apPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Aplist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&apPos, &cartPos) == true)
        {
            delete (*it);
            Aplist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Banana *>::iterator it = Banlist.begin(); it != Banlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect banPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Banlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&banPos, &cartPos) == true)
        {
            delete (*it);
            Banlist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Carrot *>::iterator it = Carlist.begin(); it != Carlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect carPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Carlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&carPos, &cartPos) == true)
        {
            delete (*it);
            Carlist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Chip *>::iterator it = Chilist.begin(); it != Chilist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect chilPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Chilist.remove(*it);
            Life -= 1;
            cout << "test chip" << endl;
        }
        else if (SDL_HasIntersection(&chilPos, &cartPos) == true)
        {
            delete (*it);
            Chilist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Egg *>::iterator it = Elist.begin(); it != Elist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect eggPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Elist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&eggPos, &cartPos) == true)
        {
            delete (*it);
            Elist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<EggPlant *>::iterator it = EPlist.begin(); it != EPlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect EPPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            EPlist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&EPPos, &cartPos) == true)
        {
            delete (*it);
            EPlist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Orange *>::iterator it = Olist.begin(); it != Olist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect OPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Olist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&OPos, &cartPos) == true)
        {
            delete (*it);
            Olist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Potato *>::iterator it = Plist.begin(); it != Plist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect potPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Plist.remove(*it);
            Life -= 1;
        }
        else if (SDL_HasIntersection(&potPos, &cartPos) == true)
        {
            delete (*it);
            Plist.remove(*it);
            Score += 5;
            mouseclick.PlaySoundEffect();
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<Corona *>::iterator it = Corlist.begin(); it != Corlist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect CorPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Corlist.remove(*it);
        }
        else if (SDL_HasIntersection(&CorPos, &cartPos) == true)
        {
            delete (*it);
            Corlist.remove(*it);
            Life -= 1;
            mouseclick.LoadingSoundEffect("corona_go.wav");
            mouseclick.PlaySoundEffect();
            mouseclick.LoadingSoundEffect("woosh.wav");
        }
        else
            (*it)->draw(gRenderer, assets);
    }

    for (list<PickHeart *>::iterator it = Piclist.begin(); it != Piclist.end(); it++)
    { // using linked list to create an object dynamically
        SDL_Rect heartPos = (*it)->find_pos();
        SDL_Rect cartPos = cart.find_pos();
        cartPos.y = cartPos.y + 30;
        if ((*it)->check == true)
        {
            delete (*it);
            Piclist.remove(*it);
        }
        else if (SDL_HasIntersection(&heartPos, &cartPos) == true)
        {
            delete (*it);
            Piclist.remove(*it);
            if (Life < 10)
                Life += 1;
            mouseclick.LoadingSoundEffect("heart.wav");
            mouseclick.PlaySoundEffect();
            mouseclick.LoadingSoundEffect("woosh.wav");
        }
        else
            (*it)->draw(gRenderer, assets);
    }
}

/** \brief function to move cart
 * it is provided a string direction as parameter
 */
void SupplyCollector::moveCart(string direction)
{
    cart.move(direction);
}

/** \brief function to create items
 * item added to linked list
 */
void SupplyCollector::createObject()
{
    int a = rand() % 3000;
    if (a == 5)
    {

        Jlist.push_back(new Juice(rand() % 960, 100));
    }
    else if (a == 10)
    {

        CHlist.push_back(new Cheese(rand() % 960, 100));
    }
    else if (a == 15)
    {

        CKlist.push_back(new Coke(rand() % 960, 100));
    }
    else if (a == 20)
    {

        Blist.push_back(new Bread(rand() % 960, 100));
    }
    else if (a == 25)
    {

        CHOClist.push_back(new Chocolate(rand() % 960, 100));
    }
    else if (a == 30)
    {

        Aplist.push_back(new Apple(rand() % 960, 100));
    }
    else if (a == 35)
    {

        Banlist.push_back(new Banana(rand() % 960, 100));
    }
    else if (a == 40)
    {

        Carlist.push_back(new Carrot(rand() % 960, 100));
    }
    else if (a == 45)
    {

        Chilist.push_back(new Chip(rand() % 960, 100));
    }
    else if (a == 50)
    {

        Elist.push_back(new Egg(rand() % 960, 100));
    }
    else if (a == 55)
    {

        EPlist.push_back(new EggPlant(rand() % 960, 100));
    }
    else if (a == 60)
    {

        Olist.push_back(new Orange(rand() % 960, 100));
    }
    else if (a == 65)
    {

        Plist.push_back(new Potato(rand() % 960, 100));
    }
    else if (a == 70)
    {

        Piclist.push_back(new PickHeart(rand() % 960, 100));
    }
    else if (a > 75 && a < 80)
    {
        Corlist.push_back(new Corona(rand() % 960, 100));
    }
    // std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}
SupplyCollector::SupplyCollector(SDL_Renderer *renderer, SDL_Texture *asst) : gRenderer(renderer), assets(asst) {}