//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_ROAD_H
#define TOWERDEFENCE_ROAD_H
#include "Square.h"
#include <list>
#include "../activeUnits/Enemy.h"


/*!
	\brief Класс-дорога.

	Содержит:
    Список указателей на врагов, которые сейчас находятся на данном участке дороги И указатель на следующую дорогу
*/

class Road: public Square {
private:
    std::list<class Enemy*> enemies;

    Road* next;

public:
    Road(int x, int y);

    int setNext(Road*);

    Road* getNext();

    /*!
  Возврашает указатель на противника с наименьшим хп на данном участке дороги
  */

    Enemy* getLowHP();

    Enemy* getFirst();

    /*!
Добавление противника на этот элемент дороги
*/

    int addHere(Enemy*);

    std::list<Enemy*>::iterator getIter() { return enemies.begin(); };

    std::list<Enemy*>:: iterator getLIter() { return enemies.end(); };

    /*!
Удаление противника с этого элемента дороги
*/

    int deleteHere(Enemy*);
};




#endif //TOWERDEFENCE_ROAD_H
