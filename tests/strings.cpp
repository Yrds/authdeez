#include "lib.hpp"
#include <gtest/gtest.h>

TEST(STRING_SPLIT, SPLIT_TEXT) {
  auto tokens = StringUtils::split("hi;bye", ";");

  EXPECT_EQ(tokens.size(), 2);
  EXPECT_EQ(tokens[0], "hi");
  EXPECT_EQ(tokens[1], "bye");
}

TEST(STRING_SPLIT, SPLIT_TEXT_2) {
  auto tokens = StringUtils::split("one||two||three", "||");

  EXPECT_EQ(tokens.size(), 3);
  EXPECT_TRUE(tokens[0] == "one");
  EXPECT_TRUE(tokens[1] == "two");
  EXPECT_TRUE(tokens[2] == "three");
}
