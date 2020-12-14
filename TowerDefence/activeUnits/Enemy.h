//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_ENEMY_H
#define TOWERDEFENCE_ENEMY_H

#include "structs.h"
#include "../squares/Road.h"
#include <string>
#include <sstream>
#include <utility>
#include "../Stack.h"


class Enemy {
private:
    int x, y;

    std::string PATH;

    std::string name;

    int hitPoints;

    sf::Sprite *sprite;

    int maxHP;

    float speed;

    int colourTime;

    int gold;

    float timeBeforePop;

    class Road* iamHere;

    struct Effect* effects[3];

    Stack<struct colourInd*> colour;


public:

    int getMoney() const { return gold; };

    Enemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time, std::string name = "Vadim");

    float getSpeed() const { return speed; };

    void setX(int newX) { x = newX; };

    void setY(int newY) { y = newY; };

    int getX() { return x; };

    float getSpeedKoaf();

    int getDamageKoaf();

    int getY() { return y; };

    int setRoad(Road* road);

    class Road* getRoad() { return iamHere; };

    void minusTime(float deltaTime) { timeBeforePop -= deltaTime; };

    float getTime() { return timeBeforePop; };

    int isMagicEffect() const;

    int getHP() const;

    void draw (sf::RenderWindow *window, sf::Text *text);

    int addEffect (struct Effect const, int effectType, int red, int green, int blue);

    int damage (int damage, int red, int green, int blue);

    int chekAndDeleteEffects ();
};


#endif //TOWERDEFENCE_ENEMY_H
