#include <iostream>
#include <string>
#include "User.h"

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
