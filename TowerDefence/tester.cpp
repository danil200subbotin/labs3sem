//
// Created by Данил Морозов on 21/12/2020.
//

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Land/Landscape.h"
#include <gtest/gtest.h>
#include <string>
#include "squares/Lair.h"




TEST (LandConstr, intint)
{
    ASSERT_NO_THROW(Landscape a(25, 25));
}


TEST (LandConstr, intint2)
{
    ASSERT_NO_THROW(Landscape a(99, 99));
}

TEST (LandConstr, intint3)
{
    ASSERT_ANY_THROW(Landscape a(0, 25));
}

TEST (LandConstr, intint4)
{
    ASSERT_ANY_THROW(Landscape a(100, 25));
}

TEST (EnemyConstr, norm1)
{
    ASSERT_NO_THROW(Enemy(0, 0, 14,  250, 4, 5, 3000));
}

TEST (TowerSimpleConstr, norm1)
{
    ASSERT_NO_THROW(TowerSimple(5, 5, nullptr));
}

TEST (TowerMagicConstr, norm1)
{
    ASSERT_NO_THROW(TowerMagic(5, 5, nullptr));
}

TEST (TowerTrapConstr, norm1)
{
    ASSERT_NO_THROW(TowerTrap(5, 5, nullptr));
}



TEST (CastleConstr, norm1)
{
    ASSERT_NO_THROW(Castle(1, 2, 150, 350, 350));
}


TEST (ForestConstr, norm1)
{
    ASSERT_NO_THROW(Forest(0, 0, 23));
}


TEST (LairConstr, norm1)
{
    ASSERT_NO_THROW(EnemiesLair(0, 12));
}


TEST (RoadConstr, norm1)
{
    ASSERT_NO_THROW(Road(24, 15));
}



TEST (SquareConstr, norm1)
{
    ASSERT_NO_THROW(Square(24, 15));
}


TEST (LandPos, norm1)
{
    Landscape a(25, 26);
    ASSERT_EQ(25 , a.getSizeX());
    ASSERT_EQ(26 , a.getSizeY());
}

TEST (LandGold, norm1)
{
    Landscape a(25, 26);
    ASSERT_EQ(250 , a.getGold());

}

TEST (EnemyGET, pos)
{
    Enemy a(0, 0, 14,  250, 4, 5, 3000);
    ASSERT_EQ(0 , a.getX());
    ASSERT_EQ(0 , a.getY());
}

TEST (EnemyGET, money)
{
    Enemy a(0, 0, 14,  250, 4, 5, 3000);
    ASSERT_EQ(5, a.getMoney());
}

TEST (EnemyTEST, effect)
{
    Enemy a(0, 0, 14, 250, 4, 5, 3000);
    ASSERT_EQ(1, a.isMagicEffect());
}

TEST (EnemyGET, hp)
{
    Enemy a(0, 0, 14, 250, 4, 5, 3000);
    ASSERT_EQ(14, a.getHP());
}


TEST (EnemyGET, speed)
{
    Enemy a(0, 0, 14, 250, 4, 5, 3000);
    ASSERT_EQ(4, a.getSpeed());
}


TEST (TowerSGET, cost)
{
    TowerSimple a(5, 5, nullptr);
    ASSERT_EQ(50, a.getCost());
}

TEST (TowerSGET, damage)
{
    TowerSimple a(5, 5, nullptr);
    ASSERT_EQ(10, a.getDamage());
}

TEST (TowerSGET, cd)
{
    TowerSimple a(5, 5, nullptr);
    ASSERT_EQ(  1000, a.getCollDown());
}

TEST (TowerSGET, xy)
{
    TowerSimple a(5, 5, nullptr);
    ASSERT_EQ(  5, a.getX());
    ASSERT_EQ(  5, a.getY());
}


TEST (TowerSGET, range)
{
    TowerSimple a(5, 5, nullptr);
    ASSERT_EQ(  3, a.getRange());
}


TEST (TowerMGET, cost)
{
    TowerMagic a(5, 5, nullptr);
    ASSERT_EQ(50, a.getCost());
}

TEST (TowerMGET, damage)
{
    TowerMagic a(5, 5, nullptr);
    ASSERT_EQ(10, a.getDamage());
}

TEST (TowerMGET, cd)
{
    TowerMagic a(5, 5, nullptr);
    ASSERT_EQ(  1000, a.getCollDown());
}

TEST (TowerMGET, xy)
{
    TowerMagic a(5, 5, nullptr);
    ASSERT_EQ(  5, a.getX());
    ASSERT_EQ(  5, a.getY());
}


TEST (TowerMGET, range)
{
    TowerMagic a(5, 5, nullptr);
    ASSERT_EQ(  3, a.getRange());
}

TEST (TowerTGET, cost)
{
    TowerTrap a(5, 5, nullptr);
    ASSERT_EQ(50, a.getCost());
}

TEST (TowerTGET, damage)
{
    TowerTrap a(5, 5, nullptr);
    ASSERT_EQ(10, a.getDamage());
}

TEST (TowerTGET, cd)
{
    TowerTrap a(5, 5, nullptr);
    ASSERT_EQ(  1000, a.getCollDown());
}

TEST (TowerTGET, xy)
{
    TowerTrap a(5, 5, nullptr);
    ASSERT_EQ(  5, a.getX());
    ASSERT_EQ(  5, a.getY());
}


TEST (CastleGET, pos)
{
    Castle a(1, 2, 150, 350, 350);
    ASSERT_EQ(  1, a.getX());
    ASSERT_EQ(  2, a.getY());
}



TEST (CastleGET, HP)
{
    Castle a(1, 2, 150, 350, 350);
    ASSERT_EQ(  350, a.getHP());
}


TEST (CastleGET, HPminus)
{
    Castle a(1, 2, 150, 350, 350);
    a.damage(100);
    ASSERT_EQ(  250, a.getHP());
}

TEST (CastleGET, Gold)
{
    Castle a(1, 2, 150, 350, 350);
    a.damage(100);
    ASSERT_EQ(  150, a.getGold());
}

TEST (CastleGET, GoldPlus)
{
    Castle a(1, 2, 150, 350, 350);
    a.MONEY(150);
    ASSERT_EQ(  300, a.getGold());
}



int _tmain(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


