#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "card.h"
#include "deck.h"

using namespace std;

int countScore(Deck);
bool allPlayerStand(int numberOfPlayer, char usrInput[]);
int findWinner(int,Deck[]);

int main()
{
    int numberOfPlayer,i,gameOverCondition;
    bool gameOver = false;
    cout << endl << "BlackJack game created using Card Games engine" << endl << endl;
    cout << "How many players (2-7 players) >> ";
    cin >> numberOfPlayer;
    Deck fullDeck, playerDeck[numberOfPlayer];
    char usrInput[numberOfPlayer];
    for(i=0;i<numberOfPlayer;i++)
        usrInput[i] = 'y';
    fullDeck.starterDeck();
    cout << endl << "Shuffling cards..." << endl << endl;
    fullDeck.shuffleCards();
    fullDeck.dealCard(2,numberOfPlayer,playerDeck);
    for(i=0; i<numberOfPlayer ; i++){
        cout << "Player " << i+1 << "'s hand : " << endl;
        playerDeck[i].showDeck();
        cout << "Player " << i+1 << "'s Total score : " << countScore(playerDeck[i]) << endl << endl;
    }
    while(!gameOver){
        for(i=0;i<numberOfPlayer;i++)
            usrInput[i] = 'y';
        for(i=0; i<numberOfPlayer ; i++){
            cout << "Player " << i+1 << " do you want to hit? (Y/N) >> ";
            cin >> usrInput[i];
            if(usrInput[i] == 'Y' || usrInput[i] == 'y')
                fullDeck.dealCard(1,playerDeck[i]);
            if(usrInput[i] == 'N' || usrInput[i] == 'n')
                cout << "Player " << i+1 << " stand" << endl << endl;
            cout << "Player " << i+1 << "'s hand : " << endl;
            playerDeck[i].showDeck();
            cout << "Player " << i+1 << "'s Total score : " << countScore(playerDeck[i]) << endl << endl;
            if(allPlayerStand(numberOfPlayer,usrInput)==true){
                gameOverCondition = 1;
                gameOver = true;
                break;
            }
            if(countScore(playerDeck[i])>21){
                gameOverCondition = 2;
                gameOver = true;
                break;
            }
        }
    }
    switch(gameOverCondition){
        case 1:
            cout << "Player " << findWinner(numberOfPlayer,playerDeck)+1 << " Win";
            break;
        case 2:
            for(i=0; i<numberOfPlayer; i++){
                if(countScore(playerDeck[i]) > 21){
                    cout << "Player " << i+1 << " BUSTED";
                }
            }
            break;

    }
    return 0;
}

int countScore(Deck playerHand){
    int totalScore = 0;
    for(int i=0 ; i<playerHand.numberOfCard ; i++){
        if(playerHand.deckCard[i].getCardNumber() > 1 && playerHand.deckCard[i].getCardNumber() < 11)
            totalScore += playerHand.deckCard[i].getCardNumber();
        else if(playerHand.deckCard[i].getCardNumber() >= 11)
            totalScore += 10;
        else if(playerHand.deckCard[i].getCardNumber() == 1 && totalScore <= 10)
            totalScore += 11;
        else
            totalScore += 1;
    }
    return totalScore;
}

bool allPlayerStand(int numberOfPlayer, char usrInput[]){
    for(int i=0; i<numberOfPlayer; i++){
        if(usrInput[i]=='Y'||usrInput[i]=='y')
            return false;
    }
    return true;
}

int findWinner(int numberOfPlayer, Deck playerHand[]){
    int maxIndex = 0;
    for(int i=0;i<numberOfPlayer;i++){
        if(countScore(playerHand[i]) > countScore(playerHand[maxIndex])){
            maxIndex = i;
        }
    }
    return maxIndex;
}
