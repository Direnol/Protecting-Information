//
// Created by direnol on 05.11.18.
//

#ifndef PROTECTION_INFORMATION_METALPOKER_H
#define PROTECTION_INFORMATION_METALPOKER_H

#include <MentalPlayer.h>

class MentalPoker {
private:
    Operation op;
    std::vector<MentalCard> cards;
    std::vector<MentalPlayer> players;
    uint64_t P;
public:
    MentalPoker(const uint64_t count_player, const uint64_t P = 0, const uint64_t count_card = 52);
    std::pair<std::vector<MentalPlayer>, std::vector<MentalCard>> game();
};

#endif //PROTECTION_INFORMATION_METALPOKER_H
