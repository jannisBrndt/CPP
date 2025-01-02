#include <gtest/gtest.h>
#include <string>
#include "my_header.h"

TEST(MyHeaderTest, CheckGreeting) {
   std::string name = "jannis";

   EXPECT_EQ(greeting(name), "Hello jannis!");
}
