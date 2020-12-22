//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERMAGIC_H
#define TOWERDEFENCE_TOWERMAGIC_H


#include "TowerSimple.h"
#include "structs.h"

/*!
	\brief Класс, отавечающий за магическую башню

	Относительно простой башни тут перегружена атака, а так же добавлены статические стуктуры с эффектами башен
*/

class TowerMagic: public TowerSimple {


public:
    static const Effect effectsTable[3];

    int attack() override;

    TowerMagic(int x, int y, std::list <Road*> *roadList);

};



#endif //TOWERDEFENCE_TOWERMAGIC_H
