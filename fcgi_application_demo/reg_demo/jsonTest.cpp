#include "Rjson.h"
#include "print.h"
#include <iostream>
#include <string_view>
int main(int argc, char *argv[]) {
  std::string_view str = R"({"user":"reisen,"passwd":132131})";
  auto res = parse(str);
  print(res);
  return 0;
}
