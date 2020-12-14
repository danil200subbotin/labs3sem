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
    PATH = levelsTable[level].PATH;
    return i;
}

int TowerSimple::attack() {
    int koaff = 0;
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
                koaff = lowest->getDamageKoaf();
                lowest->damage(getDamage() + koaff, 255, 0, 0);
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
        {15,700,4, 50, 2, "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerS2.png"},
        {20, 700, 4, 50, 2, "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerS3.png"}
} ;