//
// Created by Данил Морозов on 30/11/2020.
//

#include "Landscape.h"



Landscape::Landscape(int x, int y) {
    if ((x <= 1) || (y <= 1) || (x >= 100) || (y >= 100)) {
        throw std::range_error("Пресечена попытка создания карты с неприменимыми размерами");
    }
    sizeY = y;
    sizeX = x;
    int coordinator = 0;
    int xl, yl, xc, yc; // помогают при случайном определении позиций элементов на карте (xl и yl снасала указывают на логово, а затем они будут указывать на местоположение следующего участка дороги)
    Forest* newForest = nullptr;
    for (int i = 1; i <= y; ++i) {
        for (int j = 1; j <= x; ++j) {
            //  лес
            if (std::rand() % 4 == 0) {                //тут можно регулировать шанс появления леса на карте
                newForest = new Forest(i, j, std::rand() % 30);     //случайная цена за удаление леса
                actUnits.forest.push_back(newForest);
                //   mapSlots.push_back(&newForest);
            }
        }
    }
    std::mt19937 psch;
    psch.seed(5);
    bool indicator = true;
    while (indicator) {
        xl = psch() % x + 1;           //геопозиция будущего логова
        yl = psch() % y + 1;
        xc = psch() % x + 1;           //геопозиция будущего замка
        yc = psch() % y + 1;
        if ((sqrt(abs((xl - xc) * (xl - xc)) + abs((yl - yc) * (yl - yc))) >= x) && (xl <= x - 1) && (xc <= x - 1) && (yl <= y - 1) && (yc <= y - 1))
            indicator = false;
    }
    castle = new Castle(xc, yc, 250, 300, 300);
    lair = new EnemiesLair(xl, yl);
    std::cout << "добавил логово: (" << xl << "; " << yl << ")" << std::endl;
    std::cout << "добавил замок: (" << xc << "; " << yc << ")" << std::endl;


    int amountRoadsX = abs(xc - xl) - 1, amountRoadsY = abs(yc - yl) - 1;
    int roadX, roadY;
    //    <контейнер> <его тип> :: iterator <имя итератора>;
    std::list <Forest*> :: iterator it_f;
    std::list <Road*> :: iterator it_r;
    coordinator = 0;
    if ((xc - xl) >= 0)
        ++coordinator;
    if ((yc - yl) >= 0)
        ++coordinator;
    switch (coordinator) {
        case 0:
            if (amountRoadsY > 0) {
                roadY = yl - 1;
                roadX = xl;
            } else {
                roadY = yl;
                roadX = xl - 1;
            }
            break;
        case 1:
            if (yl > 1) {
                roadY = yl - 1;
                roadX = xl;
            } else {
                if (xc > xl) {
                    roadY = yl;
                    roadX = x + 1;
                } else {
                    roadY = yl;
                    roadX = x - 1;
                }
            }
            break;
        case 2:
            if (amountRoadsY > 0) {
                roadY = yl + 1;
                roadX = xl;
            } else {
                roadY = yl;
                roadX = xl + 1;
            }
    }

    firstRoad = new Road(roadX, roadY);

    Road* prevRoad = firstRoad;
    Road* currentRoad = nullptr;
    int tester = 0;
    while (amountRoadsX + amountRoadsY > 0) {
        if (((rand() % 2 == 0) && (amountRoadsX > 0)) || ((amountRoadsY < 1) && (amountRoadsX > 0))) {
            if (xc > xl) {
                ++xl;
            } else {
                --xl;
            }
            --amountRoadsX;
        } else {
            if (amountRoadsY > 0) {
                if (yc > yl) {
                    ++yl;
                } else {
                    --yl;
                }
                --amountRoadsY;
            }
        }
        tester ++;
        std::cout<< tester << ":осталось покоординатно после выхода: (" << amountRoadsX << "; " << amountRoadsY << ")" << std::endl;
    //    newForest = actUnits.forest.front();
        it_f = actUnits.forest.begin();
        std::cout << "добавил дорогу: (" << xl << "; " << yl << ")" << std::endl;
        for (it_f = actUnits.forest.begin(); it_f != actUnits.forest.end(); ++it_f) {
            if (((*it_f)->getX() == xl) && ((*it_f)->getY() == yl)) {
                it_f = actUnits.forest.erase(it_f);                     //удаляю лес, совпавший с дорогами
            }
        }
        currentRoad = new Road(xl, yl);
        currentRoad->setNext(nullptr);
        prevRoad->setNext(currentRoad);
        actUnits.road.push_back(currentRoad);
        prevRoad = currentRoad;
    }
}

int Landscape::getCastleX() const {
    return castle->getX();
}

int Landscape::getCastleY() const {
    return castle->getY();
}


void Landscape::drawCastle(sf::RenderWindow *window, sf::Text *text) {
    text->setFillColor(sf::Color::Black);
    text->setStyle(sf::Text::Bold);

    std::stringstream out;
    if (castle->getHP() > 0) {
        out << "HP: " << castle->getHP() << " ";
    } else {
        out << "DEFEAT";
        std::string newPATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/castle3.png";
        castle->setPATH(newPATH);
    }
    std::string str = out.str();
 //   std::cout << out.str() << std::endl;
    text->setString(str);
   // std::cout <<"("<< castle->getX() * 50<<", " << castle->getY() * 50<< ")" << std::endl;
    text->setPosition(castle->getX() * 50, castle->getY() * 50 - 20);


    window->draw(*text);
    castle->draw(window);
}

void Landscape::drawLair(sf::RenderWindow *window) {
    lair->draw(window);
}

void Landscape::drawRoad(sf::RenderWindow *window) {
    Road* it_r;
    it_r = firstRoad;
    while (it_r != nullptr) {
        it_r->draw(window);
        it_r = it_r->getNext();
    }
}


void Landscape::drawForest(sf::RenderWindow *window) {
    std::list <Forest*> :: iterator it_f;
    for (it_f = actUnits.forest.begin(); it_f != actUnits.forest.end(); ++it_f) {
        (*it_f)->draw(window);
    }
}

void Landscape::drawEnemies(sf::RenderWindow *window, sf::Text *text) {
    std::list <Enemy*> :: iterator it_e;
    for (it_e = actUnits.enemies.begin(); it_e != actUnits.enemies.end(); ++it_e) {
        (*it_e)->draw(window, text);
    }
}

void Landscape::drawTowers(sf::RenderWindow *window) {
    std::list <TowerSimple*> :: iterator it_s;
    for (it_s = actUnits.simpleTower.begin(); it_s != actUnits.simpleTower.end(); ++it_s) {
        (*it_s)->draw(window);
    }
    std::list <TowerMagic*> :: iterator it_m;
    for (it_m = actUnits.magicTower.begin(); it_m != actUnits.magicTower.end(); ++it_m) {
        (*it_m)->draw(window);
    }
    std::list <TowerTrap*> :: iterator it_t;
    for (it_t = actUnits.trapTower.begin(); it_t != actUnits.trapTower.end(); ++it_t) {
        (*it_t)->draw(window);
    }

}

int Landscape::pushEnemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time) {
    Enemy* newEnemy;
    newEnemy = new Enemy(x, y, hitPoints,  maxHP, speed, gold, time);
    actUnits.enemies.push_back(newEnemy);
}


int Landscape::updateEnemies(float time) {
    std::list <Enemy*> :: iterator it_e;
    for (it_e = actUnits.enemies.begin(); it_e != actUnits.enemies.end(); ++it_e) {
        if (((*it_e)->getHP() <= 0) && (((*it_e)->getX() != 1100))) {
            (*it_e)->setX(1100);
            std::cout << "добавил денег" << (*it_e)->getMoney() << std::endl;
            castle->MONEY((*it_e)->getMoney());
            (*it_e)->setX(1100);
            (*it_e)->setY(0);
            (*it_e)->getRoad()->deleteHere((*it_e));
            it_e = actUnits.enemies.erase(it_e);
        } else {
            (*it_e)->chekAndDeleteEffects();
            if ((*it_e)->getTime() > 0) {
                (*it_e)->minusTime(time);
                if ((*it_e)->getTime() < 0) {
                    (*actUnits.road.begin())->addHere((*it_e));
                    (*it_e)->setRoad(*actUnits.road.begin());
                    (*it_e)->setX((*actUnits.road.begin())->getX() * 50 + 25);
                    (*it_e)->setY((*actUnits.road.begin())->getY() * 50 + 25);
                }
            } else {
                int direction = 0;
                if ((*it_e)->getRoad()->getNext() != nullptr) {
                    if ((*it_e)->getRoad()->getX() < (*it_e)->getRoad()->getNext()->getX())
                        direction = 1;
                    if ((*it_e)->getRoad()->getY() < (*it_e)->getRoad()->getNext()->getY())
                        direction = 2;
                    if ((*it_e)->getRoad()->getX() > (*it_e)->getRoad()->getNext()->getX())
                        direction = 3;
                    if ((*it_e)->getRoad()->getY() > (*it_e)->getRoad()->getNext()->getY())
                        direction = 4;
                    int x = (*it_e)->getX();
                    int y = (*it_e)->getY();
                    float speed = (*it_e)->getSpeed();
                 //   std::cout << "-->"<< (*it_e)->getSpeedKoaf() << std::endl;
                    speed = speed / (*it_e)->getSpeedKoaf();
                    //      std::cout << (*it_e)->getRoad()->getNext()->getX() << std::endl;
                    switch (direction) {
                        case 0:
                            break;
                        case 1:
                            (*it_e)->setX(int(speed * time) + x);
                            break;
                        case 2:
                            (*it_e)->setY(int(speed * time) + y);
                            break;
                        case 3:
                            (*it_e)->setX(x - int(speed * time));
                            break;
                        case 4:
                            (*it_e)->setY(y - int(speed * time));
                            break;
                    }
                    x = (*it_e)->getX();
                    y = (*it_e)->getY();
                    int rpx = (*it_e)->getRoad()->getX() * 50;
                    int rpy = (*it_e)->getRoad()->getY() * 50;
                    int rnx = (*it_e)->getRoad()->getNext()->getX() * 50;
                    int rny = (*it_e)->getRoad()->getNext()->getY() * 50;
                    //          std::cout << "(" << (*it_e)->getRoad() <<") -> (" <<(*it_e)->getRoad()->getNext()<< ")"<< std::endl;
                    if (sqrt((x - rpx) * (x - rpx) + (y - rpy) * (y - rpy)) >
                        sqrt((x - rnx) * (x - rnx) + (y - rny) * (y - rny))) {
                        (*it_e)->getRoad()->getNext()->addHere((*it_e));
                        (*it_e)->getRoad()->deleteHere((*it_e));
                        (*it_e)->setRoad((*it_e)->getRoad()->getNext());
                    }
                } else {
                    if ((*it_e)->getX() != 1100) {
                        castle->damage((*it_e)->getHP());
                        (*it_e)->getRoad()->deleteHere((*it_e));
                        //        castle->MONEY((*it_e)->getMoney());
                        (*it_e)->setX(1100);
                        (*it_e)->setY(0);
                    }
                }

            }
        }
    }
}


int Landscape::getGold() {
    return castle->getGold();
}

std::list <Road*>* Landscape::getRoad() {
    return &actUnits.road;
}

bool Landscape::isRoad (int x, int y) {
    std::list<Road *>::iterator it_r;
    for (it_r = actUnits.road.begin(); it_r != actUnits.road.end(); ++it_r) {
        if (((*it_r)->getX() == x) && ((*it_r)->getY() == y)) {
            return 1;
        }
    }
    return 0;
}

bool Landscape::isTowerS (int x, int  y) {
    std::list<TowerSimple*>::iterator it_r;
    for (it_r = actUnits.simpleTower.begin(); it_r != actUnits.simpleTower.end(); ++it_r) {
        if (((*it_r)->getX() == x) && ((*it_r)->getY() == y)) {
            return 1;
        }
    }
    return 0;
}

bool Landscape::isTowerM (int x, int  y) {
    std::list<TowerMagic*>::iterator it_r;
    for (it_r = actUnits.magicTower.begin(); it_r != actUnits.magicTower.end(); ++it_r) {
        if (((*it_r)->getX() == x) && ((*it_r)->getY() == y)) {
            return 1;
        }
    }
    return 0;
}

bool Landscape::isTowerT (int x, int  y) {
    std::list<TowerTrap*>::iterator it_r;
    for (it_r = actUnits.trapTower.begin(); it_r != actUnits.trapTower.end(); ++it_r) {
        if (((*it_r)->getX() == x) && ((*it_r)->getY() == y)) {
            return 1;
        }
    }
    return 0;
}

int Landscape::updateTower(int x, int y) {
    int indicatorFinder = 0;
    std::list <TowerSimple*> :: iterator it_s;
    std::list <TowerMagic*> :: iterator it_m;
    std::list <TowerTrap*> :: iterator it_t;
    for (it_s = actUnits.simpleTower.begin(); it_s != actUnits.simpleTower.end(); ++it_s) {
        if (((*it_s)->getX() == x) && ((*it_s)->getY() == y)) {
            if ((*it_s)->levelUp(castle->getGold())) {
                castle->MONEY(-(*it_s)->getCost());
                std::cout << "Отнял столько денег:" << (*it_s)->getCost() << std::endl;
            }
            indicatorFinder = 1;
            return 0;
        }
    }
}


bool Landscape::isTower (int x, int y) {
    if (isTowerM(x, y) || isTowerS(x, y) || isTowerT(x, y)) {
        return 1;
    }
    return 0;
}

bool Landscape::isForest (int x, int y) {
    std::list<Forest*>::iterator it_r;
    for (it_r = actUnits.forest.begin(); it_r != actUnits.forest.end(); ++it_r) {
        if (((*it_r)->getX() == x) && ((*it_r)->getY() == y)) {
            return 1;
        }
    }
    return 0;
}

int Landscape::addTower(int x, int y, int type, std::list <Road*> *roadList) {
    if (castle->getGold() >= TowerSimple::levelsTable->price) {
        if (isTower(x, y)) {
            updateTower(x, y);
        } else {
            if (type == 1) {
                if (!isForest(x, y) && !isRoad(x, y)) {
                    auto *newTowerS = new TowerSimple(x, y, roadList);
                    actUnits.simpleTower.push_back(newTowerS);
                }
            }
            if (type == 2) {
                if (!isForest(x, y) && !isRoad(x, y)) {
                    auto *newTowerM = new TowerMagic(x, y, roadList);
                    actUnits.magicTower.push_back(newTowerM);
                }
            }
            if (type == 3) {
                if (isRoad(x, y)) {
                    auto *newTowerT = new TowerTrap(x, y, roadList);
                    actUnits.trapTower.push_back(newTowerT);
                }
            }
            castle->MONEY(-TowerSimple::levelsTable->price);
        }
    }
}


void Landscape::fire(float time) {
//    std::cout << "не пуст4!!!" << std::endl;
    if (!actUnits.simpleTower.empty()) {
        auto it_r = actUnits.simpleTower.begin();
        while (it_r != actUnits.simpleTower.end()) {
            (*it_r)->minusCoolDown(time);
            if ((*it_r)->getCollDown() < 0 ) {
                (*it_r)->attack();
                (*it_r)->startRaload();
            }
            ++it_r;
        }
    }
    if (!actUnits.magicTower.empty()) {
        auto it_r = actUnits.magicTower.begin();
        while (it_r != actUnits.magicTower.end()) {
            (*it_r)->minusCoolDown(time);
            if ((*it_r)->getCollDown() < 0 ) {
                (*it_r)->attack();
                (*it_r)->startRaload();
            }
            ++it_r;
        }
    }
    if (!actUnits.trapTower.empty()) {
        auto it_r = actUnits.trapTower.begin();
        while (it_r != actUnits.trapTower.end()) {
            (*it_r)->attack();
            ++it_r;
        }

    }

}

