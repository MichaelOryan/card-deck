#include <iostream>
#include <Deck.h>
#include <Card.h>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

bool getInput(std::string question, std::vector<std::string> v_true, std::vector<std::string> v_false);
int calcPoints(Card card, Deck deck);
void displayCards(std::string leadingText, std::vector<Card> &hand);
bool isBust(std::vector<Card> hand, int max_score, Deck deck);
int calcTotalScore(std::vector<Card> hand, int max_score, Deck deck);

int main()
{
    Deck deck;
    deck.createDefaultDeck();
    std::vector<Card> myHand;
    std::vector<Card> computerHand;

    myHand.push_back(deck.drawTopCard());
    myHand.push_back(deck.drawTopCard());

    displayCards("Here are your cards - ", myHand);

    std::vector<std::string> yes = {"y", "yes"};
    std::vector<std::string> no = {"n", "no"};
    while(!isBust(myHand, 21, deck) && getInput("Draw another card? y/n:", yes, no)){
        Card card = deck.drawTopCard();
        myHand.push_back(card);
        cout << "You drew a " << card.getCardName() << endl;
    }

    cout << "Your score is: " << calcTotalScore(myHand, 21, deck);

    return 0;
}

int calcPoints(Card card, Deck deck){
    int i_size = deck.v_numbers.size();
    for(int i = 0; i < i_size; i++){
            if(card.getCardName().find(deck.v_numbers[i]) != std::string::npos){
                return i < 10 ? i + 1 : 10;
            }
    }

    return 0;

}

bool isBust(std::vector<Card> hand, int max_score, Deck deck)
{
    return calcTotalScore(hand, max_score, deck) > max_score;
}

int calcTotalScore(std::vector<Card> hand, int max_score, Deck deck){
    int aces = 0;
    int score = 0;
    for(Card &card : hand){
        int thisCard = calcPoints(card, deck); //Get lowest value for each card. Aces are one.
        score += thisCard;
        aces += thisCard == 1? 1 : 0;
    }
    //Aces can be one of eleven points.
    while(score + 10 <= max_score && aces > 0){
        aces--;
        score += 10;
    }
    return score;
}


void displayCards(std::string leadingText, std::vector<Card> &hand){

    cout << leadingText;
    for(Card &card : hand){
        cout << card.getCardName() << " ";
    }
    cout << "\n";

}

bool getInput(std::string question, std::vector<std::string> v_true, std::vector<std::string> v_false)
{
    std::string choice;
    bool is_true = false;
    bool is_false = false;
    bool first_run = true;
    cout << std::flush;
    do{
        if(!cin.good()){
            cin.clear();
            cin.ignore(100, '\n');
        }
        if(first_run){
            first_run = false;

        }
        else{
            cout << "Valid choice entered. Please try again." << endl;
        }
        cout << question << std::flush;
        cin >> choice;

        is_true = std::find(v_true.begin(), v_true.end(), choice) != v_true.end();
        is_false = std::find(v_false.begin(), v_false.end(), choice) != v_false.end();
    }while(!(is_true || is_false));

    return is_true && !is_false;
}
