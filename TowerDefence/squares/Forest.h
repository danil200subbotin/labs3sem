//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_FOREST_H
#define TOWERDEFENCE_FOREST_H

/*!
	\brief Класс-лес

    Это лес, просто лес, функционал по покупке леса пока не добавлен

*/

#include "Square.h"

class Forest: public Square {
private:
    int cost;
public:
    Forest(int, int, int);  //x, y, стоимость удаления леса

    int setCost(int);

    /*!
  Покупка участка леса с целью установить там башню
  */

    int buyForest();


};

#endif //TOWERDEFENCE_FOREST_H
