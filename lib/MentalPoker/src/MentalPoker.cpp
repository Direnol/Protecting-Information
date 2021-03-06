//
// Created by direnol on 05.11.18.
//

#include <MetalPoker.h>

MentalPoker::MentalPoker(const uint64_t count_player, uint64_t P, const uint64_t count_card)
{
    if (P == 0) {
        P = static_cast<uint64_t>(op.get_simple());
    }
    this->P = P;
    std::cout << "P = " << this->P << std::endl;
    for (auto i = 0; i < count_player; ++i) {
        this->players.emplace_back(this->P);
    }
    for (uint64_t i = 0; i < count_card; ++i) {
        this->cards.emplace_back(i);
    }
    MentalCard::shuffle(this->cards);
    for (auto &c: this->cards) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;
}

std::pair<std::vector<MentalPlayer>, std::vector<MentalCard>> MentalPoker::game()
{
    if ((2 * this->players.size() + 5) > this->cards.size()) {
        std::ostringstream err;
        err << "Invalid count of cards: " << this->cards.size() << " for count of players: " << this->players.size()
            << std::endl;
        err << "Must be minimum count of cards: count_player * 2 + 5" << std::endl;
        throw err.str();
    }
/*
 * Теперь работает такая схема, каждый игрок берет и кодирует
 * карты своим секретным числом (с) по формуле (u^c mod p), и
 * мешает карты
 */
    for (auto &p: this->players) {
        p.encrypt(this->cards);
    }
/*
* Теперь работает такая схема, каждый игрок выполняет следующий алгоритм
* 1) Выбрать карту
* 2) Всё её декодируют по формуле (u^d mod p), но никто не знает
*    какая это конечная карта в итоге
* 3) После того как все остальные выполнили декодирование данной карты,
*    она возвращается к стартовому игроку, и он, декодируя её, определяет
*    какая это карта
* 5) Мешаем карты
*/
    for (auto i = 0; i < players.size(); ++i) {
        MentalCard pcard[2];
        for (auto &c : pcard) {
            auto idx = op.getRand() % this->cards.size();
            c = this->cards[idx];
            for (auto j = 0; j < players.size(); ++j) {
                if (i != j) {
                    players[j].decode(c);
                }
            }
            cards.erase(this->cards.begin() + idx);
        }
        players[i].decode(std::make_pair(pcard[0], pcard[1]));
        MentalCard::shuffle(this->cards);
    }
    std::vector<MentalCard> desk;
    desk.reserve(5);
    for (auto i = 0; i < 5; ++i) {
        desk.push_back(this->cards[i]);
    }
    for (auto &p: this->players) {
        for (auto &c: desk) p.decode(c);
    }
    return std::make_pair(players, desk);
}