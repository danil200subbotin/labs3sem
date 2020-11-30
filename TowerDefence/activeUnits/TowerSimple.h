//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERSIMPLE_H
#define TOWERDEFENCE_TOWERSIMPLE_H

#include "Tower.h"


struct TowerLevel{
    int damage;

    int speed;

    int radius;

    int price;

    int maxLevel;
};


class TowerSimple: public Tower{
private:
    static const TowerLevel levelsTable[3];

public:
    int attack() override;

    int levelUp(int castleGold);

    int getRange() override;

    int getDamage() override;

    int getCost();
};


#endif //TOWERDEFENCE_TOWERSIMPLE_H
