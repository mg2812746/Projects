/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 17, 2021, 8:46 PM
 * Purpose: Uno Version 3, create general outline
 *          of game. Rules, input, etc.
 */

//System Libraries
#include <iostream>     //Input/Output Library
#include <ctime>        //time()
#include <cstdlib>      //rand()
#include <cstring>      //strcmp()
#include "Uno.h"        //Uno Class
#include "Pile.h"       //Pile Superclass
#include "Deck.h"       //Deck derived Class
#include "Player.h"     //Player derived Class
using namespace std;    //STD Name-space where Library is compiled

//Function Prototypes
void draw(Deck &,Player &,int);
void setup(Deck &,Uno&);
void toss(Uno &,Player &,int);
void show(Uno&);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables here
    Deck set;       //Set of Uno Cards
    Player plr1;    //Player 1
    Player plr2;    //Player 2
    Uno top;        //Stack of Uno Cards
    short input;    //Input from player
    //Each Player Draws 7 Cards From the Deck
    try{
        draw(set,plr1,7);
        draw(set,plr2,7);
    }catch(...){
        cout<<"There was an error in an attempt to"
            <<" draw 7 cards for each player."
            <<endl;
    }
    //Draw a card for the pile
    try{
        setup(set,top);
    }catch(...){
        cout<<"There was an error when drawing a "
            <<"card for the top card."<<endl;
    }
    //Continue the game until one player doesn't have any cards
    while(plr1.getSize()!=0&&plr2.getSize()!=0){
        //If flag is not set to skip player 1
        if(!plr1.getSkip()){
        //Prompt user to enter 1 before showing cards
            cout<<"Player 1's turn: Enter 1 to continue.";
            do{
                //Exception 1 - if a number other than 1 was entered
                try{
                    cin>>input;
                    if(input!=1){
                        throw 0;
                    }
                }catch(...){
                    cout<<"Error: Number was not 1"<<endl;
                    //Clear the previous input
                    cin.clear();
                    //Discard the previous input
                    cin.ignore();
                }
            }while(input!=1);
            //Display player 1's hand
            plr1.hand();
            //Display card on the pile
            show(top);
            //Prompt for a Card Number to toss to the pile
            cout<<"Enter a Card # to toss to the pile. Or "
                <<"enter 100 to draw: ";
            do{
                //Exception handling
                try{
                    cin>>input;
                    //If input was not 100, and if colors do not 
                    //match and if values do not match, and 
                    //if it's not a wildcard
                    if(input!=100&&strstr(plr1.getColor(input),
                        top.getColor())==NULL
                        &&(plr1.getValue(input)!=
                        top.getValue())&&
                        plr1.getValue(input)<WILD){
                        throw 0;
                    }
                }catch(...){
                    cout<<"error: please enter a valid card number "
                        <<"or 100 to draw a card";
                    //Clear the previous input
                    cin.clear();
                    //Discard the previous input
                    cin.ignore();
                }
                //If input was not 100, and if colors do not 
                //match and if values do not match, and 
                //if it's not a wildcard
            }while(input!=100&&strstr(plr1.getColor(input),
                    top.getColor())==NULL
                    &&(plr1.getValue(input)!=
                    top.getValue())&&
                    plr1.getValue(input)<WILD);
            while(input==100){   
                draw(set,plr1,1);
                //Show player 1's hands
                plr1.hand();
                //Display card on top of pile
                show(top);
                cout<<"Enter the card # to throw to the pile. \n"
                    <<"Or enter 100 to draw. \n";
                do{
                    try{
                        cin>>input;
                        //Display choices
                        if(input!=100&&strstr(plr1.getColor(input),
                        top.getColor())==NULL
                        &&(plr1.getValue(input)!=
                        top.getValue())&&
                        plr1.getValue(input)<WILD){
                            throw 0;
                        }
                    }catch(...){
                        cout<<"Error: enter a valid number."<<endl
                            <<"Otherwise, enter 100 to draw: "<<endl;
                        //Clear the previous input
                        cin.clear();
                        //Discard the previous input
                        cin.ignore();
                    }
                    //Input Validation 
                }while(input!=100&&strstr(plr1.getColor(input),
                        top.getColor())==NULL
                    &&(plr1.getValue(input)!=
                    top.getValue())&&
                    plr1.getValue(input)<WILD);
            }
            //If input was skip and same color as pile
            if(plr1.getValue(input)==SKIP&&
                    strstr(plr1.getColor(input),
                        top.getColor())!=NULL){
                //Exception handling
                try{
                    //Toss to pile
                    toss(top,plr1,input);
                    plr2.set();     //Set the skip flag
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"SKIP if statement"<<endl;
                }
            //If value is reverse and same color as pile
            }else if(plr1.getValue(input)==REVERSE&&
                    strstr(plr1.getColor(input),
                        top.getColor())!=NULL){
                //Exception handling
                //Toss to pile
                try{
                    toss(top,plr1,input);
                    plr2.set();     //Set the skip flag
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"REVERSE if statement "<<endl;
                }
            //If value is draw +1 and same color as pile
            }else if(plr1.getValue(input)==DRAW&&
                    strstr(plr1.getColor(input),
                        top.getColor())!=NULL){
                try{
                    //Toss to pile
                    toss(top,plr1,input);
                    draw(set,plr2,1);   //Player 2 draws a card
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"DRAW if statement "<<endl;
                }
            //If value is a wildcard, toss and pick color for pile
            }else if(plr1.getValue(input)==WILD){
                try{
                    //Toss to pile
                    toss(top,plr1,input);
                    top=plr1.wild();    //Player 1 assigns a color
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"WILD if statement "<<endl;
                }
            //If value is wildcard draw +4, toss and make player draw 4 cards
            }else if(plr1.getValue(input)==DRAWWILD){
                try{
                    //Toss to pile
                    toss(top,plr1,input);
                    top=plr1.wild();    //Player 1 assigns a color
                    draw(set,plr2,4);   //Player 2 draws 4 cards
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"DRAWWILD if statement "<<endl;
                }
            }
            //Otherwise just toss the card to the pile
            else{
                try{
                    toss(top,plr1,input);
                }catch(...){
                    cout<<"Error in player 1's "
                        <<"else statement "<<endl;
                }
            }
        //Skip player's turn and reset skip flag
        }else{
            plr1.reset();
        }
        //Check to make sure player 1 didn't already win
        if(plr1.getSize()!=0){
            //If flag is not set to skip player 1
            if(!plr2.getSkip()){
                //Prompt user to enter 1 before showing cards
                cout<<"Player 2's turn: Enter 1 to continue.";
                do{
                    //Exception 0 - if a number other than 1 was entered
                    try{
                        cin>>input;
                        if(input!=1){
                            throw 0;
                        }
                    }catch(...){
                        cout<<"Error: Number was not 1"<<endl;
                        //Clear the previous input
                        cin.clear();
                        //Discard the previous input
                        cin.ignore();
                    }
                }while(input!=1);
                //Display player 2's hand
                plr2.hand();
                //Display card on top of pile
                show(top);
                cout<<"Enter the card # to throw to the pile. \n"
                    <<"Or enter 100 to draw. \n";
                //Exception handling, If an invalid card was entered, 
                //prod the player to enter an acceptable card or 100 to 
                //draw
                do{
                    //Exception handling
                    try{
                        //If input was not 100, and if colors do not 
                        //match and if values do not match, and 
                        //if it's not a wildcard
                        cin>>input;
                        if(input!=100&&strstr(plr2.getColor(input),
                            top.getColor())==NULL
                        &&(plr2.getValue(input)!=
                        top.getValue())&&
                        (plr2.getValue(input)<WILD)){
                            throw 0;
                        }
                    }catch(...){
                        cout<<"Error: enter a valid number."<<endl
                            <<"Otherwise, enter 100 to draw: "<<endl;
                        //Clear the previous input
                        cin.clear();
                        //Discard the previous input
                        cin.ignore();
                    }
                }while(input!=100&&strstr(plr2.getColor(input),
                    top.getColor())==NULL
                    &&(plr2.getValue(input)!=
                    top.getValue())&&
                    plr2.getValue(input)<WILD);
                //While the input is 100
                while(input==100){   
                    draw(set,plr2,1);
                    //Show player 1's hands
                    plr2.hand();
                    //Display card on top of pile
                    show(top);
                    cout<<"Enter the card # to throw to the pile. \n"
                        <<"Or enter 100 to draw. \n";
                    //Exception Handling
                    do{
                        //Exception handling
                        try{
                            cin>>input;
                            if(input!=100&&strstr(plr2.getColor(input),
                            top.getColor())==NULL
                            &&(plr2.getValue(input)!=
                            top.getValue())&&
                            plr2.getValue(input)<WILD){
                                throw 0;
                            }
                        }catch(...){
                            cout<<"Error: enter a valid number."<<endl
                                <<"Otherwise, enter 100 to draw: "<<endl;
                            //Clear the previous input
                            cin.clear();
                            //Discard the previous input
                            cin.ignore();
                        }
                        //Input Validation 
                    }while(input!=100&&strstr(plr2.getColor(input),
                            top.getColor())==NULL
                        &&(plr2.getValue(input)!=
                        top.getValue())&&
                        plr2.getValue(input)<WILD);
                }
                //If input was skip and same color as pile
                if(plr2.getValue(input)==SKIP&&
                        strstr(plr2.getColor(input),
                            top.getColor())!=NULL){
                    //Toss to pile
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                    //Exception handling
                    try{
                        plr1.set();     //Set the skip flag for player 1
                    }catch(...){
                        cout<<"There was an error"
                            <<" in an attemp to set plr 1's skip flag. "
                            <<endl;
                    }
                //If value is reverse and same color as pile
                }else if(plr2.getValue(input)==REVERSE&&
                        strstr(plr2.getColor(input),
                            top.getColor())!=NULL){
                    //Toss to pile
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                    plr1.set();     //Set the skip flag for player 1
                //If value is draw +1 and same color as pile
                }else if(plr2.getValue(input)==DRAW&&
                        !strstr(plr2.getColor(input),
                            top.getColor())==NULL){
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                    draw(set,plr1,1);
                //If value is a wildcard, toss and pick color for pile
                }else if(plr2.getValue(input)==WILD){
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                    top=plr2.wild();
                //If the card is a wildcard draw+4, toss 
                //and make other player draw four cards
                }else if(plr2.getValue(input)==DRAWWILD){
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                    //Exception handling
                    try{
                        top=plr2.wild();
                    }catch(...){
                        cout<<"there was an error when assigning top"
                            <<"to the player 2 wild member function."
                            <<endl;
                    }
                    draw(set,plr1,4);
                //Otherwise, simply toss the card onto the pile
                }else{
                    //Exception handling
                    try{
                        toss(top,plr2,input);
                    }catch(...){
                        cout<<"There was an error "
                            <<"when tossing a card."<<endl;
                    }
                }
            //If skip flag was set for player, reset the flag
            }else{
                //Exception handling
                try{
                    plr2.reset();
                }catch(...){
                    cout<<"There was an error when "
                        <<"resetting player 2's skip flag"<<endl;
                }
            }
        }
    }
    //Exception handling
    try{
        //Congratulate Winner
        plr1.getSize()==0?cout<<"Congratulations! Player 1 wins."<<endl:
                        cout<<"Congratulations! Player 2 wins."<<endl;
    }catch(...){
        cout<<"There was an error when "
            <<"the player was congratulated."<<endl;
    }
    //Exit
    return 0;
}
//A player draws a card from the deck
void draw(Deck &set,Player &plr,int total){
    int index;
    for(int i=0;i<total;i++){
    //Exception handling, when deck is empty
        try{
    //Generate a random valid index from the deck
            index=set.getIndex();
            //If we no longer have any cards in the deck
            if(set.getSize()==0){
                throw 5;
            }
        }catch(...){
            //Reset the status array/reshuffle all cards back into deck
            set.reset();
            //Try getting another acceptable index
            index=set.getIndex();
        }
    //Draw a card onto the player's hand
        try{
        plr.draw(set.getColor(index),set.getValue(index));
        }catch(...){
            cout<<"There was an error drawing a card "
                <<"for the player. "<<endl;
        }
    //Invalidate the index used on the stat array
        try{
        set.falsify(index);
        }catch(...){
            cout<<"There was an error falsifying an index. "
                <<endl;
        }
    }
}
void setup(Deck &set,Uno &top){
    //Exception handling - when the setup fails
    try{
        //Generate a random valid index from the deck
        int index=set.getIndex();
        //Replace the color and value of the top card of the deck
        top.setColor(set.getColor(index));
        top.setValue(set.getValue(index));
        //Invalidate the index used on the stat array
        set.falsify(index);
    }catch(...){
        cout<<"There was an error in the setup."<<endl;
    }
}
void toss(Uno &top,Player &plr,int input){
    //Exception handling - if an error was detected tossing a card
    try{
        //Replace the color and value of the top card with player's card
        top.setColor(plr.getColor(input));
        top.setValue(plr.getValue(input));
        //Remove the indexed card from the player
        plr.remove(input);
    }catch(...){
        cout<<"There was an error when tossing "
            <<"the card to the pile."<<endl;
    }
}
//Display the top card 
void show(Uno &top){
    //Exception handling- if an error was detected outputting color
    try{
        cout<<"Card on \ntop \nof pile: ";
        cout<<top.getColor()<<" ";
        top.getValue()==SKIP?cout<<"SKIP"<<endl:
        top.getValue()==REVERSE?cout<<"REVERSE"<<endl:
        top.getValue()==DRAW?cout<<"DRAW +1"<<endl:
        top.getValue()==WILD?cout<<"WILDCARD"<<endl:
        top.getValue()==DRAWWILD?cout<<"DRAW+4"<<endl:
        cout<<top.getValue()<<endl;
    }catch(...){
        cout<<"There was an error "
            <<"displaying the color."<<endl;
    }
}