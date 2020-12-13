//
// Created by Данил Морозов on 30/11/2020.
//

#include "Castle.h"

Castle::Castle(int x, int y, int gold, int HP, int mHP): Square(x, y), amountGold(gold)  {
    if ((HP > mHP) || (HP <= 0)) {
        throw std::range_error("Неверное задание HP замка");
    } else {
        hitPoints = HP;
        maxHP = mHP;
    }
    PATH = "/Users/danilmorozov/Desktop/labsgit/TowerDefence/images/castle2.png";
};


int Castle::damage(int damage) {
    hitPoints -= damage;
    return 0;
}



int Castle::MONEY(int gold) {
    amountGold += gold;
}