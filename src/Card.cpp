#include "Card.h"

Card::Card(const std::string &name)
{
    setCardName(name);
}


Card::~Card()
{
    //dtor
}

void Card::setCardName(const std::string &name){
    this->name = name;
}

std::string Card::getCardName(){
    return this->name;
}

void Card::addValue(const std::string &s_key, const std::string &s_value){
    this->m_properties[s_key] = s_value;
}

std::string Card::getValue(const std::string &s_key){
    return this->m_properties[s_key]; // This seems wrong somehow
}

bool Card::operator==(const Card &rhs){
    return name == rhs.name;
}

