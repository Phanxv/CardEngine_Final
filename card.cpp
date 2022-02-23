#include "card.h"

void Card::assignCardFace(char cardFace)
{face = cardFace;}

void Card::assignCardNumber(int cardNumber)
{number = cardNumber;}

char Card::getCardFace()
{return face;}

int Card::getCardNumber()
{return number;}
