#include "Pile.h"
#include <algorithm>
#include <random>
#include <ctime>


/* Constructors and Destructors */


Pile::Pile()
{
    //ctor
}

Pile::Pile(std::vector<Card> v_cards){
    this->clearDeck();
    this->addCards(v_cards);
}

Pile::~Pile()
{
    this->v_cards.clear();
}



/* Drawing Cards */

Card Pile::drawTop(){
    Card r_card = this->v_cards.back();
    this->v_cards.pop_back();
    return r_card;
}


std::vector<Card> Pile::drawAllCards(){
    std::vector<Card> v_return = this->v_cards;
    this->v_cards.clear();
    return v_return;
}


/* Adding Cards to Deck */
void Pile::addCards(std::vector<Card> v_cards){
    this->v_cards.insert(this->v_cards.end(), v_cards.begin(), v_cards.end());
}

void Pile::addBottom(std::vector<Card> v_cards){
    this->v_cards.insert(this->v_cards.begin(), v_cards.begin(), v_cards.end());
}
void Pile::addCard(Card card){
    this->v_cards.push_back(card);

}
void Pile::addBottom(Card card){
    this->v_cards.insert(this->v_cards.begin(), card);
}

/* Shuffles */
void Pile::shuffle(){
    std::srand(std::time(0));
    std::mt19937 g(std::rand());
    std::shuffle(v_cards.begin(), v_cards.end(), g);
}

/* Special Functions */
void Pile::createDefault(bool b_shuffled){

    /* Need to figure out where to store these */
    /*
        const std::vector<std::string> v_numbers = {std::string("Ace"), std::string("Two"), std::string("Three"), std::string("Four"), std::string("Five"), std::string("Six"), std::string("Seven"), std::string("Eight"), std::string("Nine"), std::string("Ten"), std::string("Jack"), std::string("Queen"), std::string("King")};
        const std::vector<std::string> v_suits = {std::string("Clubs"), std::string("Diamonds") ,std::string("Hearts"), std::string("Spades")};
    */
    /* And the best place to run this algorithm */
    /*
    for(std::string s_postfix : v_postfix){
        for(std::string s_prefix : v_prefix){
            defaultPile(Card(s_prefix + s_join + s_postfix));
        }
    }
    */
    if(b_shuffled){
            this->shuffle();
    }
}

void Pile::clearDeck(){
    this->v_cards.clear();
}

