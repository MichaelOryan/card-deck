#include "Card.h"

Card::Card(const std::string &s_name)
{
    setCardName(s_name);
}

Card(const std::string &s_name, int i_type){
    this->Card(i_type);// This before assigning a name as Card(int i_type) reserves the right to give a default name. Maybe replace with direct call to Card::addType(int)
    this->Card(s_name);
}

//Reserved right to give a default name to a card.
Card(int i_type){
    this->addType(i_type);
}



Card::~Card()
{
    //dtor
}

void Card::setCardName(const std::string &s_name){
    this->s_name = s_name;
}

std::string Card::getCardName(){
    return this->s_name;
}

void Card::addValue(const std::string &s_key, const std::string &s_value){
    this->m_properties[s_key] = s_value;
}

std::string Card::getValue(const std::string &s_key){
    return this->m_properties[s_key]; // This seems wrong somehow
}

//Overloads comparison operator == with the check to see if two cards are the same.
bool Card::operator==(const Card &rhs){
    return i_type == rhs.i_type;
}

void setType(const int i_type){
    this->i_type = i_type;
}

int getType(){
    return this->i_type;
}


