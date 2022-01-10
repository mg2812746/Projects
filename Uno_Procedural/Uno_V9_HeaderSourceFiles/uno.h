/* 
 * File:   uno.h
 * Author: Miguel Galvez
 * Purpose: Store all function prototypes/libraries/enums
 * Created on November 13, 2021, 3:14 PM
 */

#ifndef UNO_H
#define UNO_H

#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strcmp
#include <iomanip>  //xprecision,fixed,showpoint
#include <fstream>  //file operations
#include <string>   //string class
#include <ctime>    //time()
#include <cstdlib>  //rand()
#include <valarray>  
using namespace std;
//User Libraries Here
//Structures
struct Uno{                 //Deck of Uno Cards
    char color[8];          //Color associated with uno card
    unsigned short value;   //Value associated with the card
};
struct Deck{        //Structure of structure containing deck of uno cards
    unsigned short size;        //Size of Uno Deck
    Uno *all;                   //Data of all uno cards
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
enum Values{        //Card Values
    ZERO,ONE,TWO,THREE,FOUR,    //0-4
    FIVE,SIX,SEVEN,EIGHT,NINE,  //5-9
    SKIP,           //Skip Next Player's Turn
    REVERSE,        //Reverse The Turn Order
    DRAW,           //Next Person Draws a Card
    WILD,           //Wildcard (Pick a color for pile)
    DRAWWILD        //Wildcard Draw +4 Cards
};
//Function Prototypes Here
void create(Deck&,Deck&,short); //Dynamically allocate memory
void define(Deck *);            //Define Uno cards
void destroy(Deck&,Deck&,Deck&,Deck&);  //Cleanup
void display(Deck *);           //Display hand 
void draw(bool [],short,Uno &,Deck);    //Draw a single card to pile
void draw1(Deck&,Deck,bool[],short);    //Draw a single card to hand
void draw4(Deck&,Deck,bool[],short);    //Draw four cards to hands
void draw7(Deck&,Deck&,Deck,            //Draw seven cards to hands
            bool [],short); 
void show(Uno *);               //Show the top of pile
void toss(Deck&,Uno&,int);      //Toss card from player's hand to pile
void wild(Deck&,Uno&,int);      //Handle case for wildcard 
void wrteRd(Deck &set,Deck &fSet,//Write entire deck of uno cards to file
        fstream &out,fstream &in);//and read file into another deck
#endif /* UNO_H */

