//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_LAIR_H
#define TOWERDEFENCE_LAIR_H
#include <stack>
#include "Square.h"

class EnemiesLair: public Square {
private:

    int quantity;

    std::stack<struct enemyTime> enemies;

public:
    EnemiesLair(int, int);

    int pushEnemy (struct enemyTime& enemyTime);

    int popNext();

    int Render();

};

struct enemyTime {

};

#endif //TOWERDEFENCE_LAIR_H
