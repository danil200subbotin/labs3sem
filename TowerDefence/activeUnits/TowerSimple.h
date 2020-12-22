//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_TOWERSIMPLE_H
#define TOWERDEFENCE_TOWERSIMPLE_H

#include "Tower.h"


/*!
	\brief Таблица эффектов обыкновенной башни
 */

struct TowerLevel{
    int damage;

    int reload;

    int radius;

    int price;

    int maxLevel;

    std::string PATH;
};

/*!
	\brief Класс, отавечающий за обычную башню

	Тут определяются все виртуальные методы абстрактного класса Башня.
*/

class TowerSimple: public Tower{
private:

    float cooldown;


public:

    static const TowerLevel levelsTable[3];

    TowerSimple(int x, int y, std::list <Road*> *roadList);

    /*!
    Башня производит выстрел в противника с наименьшим количеством HP из радиуса ее действия
    */
    int attack() override;

    /*!
   Увеличивает уровень башни, если достаточно средств
     \param[in] amountGold количетво средств в замке
   */

    int levelUp(int amountGold) final;

    /*!
    Возвращает радиус действия башни
    */

    int getRange() override;

    /*!
    Возвращает текущий урон от башни
    */

    int getDamage() override;

    int getCost();

    /*!
    Позволяет встат башне на перезарядку
    */

    int getCollDown () { return cooldown; };

    /*!
    Уменьшает перезарядку
    */

    void minusCoolDown (float);

    /*!
    Начало перезарядки
    */

    void startRaload ();
};




#endif //TOWERDEFENCE_TOWERSIMPLE_H
