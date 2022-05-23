#include "lib.hpp"
#include <sstream>
using namespace std;

#include <gtest/gtest.h>

TEST(HMAC, HMAC_DIGEST_SHA1) {
  std::basic_string<unsigned char> hmac_digest = 
    hmac_sha1("key", reinterpret_cast<const unsigned char*>("The quick brown fox jumps over the lazy dog")).c_str();

  EXPECT_EQ(hmac_digest.length(), 20);
  EXPECT_EQ(toHexString(hmac_digest), "de7c9b85b8b78aa6bc8a7a36f70a90701c9db4d9");
}

TEST(HMAC, HMAC_DIGEST_SHA1_TEST2) {

  std::basic_string<unsigned char> hmac_digest = 
    hmac_sha1("Fornite", reinterpret_cast<const unsigned char*>("Babagi")).c_str();

  EXPECT_EQ(hmac_digest.length(), 20);
  EXPECT_EQ(toHexString(hmac_digest), "a62e14d2affcc5b1ebf96f56cb178cf0fb532fa5");
}
