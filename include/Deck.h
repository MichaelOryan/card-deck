#ifndef DECK_H
#define DECK_H

#include <vector>
#include <Card.h>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>


class Deck
{
    public:
        Deck();
        virtual ~Deck();
        void addCard(const Card card, int i_number = 1); // add i_number clones of card to deck
        Card drawTopCard(int i_burn_number); //draws one card skipping the first i_burn_number cards
        Card drawTopCard();
        void shuffleDeck();
        void createDefaultDeck(bool shuffled = true);
        bool isEmpty(); //Empties the deck and creates a default 52 card deck of ace, 2-10, jack, queen and king in suits of Clubs, Diamonds, Hearts and Spades
        void resetDeck(const bool shuffled = true); //Resets deck back to it's original state. Order not guaranteed.
        void resetDeck(const std::vector<Card> excluded, const bool shuffled = true); //Takes drawn cards and places them in the deck. Removes clashes with cards in excluded. Order not guaranteed.

    protected:
    private:
        std::vector<Card> cards;
        std::vector<Card> drawn;
};

#endif // DECK_H
