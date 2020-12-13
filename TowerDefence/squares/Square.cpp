//
// Created by Данил Морозов on 30/11/2020.
//

#include "Square.h"



Square::Square(int x, int y): x(x), y(y) {};

int Square::getX() {
    return x;
}

int Square::getY() {
    return y;
}

void Square::setPATH(std::string &newPATH) {
    PATH = newPATH;
}


int Square::draw(sf::RenderWindow *window) {
    sf::Texture texture;
    texture.loadFromFile(PATH);
    sf::Sprite *newSprite = new sf::Sprite(texture);
    newSprite->setPosition(x * 50, y * 50);
    sprite = newSprite;
    window->draw(*sprite);
}