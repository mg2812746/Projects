#include "Uno.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//Copy Constructor-Copies the color of Uno card referenced
Uno::Uno(const char xColor[]){
    try{
        //Get the size of the Uno object
        int i=0;    //Size of Uno object
        for(;xColor[i]!='\0';i++);
        //Dynamically size color
        color= new char [i];
        //Copy the color from one Uno card to the other
        for(int j=0;j<i;j++){
            color[j]=xColor[j];
        }
    }catch(...){
        cout<<"Error in Uno() copy constructor"<<endl;
    }
}
//Assign color to Uno class
void Uno::operator=(const char xColor[]){
    try{
        strcpy(color,xColor);
    }catch(...){
        cout<<"error in overloaded operator= const char"
            <<"in Uno class"<<endl;
    }
}
//Assign the short value to Uno class with assignment operator
void Uno::operator=(const short x){
    try{
    //Assign x to value
    value=x;
    }catch(...){
        cout<<"Error in overloaded operator= "
            <<"const short Uno class"<<endl;
    }
}
//Our own comparison with Uno object and string
bool Uno::operator==(const char x[]){
    try{
        int i=0;    //Size of Uno object
        for(;x[i]!='\0';i++);
        for(int j=0;j<i;j++){
            if(x[j]!=color[j]){
                return false;
            }
        }
        return true;
    }catch(...){
        cout<<"Error in overloaded operator=="
            <<"const char in Uno.cpp"<<endl;
    }
}
//Comparison between Uno object and short 
bool Uno::operator==(const short x){
    try{
        if(x!=value){
            return false;
        }
        return true;
    }catch(...){
        cout<<"Error in overloaded operator=="
            <<"const char in Uno.cpp"<<endl;
    }
}
//Sets the color for an Uno card
void Uno::setColor(char x[]){
    try{
        strcpy(color,x);
    }catch(...){
        cout<<"Error in setColor() inside Uno class"
            <<endl;
    }
}
//Sets the value for an Uno card
void Uno::setValue(int x){
    try{
        value=x;
    }catch(...){
        cout<<"Error in setValue() inside Uno class"
            <<endl;
    }
}