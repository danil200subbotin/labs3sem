//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_LANDSCAPE_H
#define TOWERDEFENCE_LANDSCAPE_H


#include "../squares/Road.h"
#include "../squares/Castle.h"
#include "../squares/Lair.h"
#include "../activeUnits/TowerSimple.h"
#include "../squares/Forest.h"
#include "../activeUnits/TowerMagic.h"
#include "../activeUnits/TowerTrap.h"
#include "../activeUnits/Enemy.h"
#include <cmath>
#include <iterator>


struct actUnits{
    std::list<TowerSimple> simpleTower;

    std::list<TowerMagic> magicTower;

    std::list<TowerTrap> trapTower;

    std::list<Forest*> forest;

    std::list<Road*> road;

    std::list<Enemy*> enemies;

};

class Landscape {
private:
    int sizeX, sizeY;

    //      std::vector<Square*> mapSlots;

    struct actUnits actUnits;

    Road* firstRoad;

    Castle* castle;

    EnemiesLair* lair;

public:
    Landscape(int, int);

    int Render();

    Square *getSquare(int, int);

    int changeSquare(int, int, Square&);

    int setTower(int, int, int);


};

#endif //TOWERDEFENCE_LANDSCAPE_H
