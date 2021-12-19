#include "Deck.h"
#include <iostream>
//Default Constructor
Deck::Deck(){
    try{
        //Default Size to 108
        size=108;
        //Default every value in status array to true
        //Indicating that every card is in the deck
        for(int i=0;i<size;i++){
            stat[i]=1;
        }
        //Define our deck of Uno cards
        define();
    }catch(...){
        cout<<"Error in Deck constructor"<<endl;
    }
}
//Define all Uno cards to deck
void Deck::define(){
    //Define x of Uno cards
    try{
        for(int i=0;i<size;i++){
            //First 25 cards are Green
            if(i<25){
                all[i]="Green";
                i==0?all[i]=ZERO:
                i<=2?all[i]=ONE:
                i<=4?all[i]=TWO:
                i<=6?all[i]=THREE:
                i<=8?all[i]=FOUR:
                i<=10?all[i]=FIVE:
                i<=12?all[i]=SIX:
                i<=14?all[i]=SEVEN:
                i<=16?all[i]=EIGHT:
                i<=18?all[i]=NINE:
                i<=20?all[i]=SKIP:
                i<=22?all[i]=REVERSE:
                all[i]=DRAW;
            //Next 25 are Blue
            }else if(i<50){
                all[i]="Blue";
                i==25?all[i]=ZERO:
                i<=27?all[i]=ONE:
                i<=29?all[i]=TWO:
                i<=31?all[i]=THREE:
                i<=33?all[i]=FOUR:
                i<=35?all[i]=FIVE:
                i<=37?all[i]=SIX:
                i<=39?all[i]=SEVEN:
                i<=41?all[i]=EIGHT:
                i<=43?all[i]=NINE:
                i<=45?all[i]=SKIP:
                i<=47?all[i]=REVERSE:
                all[i]=DRAW;
            //Next 25 are Red
            }else if(i<75){
                all[i]="Red";
                i==50?all[i]=ZERO:
                i<=52?all[i]=ONE:
                i<=54?all[i]=TWO:
                i<=56?all[i]=THREE:
                i<=58?all[i]=FOUR:
                i<=60?all[i]=FIVE:
                i<=62?all[i]=SIX:
                i<=64?all[i]=SEVEN:
                i<=66?all[i]=EIGHT:
                i<=68?all[i]=NINE:
                i<=70?all[i]=SKIP:
                i<=72?all[i]=REVERSE:
                all[i]=DRAW;
            //Next 25 are Yellow
            }else if(i<100){
                all[i]="Yellow";
                i==75?all[i]=ZERO:
                i<=77?all[i]=ONE:
                i<=79?all[i]=TWO:
                i<=81?all[i]=THREE:
                i<=83?all[i]=FOUR:
                i<=85?all[i]=FIVE:
                i<=87?all[i]=SIX:
                i<=89?all[i]=SEVEN:
                i<=91?all[i]=EIGHT:
                i<=93?all[i]=NINE:
                i<=95?all[i]=SKIP:
                i<=97?all[i]=REVERSE:
                all[i]=DRAW;
            //Last 8 are Black wildcards
            }else{
                all[i]="Black";
                i<=103?all[i]=WILD:
                all[i]=DRAWWILD;
            }
        }
    }catch(...){
        cout<<"There was an error when "
            <<"defining the deck of Uno"
            <<"cards. (inside of Deck constructor)"
            <<endl;
    }
}
//Displays the entire array of cards from deck
void Deck::display(){
    int temp;
    try{
        for(int i=0;i<getTotal();i++){
            std::cout<<"Card #: "<<i<<std::endl
                     <<"Color: "<<all[i].getColor();
            temp=all[i].getValue();
            std::cout<<"Value: ";
            temp==SKIP?std::cout<<"SKIP"<<std::endl:
            temp==REVERSE?std::cout<<"REVERSE"<<std::endl:
            temp==DRAW?std::cout<<"DRAW+1"<<std::endl:
            temp==WILD?std::cout<<"WILD"<<std::endl:
            temp==DRAWWILD?std::cout<<"DRAW+4"<<std::endl:
            std::cout<<temp<<std::endl;
        }
    }catch(...){
        cout<<"There was an error in display()"
            <<" deck member function. "<<endl;
    }
}
//Returns true or false depending on whether the card was 
//available in deck
bool Deck::status(int indx){
    try{
        if(stat[indx]){
            return true;
        }
        return false;
    }catch(...){
        cout<<"Error: in status member function (deck.cpp)"
            <<endl;
    }
}
//Returns the color of the specified card 
char *Deck::getColor(int indx)const{
    try{
        return all[indx].getColor();
    }catch(...){
        cout<<"There was an error in "
            <<"getColor() deck member function"<<endl;
    }
}
//Returns the value of the specified card
short Deck::getValue(int indx)const{
    try{
        return all[indx].getValue();
    }catch(...){
        cout<<"Error in getValue() deck member function"
            <<endl;
    }
}
//Invalidates the entry from the status array
void Deck::falsify(int indx){
    try{
        stat[indx]=0;
    }catch(...){
        cout<<"There was an error in falsify "
            <<"deck member function "<<endl;
    }
}
//Generates an index that we can draw from
int Deck::getIndex(){
    try{
        //Assign random number to index 0-108
        int index=rand()%getTotal();
        //Keep trying a random number until the number is valid
        while(!status(index)){
            index=rand()%getTotal();
        }
        return index;
    }catch(...){
        cout<<"Error in getIndex() Deck member function."
            <<endl;
    }
}
//Resets the status array so that all cards are available for drawing again
void Deck::reset(){
    try{
        //Only activated if there are no more cards in the deck
        for(int i=0;i<getTotal();i++){
            stat[i]=1;
        }
    }catch(...){
        cout<<"There was an error in the reset() "
            <<"member function"<<endl;
    }
}