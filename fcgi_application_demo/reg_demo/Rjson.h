#include "print.h"
#include <charconv>
#include <cstddef>
#include <iostream>
#include <optional>
#include <regex>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>
struct JsonObj;
using jsonObjcet = std::unordered_map<std::string, JsonObj>;
using jsonArray = std::vector<JsonObj>;

struct JsonObj {
  // json对象
  std::variant<std::monostate, // null
               int,            // 35
               bool,           // true
               double,         // 3.14
               std::string,    //"reisen "
               jsonArray,      //[3,4,"dsad"]  Json数组
               jsonObjcet      //{"hello":"world","PI",3.14}
               >
      inner;
  void do_print() const { printnl(inner); }
  template <class T> bool is() const {
    // 判断文件类型
    return std::holds_alternative<T>(inner);
  }

  template <class T> T &get() { return std::get<T>(inner); }

  template <class T> T const &get() const { return std::get<T>(inner); }
};
template <class T> static std::optional<T> try_parse_num(std::string_view str) {
  T value;
  // 将str转为数字
  auto res = std::from_chars(str.data(), str.data() + str.size(), value);
  if (res.ec == std::errc() && res.ptr == str.data() + str.size()) {
    // 这里不仅要判定是否正常返回，还要判定是否全部转换
    // 因为如果在对double调用该函数时错选择了int模板，会导致只转换整数部分
    return value;
  }
  return std::nullopt;
}

std::pair<JsonObj, size_t> parse(std::string_view str);
