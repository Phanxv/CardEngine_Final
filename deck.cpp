#include "deck.h"
#include "card.h"
#include <iostream>
#include <ctime>

using namespace std;

void Deck::starterDeck(){
    for(int i=0;i<52;i++){
        if(i<=12){
            deckCard[i].assignCardFace('C');
            deckCard[i].assignCardNumber(i+1);
        }
        else if(i<=25){
            deckCard[i].assignCardFace('D');
            deckCard[i].assignCardNumber(i-12);
        }
        else if(i<=38){
            deckCard[i].assignCardFace('H');
            deckCard[i].assignCardNumber(i-25);
        }
        else{
            deckCard[i].assignCardFace('S');
            deckCard[i].assignCardNumber(i-38);
        }
        numberOfCard++;
    }
}

void Deck::showDeck(){
    if(numberOfCard == 0)
        cout << "There is no card on this deck" << endl;
    else{
        for(int i=0;i<numberOfCard;i++)
            showCard(i);
    }
}

void Deck::shuffleCards(){
    int randomIndex;
    Card tempCard;
    srand(time(NULL));
    for(int i=0;i<numberOfCard;i++){
        randomIndex = rand()%numberOfCard;
        tempCard = deckCard[randomIndex];
        deckCard[randomIndex] = deckCard[i];
        deckCard[i] = tempCard;
    }
}

void Deck::swapCard(int a, int b){
    Card tempCard;
    tempCard = deckCard[a-1];
    deckCard[a-1] = deckCard[b-1];
    deckCard[b-1] = tempCard;
}

void Deck::showCard(int i){
    if(deckCard[i].getCardNumber() == 1)
        cout << "[" << deckCard[i].getCardFace() << "-" << "A" << "]" << endl;
    else if(deckCard[i].getCardNumber() <= 10)
        cout << "[" << deckCard[i].getCardFace() << "-" << deckCard[i].getCardNumber() << "]" << endl;
    else if(deckCard[i].getCardNumber() == 11)
        cout << "[" << deckCard[i].getCardFace() << "-" << "J" << "]" << endl;
    else if(deckCard[i].getCardNumber() == 12)
        cout << "[" << deckCard[i].getCardFace() << "-" << "Q" << "]" << endl;
    else if(deckCard[i].getCardNumber() == 13)
        cout << "[" << deckCard[i].getCardFace() << "-" << "K" << "]" << endl;
}

void Deck::showSingleCard(int i)
{showCard(i-1);}

void Deck::testDeck(){
    numberOfCard = 5;
    deckCard[0].assignCardFace('C');
    deckCard[0].assignCardNumber(1);
    deckCard[1].assignCardFace('C');
    deckCard[1].assignCardNumber(5);
    deckCard[2].assignCardFace('H');
    deckCard[2].assignCardNumber(3);
    deckCard[3].assignCardFace('S');
    deckCard[3].assignCardNumber(2);
    deckCard[4].assignCardFace('D');
    deckCard[4].assignCardNumber(12);
}

void Deck::placeAfter(Card a)
{
    deckCard[numberOfCard] = a; //กำหนด Index เป็น numberofCard ซึ่งเป็นค่าขยะให้มันเท่ากับ parameter ของฟังก์ชั่นนี้
    numberOfCard++;
}

void Deck::placeBefore(Card a)
{
    int i;
    for(i = numberOfCard; i > 0; i--)
    {
        deckCard[i] = deckCard[i-1];//ทำจากหลังมาหน้า ตรงกันข้ามกับฟังก์ชั่น placeAfter
    }
    deckCard[0] = a;
    numberOfCard++;
}

Card Deck::sendCard(int index){
    Card tempCard = deckCard[index-1];
    for(int i = index-1; i < numberOfCard ;i++){
        deckCard[i] = deckCard[i+1];
    }
    numberOfCard--;
    return tempCard;
}

void Deck::dealCard(int amountDeal, int numberOfPlayer, Deck reciever[]){
    cout << "Dealing cards..." << endl << endl;
    for(int i = 0; i < amountDeal; i++){
        for(int j = 0; j < numberOfPlayer; j++){
            reciever[j].placeAfter(sendCard(numberOfCard));
        }
    }
}

void Deck::dealCard(int amountDeal, Deck &reciever){
    for(int i = 0; i < amountDeal; i++)
        reciever.placeAfter(sendCard(numberOfCard));
}

void Deck::pickSetCard(int firstCard, int lastCard, Deck &recieveDeck)
{
    for (int i = firstCard; i <= lastCard ; i++)
    {
        recieveDeck.placeAfter(sendCard(firstCard)); //ส่งจากใบสุดท้ายที่เลือก
    }
}

void Deck::pickSetCard(int firstCard, int lastCard, Deck &recieveDeck, int placePosition){
    for (int i = firstCard; i <= lastCard ; i++)
    {
        recieveDeck.placeBetween(sendCard(firstCard),placePosition + i - firstCard);
    }
}

void Deck::testDeck2()
{
    numberOfCard = 3;
    deckCard[0].assignCardFace('D');
    deckCard[0].assignCardNumber(10);
    deckCard[1].assignCardFace('S');
    deckCard[1].assignCardNumber(7);
    deckCard[2].assignCardFace('D');
    deckCard[2].assignCardNumber(3);
}

void Deck::placeBetween(Card a, int position)
{
    for(int i = numberOfCard; i > 0; i--)
    {
        deckCard[i] = deckCard[i-1];
    }
    deckCard[position - 1] = a;
    numberOfCard++;
}
