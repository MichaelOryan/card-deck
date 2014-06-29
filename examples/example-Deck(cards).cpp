//    Usage of Deck(Pile)
#include <Deck.h>
#include <iostream>

int main(){

    Deck deck;
    deck.createDefaultDeck(false);
    Deck::Hand myHand;
    for(int i = 0; i < 26; i++){
        myHand.push_back(deck.drawTopCard());
    }
    Deck halfDeck(myHand);
    halfDeck.shufflePile();
    while(!halfDeck.isEmpty()){
        std::cout << halfDeck.drawTopCard().getCardName() << "\t";
    }
    std::cout << std::endl;
    return 0;
}
