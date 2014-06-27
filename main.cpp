/*
Example main.cpp file that I use for testing the library out.
I guess I won't learn about proper testing for a while so this is it for the moment. :\

A better example now may be blackjack.cpp
*/


#include <iostream>
#include <Deck.h>
#include <Card.h>
#include <string>

//using namespace std; //Bye by std namespace. Uncomment it if you really have to.
using std::cout;
using std::endl;
using std::cin;


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


    deck.addToDiscard(hand);
    deck.resetDeck();
    cout << deck.cardsRemaining() << endl;
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
