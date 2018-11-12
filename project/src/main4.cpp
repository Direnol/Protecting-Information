//
// Created by direnol on 05.11.18.
//


#include <MetalPoker.h>

int main()
{
    uint64_t n;
    std::cout << "Enter count of player" << std::endl;
    std::cin >> n;
    MentalPoker poker(n);
    auto [players, desk] = poker.game();
    std::cout << "Table: ";
    for (auto &c: desk) {
        std::cout << c << ' ';
    }
    std::cout << std::endl << "Players:" << std::endl;
    for (auto i = 0; i < players.size(); ++i) {
        std::cout << 'P' << i << ": " << players[i] << std::endl;
    }
}