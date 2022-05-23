#include <lib.hpp>
#include <gtest/gtest.h>

TEST(HOTP, HOTP_BIN_CODE) {

  std::string key = { 72, 101, 108, 108, 111, 33, -34, -83, -66, -17 };
  std::basic_string<unsigned char> counter_bytes{0, 0, 0, 0, 3, 72, 205, 50};

  std::cout << "counter bytes size:" << counter_bytes.size() << std::endl;

  EXPECT_EQ(HOTP(key, counter_bytes, 6), "938981");
}

TEST(TOTP, TOTP_B32_ACCOUNT) {
  Account account {
    "Tester",
    "JBSWY3DPEHPK3PXP",
    6, true, true,  //code_size, b32, totp
    30 //interval
  };

  uint64_t time = 1653332813;

  EXPECT_EQ(TOTP(account, time), "985845");
}

TEST(TOTP, TOTP_NO_DECODED_ACCOUNT) {

  Account account {
    "No decoded account",
    { 72, 101, 108, 108, 111, 33, -34, -83, -66, -17 },
    6, false, true,  //code_size, b32, totp
    30 //interval
  };

  uint64_t time = 1653333014;

  EXPECT_EQ(TOTP(account, time), "259495");
}
