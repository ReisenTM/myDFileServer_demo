#include "Rjson.h"
#include <charconv>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#define BUFSIZE 4096

struct json_info_st {
  std::string_view username;
  std::string_view passwd;
};

// 解析请求

/**
 * @brief 读取 HTTP 请求正文，自动跳过头部部分（直到空行）
 *
 * @return std::optional<std::string_view> 返回正文字符串视图，若失败返回
 * nullopt
 */
std::optional<std::string_view> read_http_body() {
  if (const char *len_str = std::getenv("CONTENT_LENGTH"); len_str) {
    size_t content_length = 0;
    auto [ptr, ec] = std::from_chars(len_str, len_str + std::strlen(len_str),
                                     content_length);

    if (ec == std::errc() || ptr == len_str + std::strlen(len_str)) {
      auto buffer =
          std::make_unique<char[]>(content_length + 1); // 多一字节放 '\0'
      size_t read_len = std::fread(buffer.get(), 1, content_length, stdin);
      if (read_len != content_length)
        return std::nullopt;
      buffer[read_len] = '\0';

      // 查找 HTTP 头部和正文之间的空行分隔符
      std::string_view all_data(buffer.get(), read_len);
      constexpr std::string_view delim = "\r\n\r\n";
      size_t pos = all_data.find(delim);

      if (pos != std::string_view::npos) {
        return all_data.substr(pos + delim.size()); // 跳过分隔符，返回正文部分
      } else {
        // 如果没有找到头部，可能是纯正文（例如 POST JSON）
        return all_data;
      }
    }
  }
  return std::nullopt;
}
// 解析请求里的json
json_info_st *getJson(std::string_view content) {
  auto [json, size] = parse(content);
  json_info_st *userInfo = nullptr;
  if (auto info = std::get_if<jsonObjcet>(&json.inner)) {
    auto user = info->at("username");
    auto pass = info->at("passwd");
    json_info_st *userinfo =
        new json_info_st{user.get<std::string>(), pass.get<std::string>()};
  }
  return userInfo;
}
// 查询数据库
void addUserIfNotExists(MYSQL *conn, const json_info_st &info) {
  std::string username = info.username.data();
  std::string password = info.passwd.data();
  // 查询数据库中是否存在该用户名
  std::string query =
      "SELECT COUNT(*) FROM users WHERE username = '" + username + "'";
  if (mysql_query(conn, query.c_str())) {
    std::cerr << "查询失败: " << mysql_error(conn) << std::endl;
    return;
  }

  MYSQL_RES *res = mysql_store_result(conn);
  if (!res) {
    std::cerr << "获取结果失败: " << mysql_error(conn) << std::endl;
    return;
  }

  MYSQL_ROW row = mysql_fetch_row(res);
  int count = atoi(row[0]);

  // 如果不存在，则插入新用户
  if (count == 0) {
    std::string insert_query =
        "INSERT INTO users (username, password) VALUES ('" + username + "', '" +
        password + "')";
    if (mysql_query(conn, insert_query.c_str())) {
      std::cerr << "插入失败: " << mysql_error(conn) << std::endl;
    } else {
      std::cout << "用户添加成功: " << username << std::endl;
    }
  } else {
    std::cout << "已存在: " << username << std::endl;
  }

  mysql_free_result(res);
}
int main(int argc, char *argv[]) {
  // 先获取请求
  MYSQL *conn = mysql_init(NULL);
  if (mysql_real_connect(conn, "localhost", "your_username", "your_password",
                         "your_database", 0, NULL, 0) == NULL) {
    std::cerr << "mysql_real_connect() failed\n";
    mysql_close(conn);
    return EXIT_FAILURE;
  }
  while (FCGI_Accpet() >= 0) {
    auto content = read_http_body();
    auto info = getJson(content.value());
    if (conn == NULL) {
      std::cerr << "mysql_init() failed\n";
      return EXIT_FAILURE;
    }
    // 连接到数据库
    addUserIfNotExists(conn, info);
    // 关闭连接
  }

  mysql_close(conn);
  return EXIT_SUCCESS;
}
