#ifndef DECK_H
#define DECK_H

#include <vector>
#include <Card.h>
#include <string>

class Deck
{

    public:
        typedef std::vector<Card> Pile;
        typedef Pile Hand;
        /* Constructors/Destructors*/
        Deck();
        Deck(const std::vector<Card> &v_cards);
        virtual ~Deck();

        /* Add Cards */
        void addCard(const Card card, int i_number = 1); // add i_number clones of card to deck
        void addToDiscard(const Card &card); // Add a card to the discard pile.
        void addToDiscard(std::vector<Card> &v_cards); // Add multiple cards to the discard pile

        /* Deck creation */
        void createDeck(std::vector<std::string> &v_prefix, std::string s_join, std::vector<std::string> &v_postfix);
        void createDefaultDeck(bool b_shuffled = true, bool b_clearPiles = true); // Default is to clear all piles

        /* Draw Cards */
        Card drawDiscard(const bool &b_shuffle); // Draw a card from the discard pile
        Card drawTopCard(int i_burn_number); //draws one card skipping the first i_burn_number cards. Starts from the end of std::vector<Card>
        Card drawTopCard();


        /* Shuffles */
        void shuffleDiscard();
        void shufflePile(); // Shuffles v_cards

        /* Reset */
        void clearAllPiles();
        void resetDeck(const bool b_shuffled = true); //Resets deck back to it's original state. Order not guaranteed.
        void resetDeck(const std::vector<Card> &v_inplay, const bool &b_shuffled = true); //Takes drawn cards and places them in the deck. Removes clashes with cards in excluded. Order not guaranteed.
        void reAddDiscards(); // Adds discard pile to draw pile

        /* Properties/States */
        int cardsRemaining();
        bool discardEmpty();
        bool isEmpty(); //Empties the deck and creates a default 52 card deck of ace, 2-10, jack, queen and king in suits of Clubs, Diamonds, Hearts and Spades

        /* Public definitions */
        //Definition of a standard deck which is used when creating a default deck. Maybe look at a better way of doing this.
        std::vector<std::string> v_numbers = {std::string("Ace"), std::string("Two"), std::string("Three"), std::string("Four"), std::string("Five"), std::string("Six"), std::string("Seven"), std::string("Eight"), std::string("Nine"), std::string("Ten"), std::string("Jack"), std::string("Queen"), std::string("King")};
        std::vector<std::string> v_suits = {std::string("Clubs"), std::string("Diamonds") ,std::string("Hearts"), std::string("Spades")};

    protected:
    private:
        /* Private Definitions */
        enum Decks{D_MAIN, D_DRAWN, D_DISCARD};
        std::vector<Card> v_cards; //All cards that make up the current undrawn or undiscarded deck
        std::vector<Card> v_drawn; //Keeps a track of all cards drawn but not discarded
        std::vector<Card> v_discard; //Cards that have been discarded

        /* Shuffle */
        void shufflePile(std::vector<Card> &v_cards); //shuffles target pile

        /* Draw */
        Card drawTopCard(std::vector<Card> &v_pile); //store drawn cards in the appropriate pile

        /* Remove Cards */
        void removeCard(Card card, std::vector<Card> &v_pile);
        void removeCard(Card card, Decks d_deck);

        /* Resetting/Clearing */
        void clearPile(Decks d_deck);
        void clearPile(std::vector<Card> &v_pile);

};

#endif // DECK_H
