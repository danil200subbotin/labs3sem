//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerSimple.h"
#include <iostream>

TowerSimple::TowerSimple(int x, int y, std::list <Road*> *roadList): Tower(x, y), cooldown(float(levelsTable[0].reload)) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerS.png";
    makeBoomArea(roadList);
}


int TowerSimple::getRange() {
    return levelsTable[level].radius;
}

int TowerSimple::getDamage() {
    return levelsTable[level].damage;
}

int TowerSimple::getCost() {
    if (level <= levelsTable->maxLevel)
        return levelsTable[level].price;
    return 99999999;
}

int TowerSimple::levelUp(int castleGold) {
    if ((castleGold < getCost() || (level >= levelsTable[0].maxLevel))) {
        return 0;
    }
    int i = getCost();
    ++level;
    return i;
}

int TowerSimple::attack() {
    std::list <Road*> :: iterator it_r;
    it_r = boomArea.begin();
    if (!boomArea.empty()) {
        Enemy *lowest = (*it_r)->getLowHP();
        for (; it_r != boomArea.end(); ++it_r) {
            if ((*it_r)->getLowHP() != nullptr) {
                if (lowest == nullptr) {
                    lowest = (*it_r)->getLowHP();
                } else {
                    if (((*it_r)->getLowHP()->getHP() < lowest->getHP())) {
                        lowest = (*it_r)->getLowHP();
                    }
                }
                lowest->damage(getDamage());
            }
        }
    }
    return 0;
}


void TowerSimple::minusCoolDown (float time) {
    cooldown -= time;
}

void TowerSimple::startRaload () {
    cooldown = float(levelsTable[level].reload);
}

const struct TowerLevel TowerSimple::levelsTable[] = {
        {10, 1000, 3, 50, 2},
        {30,700,4, 50, 2},
        {50, 700, 4, 50, 2}
} ;