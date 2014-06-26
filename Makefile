all:	main

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
	
