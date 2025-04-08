#include "mylog.h"
#include <iostream>

int main(int argc, char *argv[]) {
  auto log = mylog_init("logtest");
  mylog_add(log, ERROR_LEVEL, "test");
  mylog_destroy(log);
  return 0;
}
