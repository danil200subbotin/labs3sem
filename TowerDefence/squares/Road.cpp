//
// Created by Данил Морозов on 30/11/2020.
//

#include "Road.h"


Road::Road(int x, int y): Square(x, y) {
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/road3.png";
};

int Road::setNext(Road * nextR) {
    next = nextR;
    return 0;
}

Road* Road::getNext() {
    return next;
}

Enemy* Road::getLowHP() {
    if (enemies.empty())
        return nullptr;
    std::list <Enemy*> :: iterator it_e;
    Enemy* lowest = *enemies.begin();
    it_e = enemies.begin();
    while (it_e != enemies.end()) {
        if ((*it_e)->getHP() < lowest->getHP())
            lowest = (*it_e);
        ++it_e;
    }
    return lowest;
}

Enemy* Road::getFirst() {
    if (enemies.empty())
        return nullptr;
    return enemies.front();
}

int Road::addHere(Enemy* enemy) {
    enemies.push_back(enemy);
    return 0;
}


int Road::deleteHere(Enemy* enemy) {
    std::list <Enemy*> :: iterator it_e;
    for (it_e = enemies.begin(); it_e != enemies.end(); ++it_e) {
            if ((*it_e) == enemy) {
                it_e = enemies.erase(it_e);
            }
        }
}