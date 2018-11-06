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
    int64_t p{};
    std::pair<MentalCard, MentalCard> cards;
public:
    MentalPlayer() = default;

    explicit MentalPlayer(uint64_t P)
    {
        auto [C, D] = op.getCD(0, P - 1);
        this->c = C;
        this->d = D;
        this->p = P;
    }

    void decode(MentalCard &card) {
        auto de = op.powmod(card.getCard(), this->d, this->p); //card.getCard() ^ this->p;
        card.setCard(de);
    }

    void encrypt(std::vector<MentalCard> &cards) {
        for (auto &c: cards) {
            auto en = op.powmod(c.getCard(), this->c, this->p);
            c.setCard(en);
        }
        MentalCard::shuffle(cards);
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
