//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerMagic.h"

TowerMagic::TowerMagic(int x, int y, std::list <Road*> *roadList): TowerSimple(x, y, roadList) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerM.png";
    startRaload();
}

 /* int TowerMagic::attack() {
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
                lowest->addEffect(*effectsTable[level], 0);
            }
        }
    }
    return 0;
}

  */

const struct Effect TowerMagic::effectsTable[] = {
        {1, 1, 1, 1000},
        {2,2,2, 2000},
        {3, 3, 3, 3000}
} ;