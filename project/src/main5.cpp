//
// Created by direnol on 12.11.18.
//

#include <cstdint>
#include <DigitalMoney.h>

int main() {
    int64_t my_amount_many, amount_customer;
    DigitalMoney digitalMoney;
    std::cout << "Введите жаждующую сумму денег в рублях" << std::endl;
    std::cin >> my_amount_many;

    while (true) {
        std::cout << "Сумма платежа" << std::endl;
        std::cin >> amount_customer;
        if (amount_customer <= my_amount_many && amount_customer > 0 ) {
            my_amount_many -= amount_customer;
            digitalMoney.list_many(amount_customer);
        } else {
            break;
        }
    }
    return 0;
}