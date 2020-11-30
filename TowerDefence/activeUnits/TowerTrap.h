//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERTRAP_H
#define TOWERDEFENCE_TOWERTRAP_H


#include "TowerSimple.h"
#include "TowerMagic.h"

class TowerTrap: public Tower {
private:
    static const TowerLevel levelsTable[2];

    static const Effect effectsTable[2];

public:

    int attack;

    int levelUp;

};

#endif //TOWERDEFENCE_TOWERTRAP_H
