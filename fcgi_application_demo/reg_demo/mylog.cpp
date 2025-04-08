#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <variant>
#define DEBUG
#define DEFAULT_PATH "./"

// log初始化
std::ofstream *mylog_init(std::string_view logName,
                          std::string_view logPath = DEFAULT_PATH) {
  std::string str;
  str.reserve(logName.size() + logPath.size());
  str.append(logPath);
  str.append(logName);
#ifdef DEBUG
  std::cout << "path:" << str << " " << std::endl;
#endif // DEBUG
  std::ofstream *outFile =
      new std::ofstream(logName, std::ios::app | std::ios::binary);
  return outFile;
}

// log 写
void mylog_add(std::ofstream *myfs, std::string_view level,
               std::string_view content) {
  std::ofstream *s = myfs;
  std::string logInfo;
  logInfo.reserve(level.size() + content.size());
  std::stringstream ss;
  ss << '[' << level << ']' << ':' << content;
  ss >> logInfo;
  *s << logInfo << std::endl;
}
// log结束

void mylog_destroy(std::ofstream *myfs) {
  myfs->close();
  delete myfs;
}
