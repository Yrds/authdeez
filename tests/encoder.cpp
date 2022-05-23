#include <gtest/gtest.h>
#include "cppcodec/base32_rfc4648.hpp"


TEST(ENCODER, ENCODE_BASE_32) {
  using base32 = cppcodec::base32_rfc4648;

  std::string expected = { 72, 101, 108, 108, 111, 33, -34, -83, -66, -17 };

  EXPECT_EQ(base32::decode<std::string>("JBSWY3DPEHPK3PXP"), expected);

}

