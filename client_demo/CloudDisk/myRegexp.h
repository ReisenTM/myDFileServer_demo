#ifndef MYREGEXP_H
#define MYREGEXP_H

//注册用正则表达式
#define USERNAME_REG        "^[a-zA-Z0-9_]{3,16}$"
#define PASS_REG            "^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d@#$%^&*]{6,20}$"
#define EMAIL_REG           "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"
#define PHONE_REG           "^1[3-9]\\d{9}$"
#define NICKNAME_REG        "^[^0-9][a-zA-Z0-9_\u4e00-\u9fa5]{1,15}$"

//状态码
#define CORRECT_STAT    "002"
#define EXISTED_STAT    "003"
#define ERROR_STAT      "004"
#endif // MYREGEXP_H
