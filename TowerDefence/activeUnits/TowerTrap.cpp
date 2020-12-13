//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerTrap.h"


int TowerTrap::attack() {
    std::list <Road*> :: iterator it_r;
    it_r = boomArea.begin();
    Enemy* lowest = (*it_r)->getLowHP();
    for (; it_r != boomArea.end(); ++it_r) {
        if ((*it_r)->getLowHP()->isMagicEffect() == 0)
            lowest = (*it_r)->getLowHP();
    }
    lowest->damage(getDamage());
    return 0;
}

TowerTrap::TowerTrap(int x, int y): Tower(x, y) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerT.png";
}

int TowerTrap::getDamage() { return damage; }

int TowerTrap::getRange() { return range; }

int TowerTrap::levelUp(int amountGold) {
    return 0;
}

