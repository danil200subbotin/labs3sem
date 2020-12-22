//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERTRAP_H
#define TOWERDEFENCE_TOWERTRAP_H


#include "structs.h"
#include "TowerSimple.h"


/*!
	\brief Класс, отавечающий за ловушки

	Относительно простой башни тут перегружена атака, а так же добавлены статические стуктуры с эффектами башен. + добавлен индикатор взорванности
*/

class TowerTrap: public TowerSimple {
private:
    int damage;
    int range;
    static const Effect effectsTable[2];
    bool boomed;

public:

    TowerTrap(int x, int y, std::list <Road*> *roadList);

    int getRange() override;

    int attack() override;

};

#endif //TOWERDEFENCE_TOWERTRAP_H
