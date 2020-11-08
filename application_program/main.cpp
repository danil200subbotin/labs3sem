#include "utils.h"
#include <iostream>

using namespace lab3;

int main (){
    std::cout << "Добро пожаловать в прикладную программу по домино." << std::endl;
    std::cout << "Поскольку данный класс умеет только создавать рандомные наборы домино." << std::endl;
    std::cout << "Я придумал новую игру 'Азартное домино', правила расскажу устно" << std::endl;
    std::cout << "Сколько человек будет участвовать в игре? (1 < x)" << std::endl;
    int a = 0;
    std::cin >> a;
    Domino *players[a];
    int rate[a];
    int summ[a];
    int playersCounter;
    for (int i = 0; i < a; i++) {
        summ[i] = 0;
        rate[i] = 0;
        players[i] = new Domino(20);
    }
   // std::cout << "test {" << players[0]->operator[](0).getLeft() <<", " << players[0]->operator[](0).getRight() << "}"<<std::endl;
    std::cout << "Ставим первые ставки" << std::endl;

    bool ender = true;
    int counter = 1;
    int bank = 0;
    int tester = 0;
    while (ender) {
        std::cout << "Если вы выходите из игры - жмите 0 или ставьте мЕньшую ставку (деньги уходят в банк)" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "ROUND-" << counter << ". Пришло время ставить cтавки" << std::endl;
        for (int i = 0; i < a; i++) {
            if (rate[i] != -1) {
                std::cout << "Игрок" << i + 1 << " введите ставку----->";
                std::cin >> tester;
                if ((tester == 0) || (tester < rate[i]) {
                    bank += rate[i];
                    rate[i] = -1;
                } else {
                    rate[i] = tester;
                }
            }
        }
        std::cout << "Вот такие вам выпали домино" << std::endl;
        for (int i = 0; i < a; ++i) {
            if (rate[i] != -1) {
                std::cout << "Игрок" << i + 1 << " - {" << players[i]->operator[](counter - 1).getLeft() <<", " << players[i]->operator[](counter - 1).getRight() << "}"<<std::endl;
            }
        }
        std::cout << "Вот такая стала ваша сумма баллов:" << std::endl;
        for (int i = 0; i < a; ++i) {
            if (rate[i] != -1) {
                summ[i] = summ[i] + players[i]->operator[](counter - 1).getLeft() + players[i]->operator[](counter - 1).getRight();
                std::cout << "Игрок" << i + 1 << " сумма стала: " << summ[i] << std::endl;
            }
        }
        std::cout << "после этого раунда в игре осталось: " << std::endl;
        playersCounter = 0;
        for (int i = 0; i < a; ++i) {
            if (rate[i] != -1) {
                ++ playersCounter;
            }
        }
        std::cout << playersCounter <<" игрока(ов)!"<< std::endl;
        ++ counter;
        if ((counter == 20) || (playersCounter == 1))
            ender  = false;
        else {
            std::cout << "Хотите ли вы сейчас закончить игру? 0 - Да, 1 - Нет" << std::endl;
            std::cin >> ender;
        }
    }
    std::cout << "Пришло время подводить итоги" << std::endl;
    int biggest = -1;
    for (int i = 0; i < a; ++i) {
        if (rate[i] != -1) {
            bank
            += rate[i];
            if (summ[i] > biggest)
                biggest = summ[i];
        }
    }

    std::cout << "Вот такая сумма находится в банке: " << bank << std::endl;
    std::cout << "Вот победители, которые поделят данный приз: " << std::endl;
    for (int i = 0; i < a; ++i) {
        if (rate[i] != -1) {
            if (summ[i] == biggest)
                std::cout << "Игрок" << i + 1 << std::endl;
        }
    }

}