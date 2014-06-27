#include <iostream>
#include <Deck.h>
#include <Card.h>
#include <string>

using namespace std;

int main()
{
    Deck deck;
    deck.createDefaultDeck(false);
    cout << endl << deck.cardsRemaining() << endl;
    //deck.shuffleDeck();
    std::vector<Card> cards;
    std::vector<Card> hand;
    for(int i = 0; i < 5; i++)
        hand.push_back(deck.drawTopCard());


    //deck.addToDiscard(hand);
    for(int i = 0; i < 52; i++){
         Card card = deck.drawTopCard();
         cards.push_back(card);
         cout << card.getCardName() << endl;
    }
    cout << endl << endl;
    deck.resetDeck(hand, false);
    /*int i = 0;
    while(i++ < 100){
        cout << deck.drawTopCard().getCardName() << "\t";
    }*/
    return 0;
}
