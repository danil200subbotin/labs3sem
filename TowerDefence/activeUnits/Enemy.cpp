//
// Created by Данил Морозов on 30/11/2020.
//

#include "Enemy.h"


int Enemy::getHP() {
    return hitPoints;
};

int Enemy::damage(int damage) {
    hitPoints -=  damage;
    if (hitPoints <= 0)
        return 1;
    return 0;
}

int Enemy::addEffect (struct Effect newEffect, int effectType) {
    effects[effectType] = newEffect;
    return 0;
}