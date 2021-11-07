/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 29th 2021, 7:22PM
 * Purpose: Version 2 had to remodel my structures since I cannot 
 *          write structures containing pointers to binary files.
 */

//System Libraries Here
#include <cstdlib>  //rand()
#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strstr
#include <iomanip>  //setprecision,fixed,showpoint
#include <fstream>  //fstream,ios::binary|ios::in|ios::out
using namespace std;
//User Libraries Here
//Structures
struct Uno{                 //A single Uno Card
    char color;             //Color associated with uno card
    unsigned short value;   //Value associated with the card
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
enum Values{        //Card Values
    ZERO,ONE,TWO,THREE,FOUR,    //0-4
    FIVE,SIX,SEVEN,EIGHT,NINE,  //5-9
    SKIP,           //Skip Next Player's Turn
    REVERSE,        //Reverse The Turn Order
    DRAW,           //Next Person Draws a Card
    WILD,           //Wildcard
    DRAWWILD,       //Wildcard Draw +4 Cards
    RED,            //Red (15) + 32 = 0 (ascii)
    BLUE,           //Blue (16)+ 32 = 1 (ascii)
    GREEN,          //Green (17)+ 32 = 2 (ascii)
    YELLOW,         //Yellow (18)+ 32 = 3 (ascii)
    BLACK           //Black (19)+ 32 = 4 (ascii)
};
//Function Prototypes Here
Uno *cards(short);   //Creates a pointer to dynamically allocated deck
void define(Uno []);        //Define each card according to color
void destroy(Uno *);       //Deallocate memory
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    const unsigned short SZE=108;    //Size of Uno Deck
    fstream out;         //File where deck of uno cards will be written
    fstream in;          //File where deck of uno cards will be read
    Uno deck[SZE];       //deck of uno cards
    Uno *fSet;          //Deck of Uno Cards read from uno deck file
    Uno *player;        //Pointer to player's hand of uno cards
    //Input or initialize values Here
    //fSet=cards(SZE,CLR);    //Dynamically create memory for deck from file
    //player=cards(SZE,CLR);  //Dynamically create memory for player's hand
    define(deck);           //Define each uno card
    //Create player's hand of uno cards 
    //Write cards to binary file
    for(int i=ZERO;i<SZE;i++){
        cout<<"color "<<deck[i].color+0<<endl;
        cout<<"value "<<deck[i].value<<endl;
    }
    //Cleanup
    //destroy(player);
    //destroy(fSet);
    //Exit
    return 0;
}
//Creates a deck of uno cards
Uno *cards(short SZE,short CLR){
    Uno *ptr;
    ptr=new Uno[SZE];
    return ptr;
}
void define(Uno set[]){
    for(int i=0;i<108;i++){
        //First 25 cards are Green
        if(i<25){
            set[i].color=GREEN;
            i==ZERO?set[i].value=ZERO:
            i<=TWO?set[i].value=ONE:
            i<=FOUR?set[i].value=TWO:
            i<=SIX?set[i].value=THREE:
            i<=EIGHT?set[i].value=FOUR:
            i<=10?set[i].value=FIVE:
            i<=12?set[i].value=SIX:
            i<=14?set[i].value=SEVEN:
            i<=16?set[i].value=EIGHT:
            i<=18?set[i].value=NINE:
            i<=20?set[i].value=SKIP:
            i<=22?set[i].value=REVERSE:
            set[i].value=DRAW;
        //Next 25 are Blue
        }else if(i<50){
            set[i].color=BLUE;
            i==25?set[i].value=ZERO:
            i<=27?set[i].value=ONE:
            i<=29?set[i].value=TWO:
            i<=31?set[i].value=THREE:
            i<=33?set[i].value=FOUR:
            i<=35?set[i].value=FIVE:
            i<=37?set[i].value=SIX:
            i<=39?set[i].value=SEVEN:
            i<=41?set[i].value=EIGHT:
            i<=43?set[i].value=NINE:
            i<=45?set[i].value=SKIP:
            i<=47?set[i].value=REVERSE:
            set[i].value=DRAW;
        //Next 25 are Red
        }else if(i<75){
            set[i].color=RED;
            i==50?set[i].value=ZERO:
            i<=52?set[i].value=ONE:
            i<=54?set[i].value=TWO:
            i<=56?set[i].value=THREE:
            i<=58?set[i].value=FOUR:
            i<=60?set[i].value=FIVE:
            i<=62?set[i].value=SIX:
            i<=64?set[i].value=SEVEN:
            i<=66?set[i].value=EIGHT:
            i<=68?set[i].value=NINE:
            i<=70?set[i].value=SKIP:
            i<=72?set[i].value=REVERSE:
            set[i].value=DRAW;
        //Next 25 are Yellow
        }else if(i<100){
            set[i].color=YELLOW;
            i==75?set[i].value=ZERO:
            i<=77?set[i].value=ONE:
            i<=79?set[i].value=TWO:
            i<=81?set[i].value=THREE:
            i<=83?set[i].value=FOUR:
            i<=85?set[i].value=FIVE:
            i<=87?set[i].value=SIX:
            i<=89?set[i].value=SEVEN:
            i<=91?set[i].value=EIGHT:
            i<=93?set[i].value=NINE:
            i<=95?set[i].value=SKIP:
            i<=97?set[i].value=REVERSE:
            set[i].value=DRAW;
        //Last 8 are Black wildcards
        }else{
            set[i].color=BLACK;
            i<=103?set[i].value=WILD:
            set[i].value=DRAWWILD;
        }
    }
}
void destroy(Uno *set){
    delete [] set;
    delete set;
}