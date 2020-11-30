//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_SQUARE_H
#define TOWERDEFENCE_SQUARE_H


class Square {
protected:
    int x, y;
    int type;
    enum types{road = 1, castle, lair, forest, tower, field};

public:
    Square(int, int, int);

    virtual int Render();

    int setCoord(int, int);

    int getX();

    int getY();

};

#endif //TOWERDEFENCE_SQUARE_H
