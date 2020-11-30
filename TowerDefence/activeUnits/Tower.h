//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWER_H
#define TOWERDEFENCE_TOWER_H

#include <list>
#include "../squares/Square.h"
#include "../squares/Road.h"
#include <cmath>


class Tower: public Square{
protected:
    int level;


    std::list<Road*> boomArea;

public:
    virtual int attack() = 0;

    virtual int getRange() = 0;

    virtual int getDamage() = 0;

    virtual int levelUp() = 0;

    int Render();

    int makeBoomArea(std::list <Road*> :: iterator it_f, std::list <Road*> :: iterator it_end);
};



#endif //TOWERDEFENCE_TOWER_H
