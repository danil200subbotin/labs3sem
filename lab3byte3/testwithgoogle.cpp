//
// Created by Данил Морозов on 01/11/2020.
//

//
// Created by Данил Морозов on 19/10/2020.
//

#include <gtest/gtest.h>
#include "biglong.h"


//конструкторы

TEST (BLConstructors, byEmpty)
{
    laba3bit3::Biglong a;
    ASSERT_EQ(0, a.get_length());

}


TEST (BLConstructors, byLong)
{
    long l = 1000;
    int g;
    g = l % 10;
    laba3bit3::Biglong a (l);
    for (int i = a.get_max_length(); i > 0; --i) {
        ASSERT_EQ(g, laba3bit3::char_to_num(a.get_one_char(i)));
        l = l / 10;
        g = l % 10;
    }
}

TEST (BLConstructors, ErrbyLong)
{
    long l = 10000000000;
    ASSERT_NO_THROW(laba3bit3::Biglong a(l));
}

TEST (BLConstructors, ErrbyNotNum)
{
    ASSERT_ANY_THROW(laba3bit3::Biglong a("char23"));
}

TEST (BLConstructors, ErrRandomMinus)
{
    ASSERT_ANY_THROW(laba3bit3::Biglong a("132-213"));
}

TEST (BLConstructors, CopyConstr)
{
    laba3bit3::Biglong a(-213213);
    laba3bit3::Biglong b(a);
    for (int i = a.get_max_length(); i > 0; --i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}


//геттеры


TEST (BLGetters, GetOneChar)
{
    laba3bit3::Biglong a(-213213);
    ASSERT_EQ((3 + '0') , a.get_one_char(a.get_max_length()));
}

TEST (BLGetters, GetLength)
{
    laba3bit3::Biglong a(-213213);
    ASSERT_EQ( 6 , a.get_length());
}

TEST (BLGetters, GetMaxLength)
{
    laba3bit3::Biglong a(-213213);
    ASSERT_EQ(6, a.get_max_length());
}

//сеттеры

TEST (BLSetters, SetOneChar)
{
    laba3bit3::Biglong a(-213213);
    a.set_one_char(5, 5);
    ASSERT_EQ(5 + '0' , a.get_one_char(5));
}

TEST (BLSetters, SetLength)
{
    laba3bit3::Biglong a(-213213);
    a.set_length(21);
    ASSERT_EQ( 21 , a.get_length());
}

TEST (BLSetters, div10minus)
{
    laba3bit3::Biglong a(-213213);
    a.div10();
    ASSERT_EQ(1 + '0' , a.get_one_char(a.get_max_length()));
}

TEST (BLSetters, multi10minus)
{
    laba3bit3::Biglong a(-213213);
    a.multi10();
    ASSERT_EQ( 0 + '0', a.get_one_char(7));
}

TEST (BLSetters, div10plus)
{
    laba3bit3::Biglong a(213213);
    a.div10();
    ASSERT_EQ(1 + '0' , a.get_one_char(a.get_max_length()));
}

TEST (BLSetters, multi10plus)
{
    laba3bit3::Biglong a(213213);
    a.multi10();
    ASSERT_EQ( 2 + '0', a.get_one_char(1));
}

//методы

TEST (BLMethods, PlusAdditCode)
{
    laba3bit3::Biglong a(213213);
    laba3bit3::Biglong b(213213);
    b = ~b;
    for (int i = a.get_max_length(); i > 0; --i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}

TEST (BLMethods, MinuAdditCode)
{
    laba3bit3::Biglong a(-25);
    // a.print(std::cout);
    laba3bit3::Biglong b(-75);
    std::cout << a.get_one_char(0);
    a = ~a;
    //  a.print(std::cout);
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}


TEST (BLMethods, plusPlusplus)
{
    laba3bit3::Biglong a(265);
    // a.print(std::cout);
    laba3bit3::Biglong b(125);
    char z[] = {'0', '0', '3','9', '0'};
    a = a + b;
    int g = a.get_max_length();
    for (int i = 0; i <= g -1; ++i) {
  //      std::cout << "aaaaa" << g << "aaaaaaa" << std::endl;
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}


TEST (BLMethods, plusPlusminus)
{
    laba3bit3::Biglong a(25);
    // a.print(std::cout);
    laba3bit3::Biglong b(-12);
    laba3bit3::Biglong c(13);
    char z[] = {'0', '0', '1','3'};
    a = a + b;
    for (int i = 1; i <= a.get_max_length() - 1; ++i) {
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}

TEST (BLMethods, plusPlusminus2)
{
    laba3bit3::Biglong a(25);
    // a.print(std::cout);
    laba3bit3::Biglong b(-29);
    laba3bit3::Biglong c(-4);
    char z[] = {'9', '0', '0','4'};
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}


TEST (BLMethods, plusPlusminus3)
{
    laba3bit3::Biglong a(25);
    // a.print(std::cout);
    laba3bit3::Biglong b(-25);
    laba3bit3::Biglong c;
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), c.get_one_char(i));
    }
}

//-----------------------------------------------------------------------------------------------

TEST (BLMethods, minusPlusplus)
{
    laba3bit3::Biglong a(-25);
    // a.print(std::cout);
    laba3bit3::Biglong b(12);
    laba3bit3::Biglong c(-13);
    char z[] = {'9', '0', '1','3'};
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}


TEST (BLMethods, minusPlusminus)
{
    laba3bit3::Biglong a(-25);
    // a.print(std::cout);
    laba3bit3::Biglong b(-12);
    laba3bit3::Biglong c(-37);
    char z[] = {'9', '0', '3','7'};
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}

TEST (BLMethods, minusPlusplus2)
{
    laba3bit3::Biglong a(-25);
    // a.print(std::cout);
    laba3bit3::Biglong b(29);
    laba3bit3::Biglong c(4);
    char z[] = {'0', '0', '0','4'};
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), z[i]);
    }
}

TEST (BLMethods, MINUS_IS_A_NEW_PLUS)
{
    laba3bit3::Biglong a(25);
    laba3bit3::Biglong b(29);
    laba3bit3::Biglong c(25);
    laba3bit3::Biglong d(-29);
    a = a - b;
    c = c + d;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), c.get_one_char(i));
    }
}

TEST (BLMethods, SetOneChar)
{
    laba3bit3::Biglong a(9999999989);
    laba3bit3::Biglong b(9999999999);
    a.set_one_char(9, 9);
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), b.get_one_char(i));
    }
}

TEST (BLMethods, SetLength)
{
    laba3bit3::Biglong a(9999999989);
    a.set_length(2);
    ASSERT_EQ(2, a.get_length());
}


TEST (BLMethods, minusPlusplus3)
{
    laba3bit3::Biglong a(-25);
    // a.print(std::cout);
    laba3bit3::Biglong b(25);
    laba3bit3::Biglong c;
    a = a + b;
    for (int i = 1; i <= a.get_max_length(); ++i) {
        ASSERT_EQ(a.get_one_char(i), c.get_one_char(i));
    }
}

int _tmain(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


