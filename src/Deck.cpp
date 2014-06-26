#include "Deck.h"

Deck::Deck()
{
    //ctor
}

Deck::~Deck()
{
    this->cards.clear();
    this->drawn.clear();
}


// add i_number clones of card to deck
void Deck::addCard(const Card card, int i_number){
    for(int i_counter = 0; i_counter < i_number; i_counter++){
        this->cards.push_back(Card(card));
    }
}

Card Deck::drawTopCard(){
    if(this->isEmpty())
        this->resetDeck();
    Card card = this->cards.back();
    this->cards.pop_back();
    this->drawn.push_back(card);
    return card;

}
//draw i_number cards, skipping every i_skip_interval between cards, skipping the first i_burn_number cards
Card Deck::drawTopCard(int i_burn_number){
    for(int i_count = 0; i_count < i_burn_number; i_count++){
            Card card = this->drawTopCard();
    }
    Card card = this->drawTopCard();
    return card;
}

void Deck::shuffleDeck(){
    std::srand(std::time(0));
    std::mt19937 g(std::rand());
    std::shuffle(this->cards.begin(), this->cards.end(), g);
}

 //Empties the deck and creates a default 52 card deck of ace, 2-10, jack, queen and king in suits of Clubs, Diamonds, Hearts and Spades
void Deck::createDefaultDeck(bool shuffled){
    std::vector<std::string> numbers = {std::string("Ace"), std::string("Two"), std::string("Three"), std::string("Four"), std::string("Five"), std::string("Six"), std::string("Seven"), std::string("Eight"), std::string("Nine"), std::string("Ten"), std::string("Jack"), std::string("Queen"), std::string("King")};
    std::vector<std::string> suits = {std::string("Clubs"), std::string("Diamonds") ,std::string("Hearts"), std::string("Spades")};
    for(std::string &number : numbers)
        for(std::string &suit : suits){
            std::string cardname = number + " of " + suit;
            this->addCard(Card(cardname));
        }
    if(shuffled)
        this->shuffleDeck();
}

bool Deck::isEmpty(){
    return this->cards.empty();
}

void Deck::resetDeck(const std::vector<Card> excluded, const bool shuffled){
    std::vector<Card> left_to_exclude;
    for(const Card &card : excluded)
        left_to_exclude.push_back(card);
    for(Card &card : this->drawn){
        auto it_excluded = std::find(std::begin(left_to_exclude), std::end(left_to_exclude), card);
        if(it_excluded == std::end(left_to_exclude)){
            this->cards.push_back(card);
        }
        else{
            left_to_exclude.erase(it_excluded);
        }
    }
    if(shuffled){
        this->shuffleDeck();
    }
}

void Deck::resetDeck(const bool shuffled){
    for(Card &card : this->drawn){
            this->cards.push_back(card);
    }
    if(shuffled){
        this->shuffleDeck();
    }
}
