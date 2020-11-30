//
// Created by Данил Морозов on 26/11/2020.
//
#include "map.h"

namespace map {

    Landscape::Landscape(int x, int y) {
        if ((x <= 1) || (y <= 1) || (x >= 11) || (y >= 11)) {
            throw std::range_error("Пресечена попытка создания карты с неприменимыми размерами");
        }
        int coordinator = 0;
        int xl, yl, xc, yc; // помогают при случайном определении позиций элементов на карте (xl и yl снасала указывают на логово, а затем они будут указывать на местоположение следующего участка дороги)
        Forest* newForest = nullptr;
        for (int i = 1; i <= y; ++i) {
            for (int j = 1; j <= x; ++j) {
                //  лес
                if (std::rand() % 4 == 0) {                //тут можно регулировать шанс появления леса на карте
                    newForest = new Forest(i, j, std::rand() % 30);     //случайная цена за удаление леса
                    actUnits.forest.push_back(newForest);
                 //   mapSlots.push_back(&newForest);
                }
            }
        }
        bool indicator = true;
        int distance = (x + y) / 2;             //подбираю достаточно удаленное расположение логова и замка
        while (indicator) {
            xl = (std::rand() + 321331) % x + 1;           //геопозиция будущего логова
            yl = (std::rand() + 542331) % y + 1;
            xc = (std::rand() + 491331) % x + 1;           //геопозиция будущего замка
            yc = (std::rand() + 992331) % y + 1;
            if (sqrt((xl - xc) * (xl - xc) + (yl - yc) * (yl - yc) >= distance))
                indicator = false;
        }
            Castle(xc, yc, 0, 100, 100);
            castle = new Castle(xc, yc, 0, 100, 100);
            lair = new EnemiesLair(xl, yl);
        //    mapSlots.push_back(&castle);
        //    mapSlots.push_back(&lair);


            int amountRoadsX = abs(xc - xl) - 1, amountRoadsY = abs(yc - yl) - 1;
            int roadX, roadY;
    //    <контейнер> <его тип> :: iterator <имя итератора>;
            std::list <Forest*> :: iterator it_f
            coordinator = 0;
            if ((xc - xl) >= 0)
                ++coordinator;
            if ((yc - yl) >= 0)
                ++coordinator;
            switch (coordinator) {
                case 0:
                    if (amountRoadsY > 0) {
                        roadY = yl - 1;
                        roadX = xl;
                    } else {
                        roadY = yl;
                        roadX = xl - 1;
                    }
                    break;
                case 1:
                    if (yl > 1) {
                        roadY = yl - 1;
                        roadX = xl;
                    } else {
                        if (xc > xl) {
                            roadY = yl;
                            roadX = x + 1;
                        } else {
                            roadY = yl;
                            roadX = x - 1;
                        }
                    }
                    break;
                case 2:
                    if (amountRoadsY > 0) {
                        roadY = yl + 1;
                        roadX = xl;
                    } else {
                        roadY = yl;
                        roadX = xl + 1;
                    }
            }

            firstRoad = new Road(roadX, roadY);

            Road* prevRoad = firstRoad;
            Road* currentRoad = nullptr;

            while (amountRoadsX + amountRoadsY > 0) {
                if ((rand() % 2 == 0) && (amountRoadsX > 0)) {
                    if (xc > xl) {
                        ++xl;
                    } else {
                        --xl;
                    }
                    --amountRoadsX;
                } else {
                    if (amountRoadsY > 0) {
                        if (yc > yl) {
                            ++yl;
                        } else {
                            --yl;
                        }
                        --amountRoadsY;
                    }
                }
                newForest = actUnits.forest.front();
                it_f = actUnits.forest.begin();
                for (it_f = actUnits.forest.begin(); it_f != actUnits.forest.end(); ++it_f) {
                    if (((*it_f)->getX() == xl) && ((*it_f)->getY() == yl)) {
                        it_f = actUnits.forest.erase(it_f);                     //удаляю лес, совпавший с дорогами
                    }
                }
                currentRoad = new Road(xl, yl);
                prevRoad->setNext(currentRoad);
                actUnits.road.push_back(currentRoad);
                prevRoad = currentRoad;
            }
    }

}
