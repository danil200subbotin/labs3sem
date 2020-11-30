//
// Created by Данил Морозов on 30/11/2020.
//

#include "Castle.h"

Castle::Castle(int x, int y, int gold, int HP, int mHP): Square(x, y, castle), amountGold(gold) {
    if ((HP > maxHP) || (HP <= 0)) {
        throw std::range_error("Неверное задание HP замка");
    } else {
        hitPoints = HP;
        maxHP = mHP;
    }
};