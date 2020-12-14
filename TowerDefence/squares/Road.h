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
    std::list<class Enemy*> enemies;

    Road* next;

public:
    Road(int x, int y);

    int setNext(Road*);

    Road* getNext();

    Enemy* getLowHP();

    Enemy* getFirst();

    int addHere(Enemy*);

    std::list<Enemy*>::iterator getIter() { return enemies.begin(); };

    std::list<Enemy*>:: iterator getLIter() { return enemies.end(); };

    int deleteHere(Enemy*);
};




#endif //TOWERDEFENCE_ROAD_H
