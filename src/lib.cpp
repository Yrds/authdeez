#include "lib.hpp"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <chrono>
#include <ctime>
#include <sstream>
#include <array>
#include <iomanip>
#include "cppcodec/base32_rfc4648.hpp"




std::string toHexString(std::basic_string<unsigned char> string) {
  std::stringstream ss;
  for(const auto &item : string) {
    ss << std::setfill('0') << std::setw(2) << std::hex << int(item);
  }

  return ss.str();
};

std::basic_string<unsigned char> hmac_sha1(
    std::string key, std::basic_string<unsigned char> data) {
  unsigned int hash_len;


  const unsigned char *result = {
      HMAC(EVP_sha1(), key.c_str(), static_cast<int>(key.size()), data.data(),
           static_cast<int>(data.size()), NULL, &hash_len)};

  return std::basic_string<unsigned char>{result, hash_len};
}

std::string HOTP(std::string key, std::basic_string<unsigned char> data, int bin_code_size) {

  if(data.size() != 8) {
    throw(std::length_error("Counter must be 8 bytes wide"));
  }

  auto result = hmac_sha1(key, data);

  int offset = result[19] & 0xf;

  int bin_code = (
      (result.at(offset) & 0x7f) << 24 |
      (result.at(offset+1) & 0xff) << 16 |
      (result.at(offset+2) & 0xff) << 8 |
      (result.at(offset+3) & 0xff)
      );

  std::string bin_code_str = std::to_string(bin_code);

  return bin_code_str.substr(bin_code_str.size() - bin_code_size, bin_code_size);
}


int64_t getUnixEpochTimeStamp() {
  return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

//TODO change this parameter to Account
std::string TOTP(std::string key, int bin_code_size, long long interval) {
  return TOTP(key, getUnixEpochTimeStamp(), bin_code_size, interval);
}

std::string TOTP(std::string key, uint64_t time, int bin_code_size, long long interval) {
  std::cout << "Time " << time << std::endl;
  uint64_t frame_time = std::floor(time/interval);

  std::basic_string<unsigned char> counter = {0, 0, 0, 0, 0, 0, 0, 0};
  counter[4] = (frame_time >> 24) & 0xFF;
  counter[5] = (frame_time >> 16) & 0xFF;
  counter[6] = (frame_time >> 8) & 0xFF;
  counter[7] = (frame_time) & 0xFF;

  //TODO add conditionally decoding base32 ex. if Account is base32
  using base32 = cppcodec::base32_rfc4648;

  auto key_decoded = base32::decode<std::string>(key);

  return HOTP(key_decoded, counter, bin_code_size);
}

std::string TOTP(const Account& account, uint64_t time) {
  uint64_t frame_time = std::floor(time/account.interval);

  std::basic_string<unsigned char> counter = {0, 0, 0, 0, 0, 0, 0, 0};
  counter[4] = (frame_time >> 24) & 0xFF;
  counter[5] = (frame_time >> 16) & 0xFF;
  counter[6] = (frame_time >> 8) & 0xFF;
  counter[7] = (frame_time) & 0xFF;

  using base32 = cppcodec::base32_rfc4648;

  return HOTP(
      account.b32 ? base32::decode<std::string>(account.key) : account.key,
      counter, account.code_size);
}

std::string TOTP(const Account& account) {
  return TOTP(account, getUnixEpochTimeStamp());
}


std::vector<Account> accountsFromTxtFile(std::ifstream file) {

  std::vector<Account> accounts;
  std::string line;
  while(std::getline(file, line)) {
    auto tokens = StringUtils::split(line, "||");
    if(tokens.size() >= 2) {
      Account account;
      account.name = tokens[0];
      account.key = tokens[1];
      accounts.push_back(account);
    }

  }

  return accounts;
}


namespace StringUtils {
std::vector<std::string> split(std::string text, std::string delimiter) {

  std::string::size_type n = 0;

  std::vector<std::string> tokens;

  while (n != std::string::npos) {
    n = text.find(delimiter);
    tokens.push_back(text.substr(0,n));
    text = text.substr(n+delimiter.size());
  }

  return tokens;
}

}
