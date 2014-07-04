#Untested for a while and for blackjack
#I just assume it works will test later
#Log an issue or make a push request if it doesn't work and/or you have a solution

all:	main blackjack

blackjack:	Card.o Deck.o blackjack.o
	g++ -o blackjack -I include blackjack.o Deck.o Card.o -std=c++11

blackjack.o:	blackjack.cpp
	g++ -o blackjack.o -I include -c blackjack.cpp -std=c++11

main:	Card.o Deck.o main.o 
	g++ -o testdeck -I include main.o Deck.o Card.o -std=c++11

main.o: main.cpp
	g++ -I include -c main.cpp -std=c++11

Deck.o:	include/Deck.h src/Deck.cpp
	g++ -I include -c src/Deck.cpp -std=c++11

Card.o: include/Card.h src/Card.cpp
	g++ -I include -c src/Card.cpp -std=c++11

clean:
	rm *.o
	
