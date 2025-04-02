#include "ex03.hpp"

#include <unordered_map>
#include <vector>

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 15};

    if (card_value < 10) {
        name += '0' + std::to_string(card_value);
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }else {
        name += "Ace";
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main()
{
    std::vector<Card> packet = get_cards(100);
    std::unordered_map<Card, int> range;

    Card card;
    for (size_t i = 0; i < 52; i++)
    {
        card.kind = static_cast<CardKind>(i/13);
        card.value = static_cast<CardValue>(i%13);
        range[card] = 0;
    }
    for (Card card : packet)
    {
        range[card]++;
    }
    
    for (size_t i = 0; i < 52; i++)
    {
        card.kind = static_cast<CardKind>(i/13);
        card.value = static_cast<CardValue>(i%13);
        std::cout << "There are " << range.find(card)->second << ' ' << card_name(card) << std::endl;
    }
}