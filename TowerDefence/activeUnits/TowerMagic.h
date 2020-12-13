//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERMAGIC_H
#define TOWERDEFENCE_TOWERMAGIC_H


#include "TowerSimple.h"
#include "structs.h"


class TowerMagic: public TowerSimple {
private:


public:
    static const Effect effectsTable[3];

 //   int attack() override;

    TowerMagic(int x, int y, std::list <Road*> *roadList);

};



#endif //TOWERDEFENCE_TOWERMAGIC_H
