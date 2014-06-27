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
If there are no cards to draw then it will start by shuffling the discard pile and making those cards available to draw.

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

Added a bunch of new features for dealing with discard piles.

Cards that would normally go to a discard pile in a real life game can now be added to the deck discard pile. Card there will be automatically added to the draw pile when it becomes empty.

For clarification std::vector<Card> is now known as a pile. If it makes sense to. I'll have to work out a way of making that happen with code.


Upcoming - Next Major Update
------------------------------------------

Next task it to go over all the code and make sure it makes sense.

Cut out functions that don't need to be there or accessed publically.

Make sure everything maintains the same style and consistency.

Maybe if it makes sense to define std::vector<Card> as a typedef of Pile. 

typedef std::vector<Card> Pile;

Long term
------------------------------------------

Revist after the upcoming session at uni is over and cry at how bad my code is and rewrite it all.


Features Ideas for Future Updates
------------------------------------------
Possible peek function for cards on piles.

Draw x return less than x to the deck, shuffled(whole, returned cards) or unshuffled.

Better way of storing values to each card. Esp for numeric values.
