//
// Created by direnol on 05.11.18.
//

#ifndef PROTECTION_INFORMATION_MENTALPLAYER_H
#define PROTECTION_INFORMATION_MENTALPLAYER_H


#include <MentalCard.h>




class MentalPlayer {
    Operation op;
    int64_t c{}; // секретное число
    int64_t d{}; // секретное число
    std::pair<MentalCard, MentalCard> cards;
public:
    MentalPlayer() = default;

    explicit MentalPlayer(uint64_t F)
    {
        auto [C, D] = op.getCD(0, F);
        this->c = C;
        this->d = D;
    }


    // TODO: encrypt
    void encrypt(std::vector<MentalCard> &cards) {

        MentalCard::shuffle(cards);
    }

    // TODO: decode
    void decode(MentalCard &card) {


    }

    void decode(std::pair<MentalCard, MentalCard> cards) {
        decode(cards.first);
        decode(cards.second);
        this->cards = cards;
    }

    friend std::ostream &operator<<(std::ostream &os, const MentalPlayer &player)
    {
        os << player.cards.first << '&' << player.cards.second;
        return os;
    }
};


#endif //PROTECTION_INFORMATION_MENTALPLAYER_H
