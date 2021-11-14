/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 13th 2021, 7:22PM
 * Purpose: Lastly, we will move function prototypes
 *          /structures/libraries to our header file and function
 *          declarations to their own .cpp file
 */

//System Libraries Here
#include "uno.h"
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Generator Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    const short SZE=108;    //Uno Deck Size
    const short PLR=54;     //Player hand size
    bool stat[SZE]; //Status of Deck array
    bool skip=0;    //Skip flag
    fstream in;     //input file
    fstream out;    //output file
    Deck set;       //Deck of uno cards
    Deck fSet;      //Deck of uno cards from file
    Deck plr1;      //Player 1
    Deck plr2;      //Player 2
    Uno pile;       //Current card on the pile
    int input;      //user input
    string in1;     //First user input
    //Display Uno game header
    cout<<"Welcome to the game of Uno! "<<endl
        <<"Enter 0 to begin, or anything else to "
        <<"end this program. ";
    cin>>in1;
    if(in1[0]==48&&size(in1)==1){
        //Dynamically Allocate Memory for Deck and Players
        create(set,fSet,SZE);
        create(plr1,plr2,PLR);
        //Players start off with 0 cards before drawing 
        //Define Uno Cards for Deck
        define(&set);
        //Write and read deck of cards
        wrteRd(set,fSet,out,in);
        //Default bool values to true
        for(int i=0;i<SZE;i++)
            stat[i]=1;
        //Draw cards from fSet into Players
        draw7(plr1,plr2,fSet,stat,SZE);
        //Draw a card for pile
        draw(stat,SZE,pile,fSet);
        while(plr1.size!=0&&plr2.size!=0){
            if(skip==0){
                //Show player 1's hands
                cout<<"Player 1's hand: "<<endl;
                display(&plr1);
                //Display card on top of pile
                cout<<"Card on \ntop \nof pile: ";
                show(&pile);
                //Prompt player 1 for an applicable card to throw to the pile
                //Otherwise draw a card
                cout<<"Enter the card # to throw to the pile. "<<endl
                    <<"Otherwise, enter 100 to draw: ";
                cin>>input;
                //Input Validation 
                while(input!=100&&strcmp(plr1.all[input].color,pile.color)
                    &&plr1.all[input].value!=pile.value&&
                    plr1.all[input].value<WILD){
                    cout<<"Error: enter a valid number."<<endl;
                    cout<<"Enter the card # to throw to the pile. "<<endl
                        <<"Otherwise, enter 100 to draw: ";
                    cin>>input;
                }
                //If card is valid, toss card onto pile
                if(input==100){   
                    draw1(plr1,fSet,stat,SZE);
                //If value is skip and same color as pile
                }else if(plr1.all[input].value==SKIP&&
                        !strcmp(plr1.all[input].color,pile.color)){
                    toss(plr1,pile,input);
                    skip=1;     //Set the skip flag
                //If value is reverse and same color as pile
                }else if(plr1.all[input].value==REVERSE&&
                        !strcmp(plr1.all[input].color,pile.color)){
                    toss(plr1,pile,input);
                //If value is draw +1 and same color as pile
                }else if(plr1.all[input].value==DRAW&&
                        !strcmp(plr1.all[input].color,pile.color)){
                    toss(plr1,pile,input);
                    draw1(plr2,fSet,stat,SZE);
                //If color is the same as pile
                }else if(!strcmp(plr1.all[input].color,pile.color)){
                    toss(plr1,pile,input);
                //If value is the same as pile
                }else if(plr1.all[input].value==pile.value){
                    toss(plr1,pile,input);
                //If value is a wildcard, toss and pick color for pile
                }else if(plr1.all[input].value==WILD){
                    wild(plr1,pile,input);
                //If value is wildcard +4, toss, pick color for pile
                //and make next player draw four cards
                }else if(plr1.all[input].value==DRAWWILD){
                    wild(plr1,pile,input);
                    //Now plr2 needs to draw 4 cards
                    draw4(plr2,fSet,stat,SZE);
                }
            //If skip flag is set, skip player's turn and reset flag
            }else{
                skip=0;
            }
            if(skip==0){
                //Display player 2's hand
                cout<<"Player 2's hand: "<<endl;   
                display(&plr2);
                //Display top of pile
                cout<<"Card on \ntop \nof pile: ";
                show(&pile);
                //Prompt player 1 for an applicable card to throw 
                //to the pile. Otherwise, draw a card
                cout<<"Enter the card # to throw to the pile. "<<endl;
                cin>>input;
                //Input Validation
                while(input!=100&&strcmp(plr2.all[input].color,pile.color)
                    &&plr2.all[input].value!=pile.value
                    &&plr2.all[input].value<WILD){
                    cout<<"Error: enter a valid number."<<endl;
                    cout<<"Enter the card # to throw to the pile. \n"
                        <<"Or enter 100 to draw. \n";
                    cin>>input;
                }   
                //If card is valid, toss card onto pile
                if(input==100){
                    draw1(plr2,fSet,stat,SZE);
                }else if(plr2.all[input].value==SKIP){
                    toss(plr2,pile,input);
                    skip=1;     //Set the skip flag
                //If card is reverse and same color as pile
                }else if(plr2.all[input].value==REVERSE&&
                        !strcmp(plr2.all[input].color,pile.color)){
                    toss(plr2,pile,input);
                //If card is draw +1 and same color as pile
                }else if(plr2.all[input].value==DRAW&&
                        !strcmp(plr2.all[input].color,pile.color)){
                    toss(plr2,pile,input);
                    //Make player 1 draw a card
                    draw1(plr1,fSet,stat,SZE);
                //If card is same color as pile
                }else if(!strcmp(plr2.all[input].color,pile.color)){
                    toss(plr2,pile,input);
                //If card is same value as pile
                }else if(plr2.all[input].value==pile.value){
                    toss(plr2,pile,input);
                //If card is a wildcard, pick a color for pile
                }else if(plr2.all[input].value==WILD){
                    wild(plr2,pile,input);
                //If card is wildcard draw +4, pick a color for pile
                //and next player draws 4 cards
                }else if(plr1.all[input].value==DRAWWILD){
                    wild(plr2,pile,input);
                    //Make player 1 draw four cards
                    draw4(plr1,fSet,stat,SZE);
                }
            //If skip flag is set, skip player and reset flag
            }else{
                skip=0;
            }
        }
        //Congratulate Winner
        plr1.size==0?cout<<"Congratulations! Player 1 wins."<<endl:
                     cout<<"Congratulations! Player 1 wins."<<endl;
    //Cleanup
    destroy(set,fSet,plr1,plr2);
    }
    //Exit
    return 0;
}