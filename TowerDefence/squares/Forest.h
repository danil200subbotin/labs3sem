//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_FOREST_H
#define TOWERDEFENCE_FOREST_H
#include "Square.h"

class Forest: public Square {
private:
    int cost;
public:
    Forest(int, int, int);  //x, y, стоимость удаления леса

    int setCost(int);

    int buyForest();


};

#endif //TOWERDEFENCE_FOREST_H
