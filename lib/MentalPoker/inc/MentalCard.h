//
// Created by direnol on 05.11.18.
//

#ifndef PROTECTION_INFORMATION_MENTALCARD_H
#define PROTECTION_INFORMATION_MENTALCARD_H

#include <stdint.h>
#include <vector>
#include <ostream>
#include <sstream>
#include <iostream>
#include <Operation.h>
#include <ostream>
#include <stdint-gcc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <vector>
#include <algorithm>

class MentalCard {
    int64_t card;
public:
    uint64_t getCard() const
    {
        return card;
    }

public:
    explicit MentalCard(uint64_t card) : card(card)
    {}

    MentalCard() = default;

    static void shuffle(std::vector<MentalCard> &cards)
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);

    }

    // TODO: Mapping cards
    // example: 15 -> Tuz B; 21 -> Tus K ...
    friend std::ostream &operator<<(std::ostream &os, const MentalCard &card)
    {
        std::map<uint64_t, std::string> map;
        map[0] = "TP";
        map[1] = "2B";
        map[2] = "3B";
        map[3] = "4B";
        map[4] = "5B";
        map[5] = "6B";
        map[6] = "7B";
        map[7] = "8B";
        map[8] = "9B";
        map[9] = "10B";
        map[10] = "VB";
        map[11] = "DB";
        map[12] = "KB";
        map[13] = "TB";
        map[14] = "TK";
        map[15] = "2C";
        map[16] = "3C";
        map[17] = "4C";
        map[18] = "5C";
        map[19] = "6C";
        map[20] = "7C";
        map[21] = "8C";
        map[22] = "9C";
        map[23] = "10C";
        map[24] = "VC";
        map[25] = "DC";
        map[26] = "KC";
        map[27] = "TC";
        map[28] = "2K";
        map[29] = "3K";
        map[30] = "4K";
        map[31] = "5K";
        map[32] = "6K";
        map[33] = "7K";
        map[34] = "8K";
        map[35] = "9K";
        map[36] = "10K";
        map[37] = "VK";
        map[38] = "DK";
        map[39] = "KK";
        map[40] = "2P";
        map[41] = "3P";
        map[42] = "4P";
        map[43] = "5P";
        map[44] = "6P";
        map[45] = "7P";
        map[46] = "8P";
        map[47] = "9P";
        map[48] = "10P";
        map[49] = "VP";
        map[50] = "DP";
        map[51] = "KP";
        os << map[card.card];
        return os;
    }

    void setCard(int64_t card)
    {
        this->card = card;
    }

};


#endif //PROTECTION_INFORMATION_MENTALCARD_H
