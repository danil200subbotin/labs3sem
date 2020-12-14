//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerMagic.h"

TowerMagic::TowerMagic(int x, int y, std::list <Road*> *roadList): TowerSimple(x, y, roadList) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerM.png";
    startRaload();
}

int TowerMagic::attack() {
    std::list <Road*> :: iterator it_r;
    std::list <Enemy*> :: iterator it_e;
    bool fire = false;
    it_r = boomArea.begin();
    if (!boomArea.empty()) {
        Enemy *lowest = (*it_r)->getLowHP();
        for (it_r = boomArea.begin(); it_r != boomArea.end(); ++it_r) {
            for (it_e = (*it_r)->getIter(); it_e != (*it_r)->getLIter(); ++it_e) {
                if (*it_e != nullptr) {
                    if (!(*it_e)->isMagicEffect() && !fire) {
                        (*it_e)->addEffect(effectsTable[level], 0, 0, 0, 255);
                        fire = true;
                    }
                }
            }
        }
    }
    return 0;
}


const struct Effect TowerMagic::effectsTable[] = {
        {1, 7, 40},
        {2,2, 50},
        {3, 3, 70}
} ;