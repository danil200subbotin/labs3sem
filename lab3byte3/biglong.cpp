//
// Created by Данил Морозов on 28/10/2020.
//

#include "biglong.h"


namespace laba3bit3 {


    Biglong::Biglong(const Biglong &biglong) {
        Biglong::length = biglong.get_length();
        Biglong::SZ = biglong.get_max_length();
        Biglong::value = new char[SZ];
        for (int i = 0; i <= SZ; ++i) {
            Biglong::value[i] = char(biglong.get_one_char(i));
        }
    }

    Biglong::Biglong() : length(0), SZ(QUOTA), value(new char[QUOTA + 1]) {
        for (int i = 0; i <= SZ; ++i) {
            value[i] = '0';
        }
    };


    Biglong::Biglong(long parametr) {
        int counter = 0;
        long parametr_copy = parametr;

        while (parametr_copy != 0) {
            parametr_copy = parametr_copy / 10;
            ++counter;
        }

        value = new char[counter + 1];
        length = counter;
        SZ = counter;

        if (parametr > 0) {
            value[0] = '0';
            parametr_copy = parametr;
        } else {
            value[0] = '9';
            parametr_copy = -parametr;
        }

        for (int i = 1; i <= SZ; ++i) {
            value[i] = '0';
        }



        for (int i = SZ; i >= 1; --i) {
            value[i] = num_to_char(int(parametr_copy % 10));
            parametr_copy = parametr_copy / 10;
        }

    }

    Biglong::~Biglong() {
        if(value)
            delete[] value;
        value = nullptr;
    }

    Biglong::Biglong(const char *char_value) {
        int new_length = int(strlen(char_value)), j = 0;

        if (char_value[0] == '-') {
            value = new char[new_length];
            value[0] = '9';
            j++;
            --new_length;
        } else {
            if ((char_value[0] < '0') || (char_value[0] > '9')) {
                throw std::range_error("Попытка инициализировать класс некорректной строкой");
            }
            value = new char[new_length + 1];
            value[0] = '0';
        }

        length = new_length;
        SZ = new_length;

        for (int i = 1; i <= new_length; ++i) {
            if ((char_value[j] >= '0') & (char_value[j] <= '9')) {
                value[i] = char_value[j];
                ++j;
            } else {
                std::cout << "В строке встретился не числовой символ" << std::endl;
                throw std::range_error("В строке встретился не числовой символ");
            }
        }
    }

    void Biglong::div10() {
        for (int i = SZ; i > 1; --i) {
            value[i] = value[i - 1];
        }
        value[1] = '0';
    }

    void Biglong::multi10() {
            if (value[1] == '0') {
                for (int i = 1; i < SZ; ++i) {
                    value[i] = value[i + 1];
                }
                value[SZ] = '0';
            } else {
                char copy[SZ + 1];
                for (int i = 0; i <= SZ; ++i) {
                    copy[i] = value[i];
                }
                free_value();
                new_value(get_max_length() + 1);
                for (int i = 0; i <= SZ; ++i) {
                    value[i] = copy[i];
                }
                value[SZ + 1] = '0';
                set_max_length(SZ + 1);
                set_length(get_length() + 1);

            }
    }




//----------------------------------------------------------------------тут пошла часть с перегрузками-----------------


//int Biglong::get_max_length() const { return SZ; };    //пришлось написать это здесь из-за странного бага

//вывод класса в поток
    std::ostream &operator<<(std::ostream &stream, const laba3bit3::Biglong &biglong) {
        int i = 1;
        if (biglong.get_one_char(0) != '0')
            stream << "-";
        int max_length = biglong.get_max_length();
        while (max_length >= i) {
            stream << biglong.get_one_char(i);
            ++i;
        }
        stream << std::endl;
        return stream;
    }


    std::istream &operator>>(std::istream &istream, laba3bit3::Biglong &biglong) {

        biglong.free_value();
        char *streamer;
        streamer = readln();
        int new_length = int(strlen(streamer)), j = 0;
        std::cout << "i = " << new_length << std::endl;
        if (streamer[0] == '-') {
            --new_length;
            biglong.new_value(new_length + 1);
            biglong.set_one_char(0, 9);
            j++;
        } else {
            biglong.new_value(new_length + 1);
            biglong.set_one_char(0, 0);
            if ((streamer[0] < '0') || (streamer[0] > '9')) {
                throw std::range_error("Попытка инициализировать класс некорректной строкой");
            }
        }

        biglong.set_length(new_length);
        biglong.set_max_length(new_length);

        while (streamer[j] != '\0') {
            if ((streamer[j] >= '0') & (streamer[j] <= '9')) {
                std::cout << "заменяю: " << biglong.get_max_length() - new_length + 1 << " на: " << streamer[j] << std::endl;
                biglong.set_one_char(biglong.get_max_length() - new_length + 1, char_to_num(streamer[j]));
                --new_length;
                ++j;
            } else {
                std::cout << "В строке встретился не числовой символ" << std::endl;
                throw std::range_error("В строке встретился не числовой символ");
            }
        }
        return istream;

    }


    Biglong Biglong::operator~() const {
        Biglong newest(*this);
        if ((newest.get_one_char(0) == '9') || (newest.get_one_char(0) == '1')) {
            newest.set_one_char(0, 9);
            for (int i = 1; i <= SZ; ++i) {
                newest.set_one_char(i, 9 - char_to_num(newest.get_one_char(i)));
            }


            int a = 0, ostatok = 1, i = SZ;         //часть с инкрементом
            while ((i > 0) & (ostatok > 0)) {
                a = char_to_num(newest.get_one_char(i));
                a = ostatok + a;
                newest.set_one_char(i, a % 10);
                ostatok = a / 10;
                --i;
            }
            if ((i < 1) & (ostatok != 0)) {
                std::cout << "На вход был подан -0, преобразую его в +0" << std::endl;
                for (int k = 0; k <= SZ; ++k) {
                    newest.set_one_char(k, 0);
                }
            }
        }
        return newest;
    }

    const Biglong Biglong::operator+(const Biglong &argument) const {
        Biglong result(*this);
        int new_length;
        if (result.get_length() >= argument.get_length()) {
            new_length = result.get_length();
            if (result.get_one_char(1) != '0')
                ++new_length;
        } else {
            new_length = argument.get_length();
            if (argument.get_one_char(1) != '0')
                ++new_length;
        }

        Biglong result_copy(result);

        result_copy.free_value();
        result_copy.new_value(new_length + 1);
        result_copy.set_max_length(new_length);
        result_copy.set_one_char(0, char_to_num(result.get_one_char(0)));
        int counter1 = result.get_max_length();
        int result_size = counter1;
        int result_copy_size = result_copy.get_max_length();
        for (int i  = 0; i < result_size; ++i) {
            result_copy.set_one_char(result_copy_size - i, char_to_num(result.get_one_char(counter1)));
            --counter1;
        }

        result_copy = ~result_copy;

        int a = 0, b = 0, over = 0;
        result_copy_size = result_copy.get_max_length();
        Biglong argument_copy (argument);
        argument_copy = ~argument_copy;

        int argument_copy_size = argument_copy.get_max_length();
        for (int i = argument_copy_size; i > 0; --i) {
            a = char_to_num(result_copy.get_one_char(result_copy_size));
            b = char_to_num(argument_copy.get_one_char(i));
            a = a + b + over;
            result_copy.set_one_char(result_copy_size, a % 10);
            over = a / 10;
            --result_copy_size;
        }

        if (argument_copy.get_one_char(0) != '0') {
            for (int i = result_copy_size; i >= 0; --i) {
                a = char_to_num(result_copy.get_one_char(i));
                a = a + 9 + over;
                result_copy.set_one_char(i, a % 10);
                over = a / 10;
            }
        } else {
            if (over != 0) {
                for (int i = result_copy_size; i >= 0; --i) {
                    a = char_to_num(result_copy.get_one_char(i));
                    a = a + over;
                    result_copy.set_one_char(i, a % 10);
                    over = a / 10;
                }
            }
        }


        if (result_copy.get_one_char(0) != '0') {
            result_copy = ~result_copy;
        }

  //      result_copy.clear_spaces();
        return result_copy;


    }



    const Biglong Biglong::operator-(const Biglong &argument) const {
        Biglong argument_copy = argument;
        if (argument.get_one_char(0) == '0')
            argument_copy.set_one_char(0, 9);
        else
            argument_copy.set_one_char(0, 0);
        return (*this + argument_copy);
    }


    void Biglong::clear_spaces (){
        int max_length = (*this).get_max_length();
        int i = 1;
        while ((*this).get_one_char(i) == '0') {
            ++i;
        }
        --i;
        char *new_value = new char[max_length - i + 1];
        new_value[0] = (*this).get_one_char(0);
        for (int j = 1; j <= (max_length - i); ++j) {
            new_value[j] = (*this).get_one_char(j + i);
        }
        (*this).free_value();
        (*this).new_value(max_length - i + 1);
        for (int j = 0; j < (max_length - i + 1); ++j) {
            (*this).set_one_char(j, char_to_num(new_value[j]));
        }
    //    (*this).div10();
    }



    void Biglong::set_one_char(int number, int value) {
        Biglong::value[number] = num_to_char(value);
    }

    void Biglong::set_length(int new_length) {
        try {
            if (new_length < 0)
                throw std::range_error("Неприемлимая длина строки");
            Biglong::length = new_length;
        }
        catch (std::range_error &error){
            std::cerr << error.what() << std::endl;
        }
    }

    void Biglong::set_max_length(int new_max_length) {
        try {
            if (new_max_length < 0)
                throw std::range_error("Неприемлимая длина строки");
            Biglong::SZ = new_max_length;
        }
        catch (std::range_error &error){
            std::cerr << error.what() << std::endl;
        }
    }




    void Biglong::free_value() {
        delete [](*this).value;
    }

    void Biglong::new_value(int count) {
        (*this).value = new char[count];
        for (int i = 0; i < count; ++i) {
            (*this).value[i] = '0';
        }

    }



    Biglong& Biglong::operator=(const Biglong &argument) {
        try {
            free_value();
            new_value(argument.get_max_length());
            set_max_length(argument.get_max_length());
            for (int i = 0; i <= Biglong::SZ; ++i) {
                value[i] = argument.value[i];
            }

            length = argument.length;
            return (*this);
        }
        catch (std::exception &error){
            std::cerr << error.what() << std::endl;
        }

    }
    
    char num_to_char(int num) {
        return num + '0';
    }

    int char_to_num(char char_a) {
        return char_a - '0';
    }


    char *readln(void) {
        fseek(stdin, 0, SEEK_END);
        char *ptr = (char *) malloc(1);
        *ptr = '\0';
        char buf[101];
        int n, len = 0;
        do {
            n = scanf("%100[^\n]", buf);
            if (n < 0) {
                free(ptr);
                ptr = nullptr;
                continue;
            }
            if (n == 0)
                scanf("%*c");
            else {
                len += strlen(buf);
                ptr = (char *) realloc(ptr, len + 1);
                strcat(ptr, buf);
            }
        } while (n > 0);
        return ptr;
    }
}