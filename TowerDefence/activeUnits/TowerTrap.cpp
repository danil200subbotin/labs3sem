//
// Created by Данил Морозов on 30/11/2020.
//

#include "TowerTrap.h"


int TowerTrap::attack() {
    std::list <Road*> :: iterator it_r;
    std::list <Enemy*> :: iterator it_e;
    it_r = boomArea.begin();
    Road* nearest = nullptr;
    Enemy* lowest = (*it_r)->getFirst();
    for (; it_r != boomArea.end(); ++it_r) {
        if (((*it_r)->getX() == x) &&((*it_r)->getY() == y))
            nearest = (*it_r);
    }
    if (boomed) {
        std::string newPATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/road4.png";
        PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerT2.png";
        nearest->setPATH(newPATH);
    } else {
        lowest = nearest->getFirst();
        //  std::cout << "("<<lowest->getX()/50<<"; " << lowest->getY()/50 << ") (" << x << "; " << y << ")" << std::endl;
        if ((lowest != nullptr) && (abs(lowest->getX() / 50 - x) <= 1) && (abs(lowest->getY() / 50 - y) <= 1)) {
            for (it_r = boomArea.begin(); it_r != boomArea.end(); ++it_r) {
                for (it_e = (*it_r)->getIter(); it_e != (*it_r)->getLIter(); ++it_e) {
                    if (*it_e != nullptr) {
                        (*it_e)->damage(100, 255, 255, 0);
                    }
                }
            }
            boomed = true;
        }
    }
    return 0;
}

TowerTrap::TowerTrap(int x, int y, std::list <Road*> *roadList): TowerSimple(x, y, roadList), damage(50) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/towerT.png";
    boomed = false;
}

int TowerTrap::getRange() {
    return 1;
}


