#pragma once

#include <fstream>
#include <string_view>
constexpr std::string_view ERROR_LEVEL = "ERROR";
constexpr std::string_view WARNING_LEVEL = "WARNING";
constexpr std::string_view NOTICE_LEVEL = "NOTICE";

#define DEFAULT_PATH "./"
std::ofstream *mylog_init(std::string_view name,
                          std::string_view path = DEFAULT_PATH);
void mylog_add(std::ofstream *fptr, std::string_view head,
               std::string_view content);
void mylog_destroy(std::ofstream *fptr);
