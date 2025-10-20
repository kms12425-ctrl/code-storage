#include <gtest/gtest.h>
#include "sut.hpp"
TEST(Hello, should_get_world)
{
    int actual = SutAdd(1, 1);
    EXPECT_EQ(actual, 2);
}