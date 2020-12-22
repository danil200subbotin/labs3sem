//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_SQUARE_H
#define TOWERDEFENCE_SQUARE_H
#include <string>
#include <SFML/Graphics.hpp>


/*!
	\brief Родительский класс - квадрат

	Этот класс является родительским для всех классов, отображающихся на карте (башни, ловушки замок, лес, логово, дороги, и тд)
*/

class Square {
protected:
    int x, y;

    sf::Sprite *sprite;

    std::string PATH;

public:
    Square(int, int);

    int draw(sf::RenderWindow *window);

    int setCoord(int, int);

    int getX();

    int getY();

    void setPATH(std::string &newPATH);

};

#endif //TOWERDEFENCE_SQUARE_H
