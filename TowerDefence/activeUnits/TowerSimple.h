//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERSIMPLE_H
#define TOWERDEFENCE_TOWERSIMPLE_H

#include "Tower.h"


struct TowerLevel{
    int damage;

    int reload;

    int radius;

    int price;

    int maxLevel;

    std::string PATH;
};


class TowerSimple: public Tower{
private:

    float cooldown;


public:

    static const TowerLevel levelsTable[3];

    TowerSimple(int x, int y, std::list <Road*> *roadList);

    int attack() override;

    int levelUp(int amountGold) final;

    int getRange() override;

    int getDamage() override;

    int getCost();

    int getCollDown () { return cooldown; };

    void minusCoolDown (float);

    void startRaload ();
};




#endif //TOWERDEFENCE_TOWERSIMPLE_H
