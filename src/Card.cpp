#include "Card.h"

Card::Card(const std::string &s_name)
{
    setCardName(s_name);
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

bool Card::operator==(const Card &rhs){
    return s_name == rhs.s_name;
}

