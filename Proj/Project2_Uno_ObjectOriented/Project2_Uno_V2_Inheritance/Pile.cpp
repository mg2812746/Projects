#include "Pile.h"
//Constructor
Pile::Pile(){
    //Allocate enough memory for hands/deck
    all=new Uno [108];
    //Default to 0
    size=0;
}
void Pile::add(char *colr, int val){
    all[size]=colr;
    all[size]=val;
    upSize();
}