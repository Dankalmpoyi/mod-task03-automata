#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(0);
    coffee.choise(1);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test2)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.choise(1);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test3)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(20);
    coffee.choise(1);
    int result = coffee.finish();
    EXPECT_EQ(10, result);
}

