//
// Created by Данил Морозов on 28/10/2020.
//

#ifndef LAB3BYTE3_BIGLONG_H
#define LAB3BYTE3_BIGLONG_H
#include <iostream>
#include <cmath>
#include <stdexcept>


namespace laba3bit3 {

    class Biglong {
    private:
        static const int QUOTA = 5;   //размер, на который будет увеличиваться BIGint во время переполнений
        int SZ;                       //текущий максимальный размер (соответствует количеству выделенной памяти)
        int length;                   //размер числа в количестве используемых элементов (char* [])
        char *value;                  //указатель на массив элементов BIGint
    public:
        //конструктры
        Biglong();    //пустой конструктор    //дописать
        explicit Biglong(long parameter);  //инициализайия через длинное целое
        Biglong(const char *char_value);  //инициализация по строки
        Biglong(const Biglong &biglong);        //копирующий конструктор
        ~Biglong();
        //геттеры
        int get_length() const { return length; };
        char get_one_char(int i) const { return value[i]; };
        int get_max_length() const { return SZ; };

        void clear_spaces ();
        void set_length(int new_length);
        void set_one_char(int number, int value);
        void set_max_length(int new_max_length);
        void div10();    //выполнение операции “уменьшения числа в десять раз” (деление на 10 нацело)ы
        void multi10();
        void free_value();
        void new_value(int count);
        //часть с перегрузками
        friend std::ostream &operator<<(std::ostream &ostream, const Biglong &biglong); //выввод в входной поток
        friend std::istream &operator>>(std::istream &istream, Biglong &biglong); //ввод из входного потока
        Biglong operator~() const;
        Biglong& operator ++();//получение дополнительного кода числа ((*) с помощью перегруженного оператора ~ )
        const Biglong operator+(const Biglong &argument) const;    //выполнение операций сложения
        const Biglong operator-(const Biglong &argument) const;
        Biglong& operator=(const Biglong &argument);
    };

    char *readln(void);
    char num_to_char(int);
    int char_to_num(char a);

    template<class T>
    double getNum(T &a) {                //проверочка ввода соответствующего типа данных
        int i = 1;
        while (i == 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> a;
            if (!std::cin.good())
                i = 1;
            else
                i = 0;
            if (i != 0) std::cout << "Вы ввели неприемлимое значение, повторите ввод" << std::endl;
        }
        return 0;
    }
}




#endif //LAB3BYTE3_BIGLONG_H
