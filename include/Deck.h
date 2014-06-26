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
        Deck(const std::vector<Card> &v_cards);
        virtual ~Deck();
        void addCard(const Card card, int i_number = 1); // add i_number clones of card to deck
        Card drawTopCard(int i_burn_number); //draws one card skipping the first i_burn_number cards
        Card drawTopCard();
        void shuffleDeck();
        void createDefaultDeck(bool b_shuffled = true);
        bool isEmpty(); //Empties the deck and creates a default 52 card deck of ace, 2-10, jack, queen and king in suits of Clubs, Diamonds, Hearts and Spades
        void resetDeck(const bool b_shuffled = true); //Resets deck back to it's original state. Order not guaranteed.
        void resetDeck(const std::vector<Card> &v_inplay, const bool &b_shuffled = true); //Takes drawn cards and places them in the deck. Removes clashes with cards in excluded. Order not guaranteed.
        void readdDiscards();
        void addToDiscard(Card &card); // Add a card to the discard pile.
        void addToDiscard(std::vector<Card> &v_cards); // Add multiple cards to the discard pile
        int cardsRemaining();
        void shuffleDiscard();
        void discardShuffle();
        bool discardEmpty();
        Card drawDiscard(const bool &b_shuffle); // Draw a card from the discard pile
    protected:
    private:
        void shuffleDeck(std::vector<Card> &v_cards); //shuffles target deck
        Card drawTopCard(std::vector<Card> &v_pile); //store drawn cards in the appropriate pile
        std::vector<Card> v_cards; //All cards that make up the current undrawn or undiscarded deck
        std::vector<Card> v_drawn; //Keeps a track of all cards drawn but not discarded
        std::vector<Card> v_discard; //Cards that have been discarded
};

#endif // DECK_H
