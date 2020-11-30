//
// Created by Данил Морозов on 30/11/2020.
//

#include "Tower.h"

int Tower::makeBoomArea(std::list <Road*> :: iterator it_begin, std::list <Road*> :: iterator it_end) {
    for (; it_begin != it_end; ++it_begin) {
        if (( sqrt( pow((*it_begin)->getX() - x, 2) + pow((*it_begin)->getY() - y, 2)) <= getRange())) {
             boomArea.push_back((*it_begin));              //добавляю дороги внутри радиуса действия
        }
    }
}





