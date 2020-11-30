//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerSimple.h"


int TowerSimple::getRange() {
    return levelsTable[level].radius;
}

int TowerSimple::getDamage() {
    return levelsTable[level].damage;
}

int TowerSimple::getCost() {
    if (level < levelsTable->maxLevel)
        return levelsTable[level + 1].price;
    return -1;
}

int TowerSimple::levelUp(int castleGold) {
    if ((castleGold < getCost() || (level = levelsTable[0].maxLevel))) {
        return 1;
    }
    ++level;
    return 0;
}

int TowerSimple::attack() {
    std::list <Road*> :: iterator it_r;
    it_r = boomArea.begin();
    Enemy* lowest = (*it_r)->getLowHP();
    for (; it_r != boomArea.end(); ++it_r) {
        if ((*it_r)->getLowHP()->getHP() < lowest->getHP())
            lowest = (*it_r)->getLowHP();
    }
    lowest->damage(getDamage());
}