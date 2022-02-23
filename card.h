#ifndef CARD_H
#define CARD_H

class Card
{
    public :
        void assignCardFace(char);
        void assignCardNumber(int);
        char getCardFace();
        int getCardNumber();
    private :
        char face;
        int number;
};

#endif

