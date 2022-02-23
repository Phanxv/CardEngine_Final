#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck
{
    friend int countScore(Deck);
    public :
        Deck() : numberOfCard(0) {}
        void starterDeck();
        void shuffleCards();
        void showDeck();
        void swapCard(int,int);
        void showCard(int);
        void showSingleCard(int);
        void testDeck();
	    void placeAfter(Card);
        void placeBefore(Card);
        Card sendCard(int);
        void dealCard(int, int, Deck []);
        void dealCard(int, Deck &);
        void pickSetCard(int, int, Deck &);
        void pickSetCard(int, int, Deck &, int);
        void testDeck2();
        void placeBetween(Card, int);
    private :
        int numberOfCard;
        Card deckCard[52];
};

#endif
