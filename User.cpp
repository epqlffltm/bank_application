#include "User.h"
#include <iostream>

new_user User::user_create(std::string user_number, std::string user_name, std::string user_account, int user_money, bool user_join)
{
    new_user customer;
    customer.user_number = user_number;
    customer.user_name = user_name;
    customer.user_account = user_account;
    customer.user_money = user_money;
    customer.user_join = user_join;

    return customer;
}

void User::user_array(new_user* us, new_user* pary, int* index)
{
    pary[*index] = *us;
}

void User::select(new_user* pary, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (pary[i].user_join)
        {
            std::cout << pary[i].user_number << " | " << pary[i].user_name << " | " << pary[i].user_account << " | " << pary[i].user_money << std::endl;
        }
    }
}

void User::deposit(new_user& u, int amount)
{
    u.user_money += amount;
}

void User::withdraw(new_user& u, int amount)
{
    u.user_money >= amount ? u.user_money -= amount : printf("잔액이 부족합니다.\n");
}
