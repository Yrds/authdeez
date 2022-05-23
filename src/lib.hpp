#ifndef LIB_INCLUDED
#define LIB_INCLUDED

#include "openssl/hmac.h"
#include "openssl/evp.h"
#include <fstream>
#include <string>
#include <vector>


namespace StringUtils {
std::vector<std::string> split(std::string text, std::string delimiter);
}

struct Account {
  std::string name;
  std::string key;
  int code_size = 6;
  bool b32 = true;
  bool totp = true;
  int interval = 30;
};

std::basic_string<unsigned char> hmac_sha1(std::string key, std::basic_string<unsigned char> data);
std::string HOTP(std::string key, std::basic_string<unsigned char> data, int bin_code_size = 6); 
int64_t getUnixEpochTimeStamp();
std::string TOTP(std::string key, int size = 6, long long interval = 30.0l);
std::string TOTP(std::string key, uint64_t time, int size = 6, long long interval = 30.0l);
std::string TOTP(const Account& account);
std::string TOTP(const Account& account, uint64_t time);
//TODO std::string getCode(Account& acount); 
std::string toHexString(std::basic_string<unsigned char> string);
//TODO Account accountFromUrl(std::string url);
std::vector<Account> accountsFromTxtFile(std::ifstream file);

#endif //LIB_INCLUDED
