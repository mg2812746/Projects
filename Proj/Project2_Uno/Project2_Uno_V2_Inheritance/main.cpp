/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 17, 2021, 8:46 PM
 * Purpose: Uno Version 2, create a "Deck" "Pile" and "Player" class
 *          Pile is an aggregate class which is a pile of 
 *          Uno cards. Deck and Player both inherit pile, since they both
 *          consist of some form of pile of Uno cards.
 */

//System Libraries
#include <iostream>     //Input/Output Library
#include <ctime>        //time()
#include <cstdlib>      //rand()
#include <cstring>
#include "Uno.h"        //Uno Class
#include "Pile.h"       //Pile Superclass
#include "Deck.h"       //Deck derived Class
#include "Player.h"     //Player derived Class
using namespace std;    //STD Name-space where Library is compiled

//Function Prototypes
void draw(Deck &,Player &,int);
void setup(Deck &,Pile&);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables here
    Deck set;       //Set of Uno Cards
    Player plr1;    //Player 1
    Player plr2;    //Player 2
    Pile stack;     //Stack of Uno Cards
    short input;    //Input from player
    //Initialize variables here
    //Each Player Draws 7 Cards From the Deck
    draw(set,plr1,7);
    draw(set,plr2,7);
    //Draw a card for the pile
    setup(set,stack);
    
    //Display the results
    return 0;
}
//A player draws a card from the deck
void draw(Deck &set,Player &plr,int total){
    for(int i=0;i<total;i++){
        int index=set.getIndex();
        plr.draw(set.getColor(index),set.getValue(index));
        set.falsify(index);
    }
}
void setup(Deck &set,Pile &stack){
    int index=set.getIndex();
    stack.add(set.getColor(index),set.getValue(index));
    set.falsify(index);
}
