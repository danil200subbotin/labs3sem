//
// Created by Данил Морозов on 06/10/2020.
//

#include "biglong.h"
#include <cmath>
#include <iostream>
//#include <cstring>

namespace laba3bit1 {

    Biglong::Biglong(const Biglong &biglong) {
        Biglong::length = biglong.get_length();
        for (int i = 0; i <= MAX_LENGTH; ++i) {
            Biglong::value[i] = char(biglong.get_one_char(i));
        }
    }


    Biglong::Biglong() : length(0) {
        for (int i = 0; i <= MAX_LENGTH; ++i) {
            value[i] = '0';
        }
    };

    Biglong::Biglong(long parametr) {
        //       std::cout << "я тут" << std::endl;
        int counter = 0;
        long parametr_copy = parametr;
        if (parametr > 0) {
            Biglong::value[0] = '0';
        } else {
            Biglong::value[0] = '9';
            parametr_copy = -parametr_copy;
        }
        while (parametr_copy > 0) {
            //     std::cout << "изменяю: " << MAX_LENGTH - counter << " НА " << parametr_copy % 10 << std::endl;
            if (MAX_LENGTH - counter < 1)
                throw "подано слишком большое значение long";
            Biglong::value[MAX_LENGTH - counter] = num_to_char(parametr_copy % 10);
            parametr_copy = parametr_copy / 10;
            ++counter;
        }
        Biglong::length = counter;
        for (int i = 1; i <= MAX_LENGTH - counter; ++i) {
            Biglong::value[i] = '0';
        }
    }


    Biglong::Biglong(const char *char_value) {
        int i = int(strlen(char_value)), j = 0;
        //    std::cout << i << std::endl;


        if (char_value[0] == '-') {
            value[0] = '9';
            j++;
            --i;
        } else {
            value[0] = '0';
            if (((int) char_value[0] < '0') || ((int) char_value[0] > '9')) {
                throw "Попытка инициализировать класс некорректной строкой";
            }
        }
        if (i > MAX_LENGTH)
            throw "попытка присвоить объекту слишком длинной строки";
        Biglong::length = i;
        while (char_value[j] != '\0') {
            if (((int) char_value[j] >= '0') & ((int) char_value[j] <= '9')) {
                value[MAX_LENGTH - i + 1] = char_value[j];
                --i;
                ++j;

            } else {
                std::cout << "В строке встретился не числовой символ" << std::endl;
                throw "В строке встретился не числовой символ";
            }
        }
        for (int i = 1; i <= MAX_LENGTH - Biglong::length; ++i) {
            Biglong::value[i] = '0';
        }

    }

    void laba3bit1::Biglong::div10() {
        for (int i = MAX_LENGTH; i > 1; --i) {
            Biglong::value[i] = Biglong::value[i - 1];
        }
    }

    void laba3bit1::Biglong::multi10() {
        if (Biglong::value[1] == '0') {
            for (int i = 1; i < MAX_LENGTH; ++i) {
                Biglong::value[i] = Biglong::value[i + 1];
            }
            Biglong::value[MAX_LENGTH] = '0';
        } else
            throw "невозможно выполнить умножение из-за опасности переполнения стека";
    }




//const laba3bit1::Biglong operator~ () const {

//----------------------------------------------------------------------тут пошла часть с перегрузками-----------------


//вывод класса в поток




    std::ostream& Biglong::print(std::ostream& ostream) {
        int i = 1;
        if ((*this).get_one_char(0) == '9')
            ostream << "-";
        while (i <= (*this).get_max_value()) {
            ostream << (*this).get_one_char(i);
            ++i;
        }
        ostream << std::endl;
        return ostream;
    }



    std::istream& Biglong::input(std::istream& istream) {
        for (int k = 1; k <= (*this).get_max_value(); ++k) {
            (*this).set_one_char(k, 0);
        }
        std::cout << "tut" << std::endl;
        char streamer[(*this).get_max_value() + 1];
        istream >> streamer;                                                //здесь может быть считывание нормальной строки
        int i = int(strlen(streamer)), j = 0;
        std::cout << "i = " << i << std::endl;
        if (i > (*this).get_max_value())
            throw "попытка присвоить объекту слишком длинной строки";
        if (streamer[0] == '-') {
            (*this).set_one_char(0, 1);
            j++;
            --i;
        } else {
            (*this).set_one_char(0, 0);
            if (((int) streamer[0] < '0') || ((int) streamer[0] > '9')) {
                throw "Попытка инициализировать класс некорректной строкой";
            }
        }
        (*this).set_length(i);
        while (streamer[j] != '\0') {
            if (((int) streamer[j] >= '0') & ((int) streamer[j] <= '9')) {
                std::cout << "заменяю: " << (*this).get_max_value() - i + 1 << " на: " << streamer[j] << std::endl;
                (*this).set_one_char((*this).get_max_value() - i + 1, char_to_num(streamer[j]));
                --i;
                ++j;
            } else {
                std::cout << "В строке встретился не числовой символ" << std::endl;
                throw "В строке встретился не числовой символ";
            }
        }
        return istream;
    }


    Biglong Biglong::dop_code() const {                      //здесь еще нужно написать прибавление единички
        Biglong newest(*this);
        if ((newest.get_one_char(0) == '9') || (newest.get_one_char(0) == '1')) {
            newest.set_one_char(0, 9);
            for (int i = 1; i <= MAX_LENGTH; ++i) {
                newest.set_one_char(i, 9 - char_to_num(newest.get_one_char(i)));
            }
            newest = newest.plusplus_one();
        }
        return newest;
    };


    Biglong &Biglong::plusplus_one() {
        int a = 0, ostatok = 1, i = MAX_LENGTH;
        while ((i > 0) & (ostatok > 0)) {
            a = char_to_num(value[i]);
            a = ostatok + a;
            value[i] = num_to_char(a % 10);
            ostatok = a / 10;
            --i;
        }
        if ((i < 1) & (ostatok != 0)) {
            throw "переполнение стека";
        }
        return *this;
    }


    Biglong Biglong::plus(const Biglong &argument) const {
        Biglong result(*this);
        result = result.dop_code();
        int a = 0, b = 0, over = 0;
        Biglong argument_copy;
        argument_copy = argument.dop_code();
        for (int i = MAX_LENGTH; i >= 0; --i) {
            a = char_to_num(result.get_one_char(i));
            b = char_to_num(argument_copy.get_one_char(i));
            a = a + b + over;
            result.set_one_char(i, a % 10);
            over = a / 10;
        }
        //     std::cout << result.get_one_char(0) << "result0" << std::endl;
        //      std::cout << argument_copy.get_one_char(0) << "a_to_copy0" << std::endl;
        if (result.get_one_char(0) != '0') {
            result.set_one_char(0, 9);
            for (int i = 1; i <= MAX_LENGTH; ++i) {
                result.set_one_char(i, 9 - char_to_num(result.get_one_char(i)));
            }
            result = result.plusplus_one();

        }
        return result;
    }

    Biglong Biglong::minus(const Biglong &argument) const {
        Biglong argument_copy = argument;
        if (argument.get_one_char(0) == '0')
            argument_copy.set_one_char(0, 9);
        else
            argument_copy.set_one_char(0, 0);
        return ((*this).plus(argument_copy));
    }


    void Biglong::set_one_char(int number, int value) {
        Biglong::value[number] = num_to_char(value);
    }



    char num_to_char(int num) {
        switch (num) {
            case 0:
                return '0';
            case 1:
                return '1';
            case 2:
                return '2';
            case 3:
                return '3';
            case 4:
                return '4';
            case 5:
                return '5';
            case 6:
                return '6';
            case 7:
                return '7';
            case 8:
                return '8';
            case 9:
                return '9';
        }
        return '-';
    }

    int char_to_num(char a) {
        switch (a) {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
        }
        return
                '-';
    }


    char *readln(void) {
        fseek(stdin, 0, SEEK_END);

        //   printf("введите информацию\n");
        char *ptr = (char *) malloc(1);
        *ptr = '\0';
        char buf[101];
        int n, len = 0;
        do {
            n = scanf("%100[^\n]", buf);
            //printf("buff = %s\n",buf);
            if (n < 0) {
                free(ptr);
                ptr = NULL;
                continue;
            }
            if (n == 0)
                scanf("%*c");
            else {
                len += strlen(buf);
                // printf("len = %d\n",len);
                ptr = (char *) realloc(ptr, len + 1);
                strcat(ptr, buf);
            }
        } while (n > 0);
        return ptr;
    }
}
