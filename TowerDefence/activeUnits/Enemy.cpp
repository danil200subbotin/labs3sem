//
// Created by Данил Морозов on 30/11/2020.
//

#include "Enemy.h"





Enemy::Enemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time, std::string name):
    x(x), y(y), hitPoints(hitPoints), maxHP(maxHP), speed(speed), gold(gold), timeBeforePop(time), name(std::move(name)), iamHere(
        nullptr){
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/tank3.png";
    colourTime = 5;
}


int Enemy::getHP() const {
    return hitPoints;
};



int Enemy::damage(int damage, int red, int green, int blue) {
    hitPoints -=  damage;
    if (hitPoints <= 0)
        return 1;
    if (colour.is_empty()) {
        colourInd *newColour = new struct colourInd;
        newColour->red = red;
        newColour->blue = blue;
        newColour->green = green;
        colour.push(newColour);
    }
    return 0;
}

int Enemy::addEffect (struct Effect effect, int type, int red, int green, int blue) {
    if (effects[type] == nullptr)
        effects[type] = new Effect;
    *effects[type] = effect;
    if (colour.is_empty()) {
        colourInd *newColour = new struct colourInd;
        newColour->red = red;
        newColour->blue = blue;
        newColour->green = green;
        colour.push(newColour);
    }
    return 0;
}

int Enemy::chekAndDeleteEffects() {
    for (int i = 0; i <= 2; ++i) {
        if (effects[i] != nullptr) {
            --effects[i]->time;
            if (effects[i]->time < 0) {
                delete effects[i];
                effects[i] = nullptr;
            }
        }
    }
}

int Enemy::isMagicEffect() const {
    if ((effects[0] == nullptr) && (effects[1] == nullptr) && (effects[2] == nullptr))
        return 0;
    return 1;
}

int Enemy::setRoad(Road *road) {
    iamHere = road;
    return 0;
}

float Enemy::getSpeedKoaf() {
    float koaff = 1;
    for (int i = 0; i <= 1; ++i) {
        if (effects[i] != nullptr) {
            koaff += float(effects[i]->slow);
        }
    }
    return koaff;
}

int Enemy::getDamageKoaf() {
    int koaff = 1;
    for (int i = 0; i <= 1; ++i) {
        if (effects[i] != nullptr) {
            koaff += float(effects[i]->illness);
        }
    }
    return koaff;
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

    if (!colour.is_empty()) {
            if (colourTime > 0) {
                //std::cout <<"время сейчас:" << colourTime << std::endl;
                sprite->setColor(sf::Color(colour.peek()->red, colour.peek()->green, colour.peek()->blue));
                --colourTime;
            } else {
                colour.pop();
                colourTime = 5;
            }
    }
    window->draw(*sprite);
    window->draw(*text);
}
