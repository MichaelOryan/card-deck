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
        void addToDiscard(const Card &card); // Add a card to the discard pile.
        void addToDiscard(std::vector<Card> &v_cards); // Add multiple cards to the discard pile
        int cardsRemaining();
        void shuffleDiscard();
        bool discardEmpty();
        Card drawDiscard(const bool &b_shuffle); // Draw a card from the discard pile
        void createDeck(std::vector<std::string> &v_prefix, std::string s_join, std::vector<std::string> &v_postfix);
        int getUniqueCardType();
        int getCardType(Card card);

    protected:
    private:
        void shuffleDeck(std::vector<Card> &v_cards); //shuffles target deck
        Card drawTopCard(std::vector<Card> &v_pile); //store drawn cards in the appropriate pile
        std::vector<Card> v_cards; //All cards that make up the current undrawn or undiscarded deck
        std::vector<Card> v_drawn; //Keeps a track of all cards drawn but not discarded
        std::vector<Card> v_discard; //Cards that have been discarded
        void removeCard(Card card, std::vector<Card> &v_pile);
        enum Decks{D_MAIN, D_DRAWN, D_DISCARD};
        void removeCard(Card card, Decks d_deck);
        unsigned int last_unique_type; // Last unique type of card returned

};

#endif // DECK_H
