//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_ENEMY_H
#define TOWERDEFENCE_ENEMY_H

#include "TowerMagic.h"
#include <string>

class Enemy {
private:
    int x, y;
    std::string name;

    int hitPoints;

    int maxHP;

    int speed;

    int gold;

    struct Effect effects[3];
public:
    Enemy();

    int isMagicEffect();

    int getHP();

    int addEffect (struct Effect, int effectType);

    int damage (int);

    int chekAndDeleteEffects ();
};

#endif //TOWERDEFENCE_ENEMY_H
