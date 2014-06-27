#ifndef CARD_H
#define CARD_H
#include <string>
#include <map>

class Card
{
    public:
        /* Constructors/Destructors */
        Card(const std::string &s_name);
        virtual ~Card();

        /* Set values */
        void setCardName(const std::string &s_name);
        void addValue(const std::string &s_key, const std::string &s_value);

        /* Get Values */
        std::string getCardName();
        std::string getValue(const std::string &s_key);

        /* Overloaded operators */
        bool operator==(const Card &rhs);

    protected:
    private:
        /* Values */
        std::string s_name;
        std::map<std::string, std::string> m_properties;
};

#endif // CARD_H
