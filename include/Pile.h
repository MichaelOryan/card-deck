#ifndef PILE_H
#define PILE_H

#include <Card.h>
#include <vector>

class Pile
{
    public:

        /* Constructors and Destructors */
        Pile();
        Pile(std::vector<Card> v_cards);
        virtual ~Pile();

        /* Drawing Cards */
        Card drawTop();
        std::vector<Card> drawAllCards();

        /* Adding Cards to Deck */
        void addCards(std::vector<Card> v_cards);
        void addBottom(std::vector<Card> v_cards);
        void addCard(Card card);
        void addBottom(Card card);

        /* Shuffles */
        void shuffle();

        /* Special Functions */
        void createDefault(bool b_shuffled = true);
        void clearDeck();

        /* Operators */
        const Pile operator+(const Pile &p_rhs);

    protected:
    private:

        /* Private data */
        std::vector<Card> v_cards;
};

#endif // PILE_H
