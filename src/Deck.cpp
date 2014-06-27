#include "Deck.h"

Deck::Deck()
{
    //ctor
}

Deck::~Deck()
{
    this->v_cards.clear();
    this->v_drawn.clear();
}

Deck::Deck(const std::vector<Card> &v_cards){
    this->v_cards = v_cards;
}

// add i_number clones of card to deck
void Deck::addCard(const Card card, int i_number){
    for(int i_counter = 0; i_counter < i_number; i_counter++){
        this->v_cards.push_back(Card(card));
    }
}

//Used to say what pile drawn cards should go to. Such as directing burn cards to the discard pile.
Card Deck::drawTopCard(std::vector<Card> &v_pile){
    if(this->isEmpty()){
        if(this->v_discard.empty()){
            this->resetDeck();
        }
        else{
            this->readdDiscards();
        }
    }
    Card card = this->v_cards.back();
    this->v_cards.pop_back();
    v_pile.push_back(card);
    return card;

}

Card Deck::drawTopCard(){
    return this->drawTopCard(this->v_drawn);

}
//draw a card skipping the first i_burn_number cards which will end up in the discard pile
Card Deck::drawTopCard(int i_burn_number){
    for(int i_count = 0; i_count < i_burn_number; i_count++){
            Card card = this->drawTopCard(this->v_discard);
    }
    Card card = this->drawTopCard();
    return card;
}

void Deck::shuffleDeck(std::vector<Card> &v_cards){
    std::srand(std::time(0));
    std::mt19937 g(std::rand());
    std::shuffle(v_cards.begin(), v_cards.end(), g);
}

//Shuffles main deck of cards that are drawn from
void Deck::shuffleDeck(){
    this->shuffleDeck(this->v_cards);
}


 //Empties the deck and creates a default 52 card deck of ace, 2-10, jack, queen and king in suits of Clubs, Diamonds, Hearts and Spades
void Deck::createDefaultDeck(bool b_shuffled){
    std::vector<std::string> v_numbers = {std::string("Ace"), std::string("Two"), std::string("Three"), std::string("Four"), std::string("Five"), std::string("Six"), std::string("Seven"), std::string("Eight"), std::string("Nine"), std::string("Ten"), std::string("Jack"), std::string("Queen"), std::string("King")};
    std::vector<std::string> v_suits = {std::string("Clubs"), std::string("Diamonds") ,std::string("Hearts"), std::string("Spades")};
    this->createDeck(v_numbers, std::string(" of "), v_suits);
    if(b_shuffled)
        this->shuffleDeck();
}

void Deck::createDeck(std::vector<std::string> &v_prefix, std::string s_join, std::vector<std::string> &v_postfix){
    for(std::string s_postfix : v_postfix){
        for(std::string &s_prefix : v_prefix){
            this->addCard(Card(s_prefix + s_join + s_postfix));
        }
    }
}

bool Deck::isEmpty(){
    return this->v_cards.empty();
}


//All cards are now in the draw deck v_cards excluding those contained in v_inplay which are removed on a one for one basis.
void Deck::resetDeck(const std::vector<Card> &v_inplay, const bool &b_shuffled){
    std::vector<Card> v_left_to_exclude;
    for(const Card &card : v_inplay)
        v_left_to_exclude.push_back(card);
    for(Card &card : this->v_drawn){
        auto it_excluded = std::find(std::begin(v_left_to_exclude), std::end(v_left_to_exclude), card);
        if(it_excluded == std::end(v_left_to_exclude)){
            this->v_cards.push_back(card);
        }
        else{
            v_left_to_exclude.erase(it_excluded);
        }
    }
    this->readdDiscards();// Maybe don't shuffle the deck twice by making this not shuffle
    if(b_shuffled){
        this->shuffleDeck();
    }
}

//All cards are now in the main draw pile. v_cards
void Deck::resetDeck(const bool b_shuffled){
    for(Card &card : this->v_drawn){
            this->v_cards.push_back(card);
    }
    this->readdDiscards();
    if(b_shuffled){
        this->shuffleDeck();
    }
}

//Adds the discard pile to the main draw pile v_cards
void Deck::readdDiscards(){// Put a bool here
    for(Card &card : this->v_discard)
        this->v_cards.push_back(card);
    this->v_discard.clear();
    this->shuffleDeck();
}

int Deck::cardsRemaining(){
    return this->v_cards.size();
}



// Add a card to the discard pile.
void Deck::addToDiscard(const Card &card){
    this->v_discard.push_back(card);
    removeCard(card, D_DRAWN);
}

// Add multiple cards to the discard pile
void Deck::addToDiscard(std::vector<Card> &v_cards){
    for(const Card &card : v_cards){
        this->addToDiscard(card);
    }

}

bool Deck::discardEmpty(){
    return this->v_discard.empty();
}


//Draw a card form the discard pile if possible otherwise the normal deck.
Card Deck::drawDiscard(const bool &b_shuffle){
    if(b_shuffle){
        this->shuffleDiscard();
    }
    if(this->discardEmpty()){
        if(this->isEmpty()){
            this->resetDeck();
        }
        return this->drawTopCard();
    }
    Card card = this->v_discard.back();
    this->v_discard.pop_back();
    v_drawn.push_back(card);
    return card;
}


//Shuffles the discard pile.
void Deck::shuffleDiscard(){
    this->shuffleDeck(this->v_discard);
}

//Removes the first card found in pile equal to card
void Deck::removeCard(Card card, std::vector<Card> &v_pile){
    auto it_card = std::find(std::begin(v_pile), std::end(v_pile), card);
     v_pile.erase(it_card);
}

void Deck::removeCard(Card card, Decks d_deck){
    switch(d_deck){
        case D_MAIN:removeCard(card, v_cards);
                break;
        case D_DRAWN:removeCard(card, v_drawn);
                break;
        case D_DISCARD:removeCard(card, v_discard);
                break;
        default:;
    };
}
