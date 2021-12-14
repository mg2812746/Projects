#include "Uno.h"
#include "Deck.h"
#include <iostream>
#include <iomanip>
//Copy Constructor-Copies the color of Uno card referenced
Uno::Uno(const char xColor[]){
    //Get the size of the Uno object
    int i=0;    //Size of Uno object
    for(;xColor[i]!='\0';i++);
    //Dynamically size color
    color= new char [i];
    //Copy the color from one Uno card to the other
    for(int j=0;j<i;j++){
        color[j]=xColor[j];
    }
}
//Definition of overloaded assignment operator
void Uno::operator=(const char xColor[]){
    //Get the size of the Uno object
    int i=0;    //Size of Uno object
    for(;xColor[i]!='\0';i++);
    //Dynamically size color
    color= new char [i];
    //Copy the color from one Uno card to the other
    for(int j=0;j<i;j++){
        color[j]=xColor[j];
    }
    return *this;
}
void Uno::operator=(const short x){
    //Assign x to value
    value=x;
    return *this;
}
bool Uno::operator==(const char x[]){
    int i=0;    //Size of Uno object
    for(;x[i]!='\0';i++);
    for(int j=0;j<i;j++){
        if(x[j]!=color[j]){
            return this->false;
        }
    }
    return true;
}
bool Uno::operator==(const short x){
    if(x!=value){
        return false;
    }
    return true;
}
void Uno::getColor()const{
    std::cout<<color<<std::endl;
}
