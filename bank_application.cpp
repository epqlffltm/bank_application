#include <iostream>
#include<string>

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
    static new_user user_create(std::string user_number, std::string user_name, std::string user_account, int user_money, bool user_join) 
    {
        new_user customer;
        customer.user_number = user_number;
        customer.user_name = user_name;
        customer.user_account = user_account;
        customer.user_money = user_money;
        customer.user_join = user_join;

        return customer;
    }

    static void user_array(new_user* us, new_user* pary, int* index) 
    {
        pary[*index] = *us;
    }

    static void select(new_user* pary, int size) 
    {
        for (int i = 0; i < size; ++i) 
        {
            if (pary[i].user_join) 
            {
                std::cout << pary[i].user_number << " | " << pary[i].user_name << " | " << pary[i].user_account << " | " << pary[i].user_money << std::endl;
            }
        }
    }

    static void deposit(new_user& u, int amount) 
    {
        u.user_money += amount;
    }

    static void withdraw(new_user& u, int amount) 
    {
        u.user_money >= amount ? u.user_money -= amount : printf("잔액이 부족합니다.\n");
    }
};

int main(void) 
{
    int n = 0, money, index = 0;
    std::string name, number;

    new_user* pary = new new_user[100];

    while (true) 
    {
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "1. 계좌 생성 | 2. 계좌 목록 | 3. 예금 | 4. 출금 | 5. 종료" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;

        std::cin >> n;

        switch (n) 
        {
        case 1: 
        {
            std::cout << "고객 이름: ";
            std::cin >> name;
            std::cout << "계좌 번호: ";
            std::cin >> number;
            std::cout << "입금 금액: ";
            std::cin >> money;

            new_user us = User::user_create(std::to_string(index + 1), name, number, money, true);
            User::user_array(&us, pary, &index);

            ++index;
            break;
        }
        case 2:
            User::select(pary, index);
            break;
        case 3: 
            {
            std::cout << "예금할 사용자 번호: ";

            std::cin >> number;

            std::cout << "금액: ";

            std::cin >> money;

            for (int i = 0; i < index; ++i) 
            {
                if (pary[i].user_number == number) 
                {
                    User::deposit(pary[i], money);

                    break;
                }
            }
            break;
        }
        case 4: 
            {
            std::cout << "출금할 사용자 번호: ";
            std::cin >> number;
            std::cout << "금액: ";
            std::cin >> money;
            for (int i = 0; i < index; ++i) 
            {
                if (pary[i].user_number == number) 
                {
                    User::withdraw(pary[i], money);

                    break;
                }
            }
            break;
        }
        case 5:
            std::cout << "시스템을 종료합니다" << std::endl;
            delete[] pary;

            return 0;

        default:

            std::cout << "번호를 잘못 입력하셨습니다." << std::endl;

            continue;
        }
    }
}
