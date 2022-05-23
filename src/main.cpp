#include "lib.hpp"
#include <vector>
#include <iostream>

int main(const int argc, const char* argv[])
{

  std::vector<Account> accounts = accountsFromTxtFile(std::ifstream("accounts.txt"));

  for(const auto &account: accounts) {
    auto code = TOTP(account);
    std::cout << account.name << ": " << code << std::endl;
  }

  return 0;
}
