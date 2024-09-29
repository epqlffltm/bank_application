#pragma once
#ifndef USER_H
#define USER_H

#include <string>

struct new_user
{
    std::string user_number; // 고객 번호
    std::string user_name;   // 고객 이름
    std::string user_account;// 계좌 번호
    int user_money;          // 금액
    bool user_join;          // 가입 유무
};

class User
{
public:
    static new_user user_create(std::string user_number, std::string user_name, std::string user_account, int user_money, bool user_join);
    static void user_array(new_user* us, new_user* pary, int* index);
    static void select(new_user* pary, int size);
    static void deposit(new_user& u, int amount);
    static void withdraw(new_user& u, int amount);
};

#endif // USER_H
