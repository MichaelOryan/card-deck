#ifndef CARD_H
#define CARD_H
#include <string>
#include <map>

class Card
{
    public:
        Card(const std::string &name);
        virtual ~Card();
        void setCardName(const std::string &name);
        std::string getCardName();
        void addValue(const std::string &s_key, const std::string &s_value);
        std::string getValue(const std::string &s_key);
        bool operator==(const Card &rhs);

    protected:
    private:
        std::string name;
        std::map<std::string, std::string> m_properties;
};

#endif // CARD_H
