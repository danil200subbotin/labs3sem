//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_LAIR_H
#define TOWERDEFENCE_LAIR_H
#include <stack>
#include <list>
#include "Square.h"
#include "../activeUnits/Enemy.h"

struct enemyTime{
    int time;

    Enemy* enemy;
};

/*!
	\brief Класс-логово.

	Содержит:
    Этот класс содержт в себе список структур, содержащих ссылки на врагов и всемя до их выхода из логова
*/

class EnemiesLair: public Square {
private:

    int quantity;

    std::list<struct enemyTime> enemies;

public:
    EnemiesLair(int, int);

    /*!
  Добавление противника в логово
  */
    int pushEnemy (struct enemyTime& enemyTime);

    /*!
 Достаем на дорогу следующего противника
  */

    int popNext();

    int Render();

};


#endif //TOWERDEFENCE_LAIR_H
