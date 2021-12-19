/* 
 * File:   Player.h
 * Author: Miguel Galvez
 * Created on December 17, 2021, 9:06 PM
 * Purpose: Player Class, an Uno derived class in which 
 *          the player has access to tossing their cards to a
 *          pile, and drawing from a deck of Uno cards.
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Pile.h"   //Pile class - superclass
#include "Deck.h"   //Deck class - function parameter
#include <iostream>
#include <iomanip>
using namespace std;
class Player:public Pile{
private:
    bool skip;      //Flag - notifies whether or not player is skipped
public:
    Player();       //Default Constructor
    void draw(char*,int);    //Draws a card from deck
    bool getSkip()const{return skip;};   //returns skip
    void reset(){skip=0;};               //resets skip flag
    void hand();             //Displays the player's hand
};
#endif /* PLAYER_H */

