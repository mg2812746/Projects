#include "Pile.h"
//Constructor
Pile::Pile(){
    try{
        //Allocate enough memory for hands/deck
        all=new Uno [108];
        //Default size to 0
        size=0;
    }catch(...){
        cout<<"Error in Pile constructor"
            <<endl;
    }
}
//Assigns a color and value to card
void Pile::add(char *colr, int val){
    try{
        all[size]=colr;
        all[size]=val;
        //Increment total size of pile
        upSize();
    }catch(...){
        cout<<"Error in add() member function in Pile"
            <<endl;
    }
}