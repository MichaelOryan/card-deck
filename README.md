card-deck
=========

Defines two structures for a deck of cards.


Card
------------------------------------------
Which must be constructed with a string name
Card card("Card Name");

Change the card name by
card.setCardName("Some other name");

Can add any string value to it by using a string key and value
card.addValue("Points", "100");

Retrieve a value from a card

cout << card.getValue("Points");


Deck
------------------------------------------
construct with or without a card

Deck deck(card);
Deck deck();

Add cards to a deck

deck.addCard(card, 2); // Add two copies of card to deck
deck.addCard(card); // Add one copy of card to deck

Draw a card from the deck with or without burning card to the discard pile.
If there are no cards to draw then it will start with a new deck of all the previously drawn cards.
Possible features for the future. Having a discard pile which can be added to and will become the new deck if the deck runs out of cards.

Card card = deck.drawTopCard(3); //Puts 3 cards into the discard pile and returns the 4th

card = deck.drawTopCard(); // Draws one card

Check to see if the deck is empty

deck.isempty(); // true if empty

Reset the deck excluding certain cards on a one for one basis. Assumes that the reset deck will be shuffled.

std::vector<cards> cards = //some cards
deck.reset(cards, false); // all cards added back to deck except for those in cards. Not shuffled.

Forgot the most fun part. You can create a default deck of 52 cards.

Deck.deck;
deck.createDefaultDeck(false); //52 cards, ace to king, 4 suits, unshuffled.
