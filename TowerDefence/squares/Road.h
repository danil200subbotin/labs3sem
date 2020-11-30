//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_ROAD_H
#define TOWERDEFENCE_ROAD_H
#include "Square.h"
#include <list>
#include "../activeUnits/Enemy.h"

class Road: public Square {
private:
    std::list<Enemy*> enemies;

    Road* next;

public:
    Road(int x, int y);

    int setNext(Road*);

    Enemy* getLowHP();
};


struct enemyTime{
    int time;

    Enemy* enemy;
};



#endif //TOWERDEFENCE_ROAD_H
