//
// Created by Данил Морозов on 30/11/2020.
//

#include "Enemy.h"





Enemy::Enemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time, std::string name):
    x(x), y(y), hitPoints(hitPoints), maxHP(maxHP), speed(speed), gold(gold), timeBeforePop(time), name(std::move(name)), iamHere(
        nullptr){
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/tank3.png";
}


int Enemy::getHP() const {
    return hitPoints;
};

int Enemy::damage(int damage) {
    hitPoints -=  damage;
    if (hitPoints <= 0)
        return 1;
    return 0;
}

/*int Enemy::addEffect (int which, int level) {
    effects[effectType] = newEffect;
    return 0;
}   */

int Enemy::isMagicEffect() const {
    if ((effects[0] == nullptr) && (effects[1] == nullptr) && (effects[2] == nullptr))
        return 0;
    return 1;
}

int Enemy::setRoad(Road *road) {
    iamHere = road;
    return 0;
}

void Enemy::draw(sf::RenderWindow *window, sf::Text *text) {

    text->setFillColor(sf::Color::Black);
    text->setStyle(sf::Text::Bold);


    std::stringstream out;
    out << hitPoints << " ";
    std::string str = "" + out.str();

    text->setString(str);
    text->setPosition(x, y - 20);

    sf::Texture texture;
    texture.loadFromFile(PATH);
    sf::Sprite *newSprite = new sf::Sprite(texture);
    newSprite->setPosition(x+25, y - 25);
    sprite = newSprite;
  //  sprite->setRotation(90);
    window->draw(*sprite);
    window->draw(*text);
}
