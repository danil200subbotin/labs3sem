//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_CASTLE_H
#define TOWERDEFENCE_CASTLE_H


#include "Square.h"
#include <stdexcept>

/*!
	\brief Класс замок, хранит некоторые данные об игре.

	Содержит:
    Баланс игрока, остаток хитпойнтов замка
*/


class Castle: public Square {
private:

    int hitPoints;

    int maxHP;

    int amountGold;

    std::string defeat;

public:
    Castle(int x, int y, int gold, int HP, int mHP);

    int MONEY(int gold);

    int getGold() const { return amountGold; };

    /*!
  Нанесение урона замку
  */

    int damage(int);

    int getHP() const { return hitPoints; };

};

#endif //TOWERDEFENCE_CASTLE_H
