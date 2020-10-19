//
// Created by Данил Морозов on 19/10/2020.
//

#include <gtest/gtest.h>
#include "biglong.h"


//конструкторы

TEST (BLConstructors, byEmpty)
{
    laba3bit1::Biglong a;
    ASSERT_EQ(0, a.get_length());

}


TEST (BLConstructors, byLong)
{
    long l = 1000;
    int g;
    g = l % 10;
    laba3bit1::Biglong a (l);
    for (int i = laba3bit1::MAX_LENGTH; i > 0; --i) {
        ASSERT_EQ(g, laba3bit1::char_to_num(a.get_one_char(i)));
        l = l / 10;
        g = l % 10;
    }
}

TEST (BLConstructors, ErrbyLong)
{
    long l = 10000000000;
    ASSERT_ANY_THROW(laba3bit1::Biglong a(l));
}

TEST (BLConstructors, ErrbyNotNum)
{
    ASSERT_ANY_THROW(laba3bit1::Biglong a("char23"));
}

TEST (BLConstructors, ErrRandomMinus)
{
    ASSERT_ANY_THROW(laba3bit1::Biglong a("132-213"));
}

TEST (BLConstructors, CopyConstr)
{
    laba3bit1::Biglong a(-213213);
    laba3bit1::Biglong b(a);
    for (int i = laba3bit1::MAX_LENGTH; i > 0; --i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}


//геттеры


TEST (BLGetters, GetOneChar)
{
    laba3bit1::Biglong a(-213213);
    ASSERT_EQ((3 + '0') , a.get_one_char(laba3bit1::MAX_LENGTH));
}

TEST (BLGetters, GetLength)
{
    laba3bit1::Biglong a(-213213);
    ASSERT_EQ( 6 , a.get_length());
}

TEST (BLGetters, GetMaxLength)
{
    laba3bit1::Biglong a(-213213);
    ASSERT_EQ(laba3bit1::MAX_LENGTH, a.get_max_length());
}

//сеттеры

TEST (BLSetters, SetOneChar)
{
    laba3bit1::Biglong a(-213213);
    a.set_one_char(5, 5);
    ASSERT_EQ(5 + '0' , a.get_one_char(5));
}

TEST (BLSetters, SetLength)
{
    laba3bit1::Biglong a(-213213);
    a.set_length(21);
    ASSERT_EQ( 21 , a.get_length());
}

TEST (BLSetters, div10)
{
    laba3bit1::Biglong a(-213213);
    a.div10();
    ASSERT_EQ(1 + '0' , a.get_one_char(laba3bit1::MAX_LENGTH));
}

TEST (BLSetters, multi10)
{
    laba3bit1::Biglong a(-213213);
    a.multi10();
    ASSERT_EQ( 2 + '0', a.get_one_char(laba3bit1::MAX_LENGTH - a.get_length()));
}


//методы

TEST (BLMethods, PlusAdditCode)
{
    laba3bit1::Biglong a(213213);
    laba3bit1::Biglong b(213213);
    b = b.get_addit_code();
    for (int i = laba3bit1::MAX_LENGTH; i > 0; --i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}

TEST (BLMethods, MinuAdditCode)
{
    laba3bit1::Biglong a(-25);
    laba3bit1::Biglong b(-9999999976);
    b = b.get_addit_code();
    for (int i = laba3bit1::MAX_LENGTH; i > 0; --i) {
        ASSERT_EQ(b.get_one_char(i), a.get_one_char(i));
    }
}













int _tmain(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}