//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerMagic.h"



int TowerMagic::attack() {
    std::list <Road*> :: iterator it_r;
    it_r = boomArea.begin();
    Enemy* lowest = (*it_r)->getLowHP();
    for (; it_r != boomArea.end(); ++it_r) {
        if ((*it_r)->getLowHP()->isMagicEffect() == 0)
            lowest = (*it_r)->getLowHP();
    }
    lowest->damage(getDamage());
}