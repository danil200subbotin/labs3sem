//
// Created by Данил Морозов on 30/11/2020.
//

#include "Road.h"


Road::Road(int x, int y): Square(x, y, road) {};

int Road::setNext(Road * nextR) {
    next = nextR;
    return 0;
}

Enemy* Road::getLowHP() {
    std::list <Enemy*> :: iterator it_e;
    Enemy* lowest = enemies.front();
    it_e = enemies.begin();
    while (it_e != enemies.end()) {
        if ((*it_e)->getHP() < lowest->getHP())
            lowest = (*it_e);
    }
    return lowest;

}