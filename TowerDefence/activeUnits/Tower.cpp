//
// Created by Данил Морозов on 30/11/2020.
//

#include "Tower.h"

int Tower::makeBoomArea(std::list <Road*> *roadList) {
    auto it_begin = roadList->begin();
    for (; it_begin != roadList->end(); ++it_begin) {
        if (( sqrt( pow((*it_begin)->getX() - x, 2) + pow((*it_begin)->getY() - y, 2)) <= getRange())) {
             boomArea.push_back((*it_begin));              //добавляю дороги внутри радиуса действия
        }
    }
    return 0;
}

Tower::Tower(int x, int y) : Square(x, y), level(0) {}









