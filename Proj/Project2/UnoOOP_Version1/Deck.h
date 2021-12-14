/* 
 * File:   Deck.h
 * Author: Miguel Galvez
 * Created on December 13, 2021, 3:55 PM
 * Purpose: Deck class aggregate, has properties of Uno card but
 *          contains multiple cards.
 */

#ifndef DECK_H
#define DECK_H
#include "Pile.h"
//
class Deck:public Pile{
    private:
        
    public:
    //Default constructor
        Deck():Pile(108){}
    //Constructor 2
        Deck(const short x):Pile(x){};
        void define();     //Defines entire deck of Uno cards
};

#endif /* DECK_H */

