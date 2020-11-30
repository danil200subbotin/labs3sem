//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_CASTLE_H
#define TOWERDEFENCE_CASTLE_H


#include "Square.h"
#include <stdexcept>

class Castle: public Square {
private:
    int hitPoints;

    int maxHP;

    int amountGold;

public:
    Castle(int, int, int, int, int);

    int addGold(int);

    int damage(int);

};

#endif //TOWERDEFENCE_CASTLE_H
