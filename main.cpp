#include <iostream>
#include <Deck.h>
#include <Card.h>
#include <string>

using namespace std;

int main()
{
    Deck deck;
    deck.createDefaultDeck();
    deck.shuffleDeck();
    std::vector<Card> cards;
    for(int i = 0; i < 5; i++){
         Card card = deck.drawTopCard();
         cards.push_back(card);
         cout << card.getCardName() << endl;
    }
    cout << endl << endl;
    deck.resetDeck(cards);
    int i = 0;
    while(i++ < 100){
        cout << deck.drawTopCard().getCardName() << "\t";
    }


    return 0;
}
