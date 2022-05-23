#include "lib.hpp"
#include <iostream>

int main(const int argc, const char* argv[])
{

  std::ifstream accountsFile("accounts.txt") ;

  if (accountsFile.good()) {
    auto accounts = accountsFromTxtFile(accountsFile);

    for (const auto& account : accounts) {
      auto code = TOTP(account);
      std::cout << account.name << ": " << code << std::endl;
    }
  } else {
    std::cerr << "File 'accounts.txt' not found. You need to create one(ex. ACCOUNT||KEY) in order to work" << std::endl;;
  }

  return 0;
}
