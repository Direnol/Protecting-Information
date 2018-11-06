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
    uint64_t card;
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
        os << card.card;
        return os;
    }

    void setCard(uint64_t card)
    {
        this->card = card;
    }

};


#endif //PROTECTION_INFORMATION_MENTALCARD_H
