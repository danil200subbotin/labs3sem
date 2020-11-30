//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERMAGIC_H
#define TOWERDEFENCE_TOWERMAGIC_H


#include "TowerSimple.h"

struct Effect {
    int DPS;

    int slow;

    int illness;

    int time;
};

class TowerMagic: public TowerSimple {
private:
    static const Effect effectsTable[3];
public:
    int attack();

    int levelUp();

};


#endif //TOWERDEFENCE_TOWERMAGIC_H
