//
// Created by Данил Морозов on 30/11/2020.
//

#ifndef TOWERDEFENCE_LANDSCAPE_H
#define TOWERDEFENCE_LANDSCAPE_H


#include "../squares/Road.h"
#include "../squares/Castle.h"
#include "../squares/Lair.h"
#include "../activeUnits/TowerSimple.h"
#include "../squares/Forest.h"
#include "../activeUnits/TowerMagic.h"
#include "../activeUnits/TowerTrap.h"
#include "../activeUnits/Enemy.h"
#include <cmath>
#include <iterator>
#include <SFML/Window.hpp>
#include <random>
#include <iostream>
/*!
	\brief структура, содержащая всех ключевых юнитов
 */

struct actUnits{
    std::list<TowerSimple*> simpleTower;

    std::list<TowerMagic*> magicTower;

    std::list<TowerTrap*> trapTower;

    std::list<Forest*> forest;

    std::list<Road*> road;

    std::list<Enemy*> enemies;

};

/*!
	\brief Класс-контейнер, отавечающий за работу всего вместе.

	Содержит:
    Размеры Карты, Указатель на первую дорогу от логова, Указатель на замок, Указатель на логово

    Содержит списки:
    Простых башен, Магических башен, ловушек, леса, дорог, врагов

    Конструктор данного класса создает необходимые для игры вещи
*/

class Landscape {
private:
    int sizeX, sizeY;

    struct actUnits actUnits;

    Road* firstRoad;

    Castle* castle;

    EnemiesLair* lair;

public:
    Landscape(int, int);

    int getSizeX() const { return sizeX; };

    int getSizeY() const { return sizeY; };

    void drawCastle(sf::RenderWindow *window,  sf::Text *text);

    void drawLair(sf::RenderWindow *window);

    void drawRoad(sf::RenderWindow *window);

    void drawForest(sf::RenderWindow *window);

    void drawEnemies(sf::RenderWindow *window, sf::Text *text);

    void drawTowers(sf::RenderWindow *window);

    int getCastleX() const;

    int getCastleY() const;

    /*!
   Обновляет позиции проивников на карте
   */


    int updateEnemies(float);

    int setTower(int, int, int);

    /*!
   Добавление противника из логова на дорогу
   */


    int pushEnemy(int x, int y, int hitPoints, int maxHP, float speed, int gold, float time);

    /*!
   Добавление башни
   */


    int addTower (int x, int y, int type, std::list <Road*> *roadList);

    int getGold();

    bool isForest (int x, int y);

    bool isRoad (int x, int y);

    bool isTowerS (int x, int y);

    bool isTowerM (int x, int y);

    bool isTowerT (int x, int y);

    bool isTower (int x, int y);


    /*!
   Улучшение башни
   */

    int updateTower (int x, int y);

    std::list <Road*>* getRoad();

    /*!
  Огонь из всех орудий и ловушек (если выполнены условия)
  */

    void fire(float time);


};

#endif //TOWERDEFENCE_LANDSCAPE_H
