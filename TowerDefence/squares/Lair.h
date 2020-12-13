//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_LAIR_H
#define TOWERDEFENCE_LAIR_H
#include <stack>
#include <list>
#include "Square.h"
#include "../activeUnits/Enemy.h"

struct enemyTime{
    int time;

    Enemy* enemy;
};


class EnemiesLair: public Square {
private:

    int quantity;

    std::list<struct enemyTime> enemies;

public:
    EnemiesLair(int, int);

    int pushEnemy (struct enemyTime& enemyTime);

    int popNext();

    int Render();

};


#endif //TOWERDEFENCE_LAIR_H
