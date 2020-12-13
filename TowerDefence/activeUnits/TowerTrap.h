//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERTRAP_H
#define TOWERDEFENCE_TOWERTRAP_H


#include "structs.h"
#include "Tower.h"

class TowerTrap: public Tower {
private:
    int damage;
    int range;
    static const Effect effectsTable[2];

public:

    TowerTrap(int x, int y);

    int getRange() override;

    int getDamage() override;

    int attack() override;

    int levelUp(int amountGold) override;
};

#endif //TOWERDEFENCE_TOWERTRAP_H
