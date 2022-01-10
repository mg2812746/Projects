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
#include <iostream> //cout,cin
#include <iomanip>  //setw
#include <cstring>  //strstr,strcpy
using namespace std;
//Player Derived Class
class Player:public Pile{
private:
    bool skip;      //Flag - notifies whether or not player is skipped
public:
    Player();                   //Default Constructor
    void draw(char*,int);       //Draws a card from deck
    bool getSkip()const{return skip;};   //returns skip
    void reset(){skip=0;};               //resets skip flag
    void set(){skip=1;};                 //sets skip flag
    void hand();                //Displays the player's hand
    void remove(int);           //Remove the specified card from player
    char *wild();               //Returns a color depending on player selection
};
#endif /* PLAYER_H */