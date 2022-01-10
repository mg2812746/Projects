/* 
 * File:   Deck.h
 * Author: Miguel Galvez
 * Created on December 17, 2021, 8:51 PM
 * Purpose: Deck Class, a class that functions to hoard
 *          the entire deck of Uno cards.
 */

#ifndef DECK_H
#define DECK_H
#include "Uno.h"
#include "Pile.h"
class Deck:public Pile{
    private:
        bool stat[108];     //Status of Uno cards in deck
    public:
        Deck();            //Default constructor
        void define();     //Defines entire deck of Uno cards
        void display();    //Displays entire deck of Uno cards
        bool status(int);  //Returns true if card is available, false otherwise    
        char *getColor(int);//Returns indicated card's color
        short getValue(int);//Returns value of a card
        void falsify(int);  //Falsifies indicated index in bool array
        int getIndex();     //Returns a valid index of a card that can be drawn
};


#endif /* DECK_H */

