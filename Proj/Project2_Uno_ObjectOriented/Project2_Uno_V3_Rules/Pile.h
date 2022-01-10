/* 
 * File:   Pile.h
 * Author: Miguel Galvez
 * Created on December 17, 2021, 9:16 PM
 * Purpose: Pile class, a general skeleton of an Uno Pile
 *          which can later be used for inheritance
 */

#ifndef PILE_H
#define PILE_H
#include "Uno.h"
#include <iostream>
using namespace std;
//Pile Class
class Pile{
protected:
    Uno *all;
    short size;
public:
    Pile();                             //Pile Constructor
    virtual ~Pile(){delete [] all;};    //Pile Destructor
    virtual void modSize(short x){size+=x;};    //With a given value- size is 
                                                //modified
    virtual void upSize(){size++;};     //Increments size
    virtual void downSize(){size--;};   //Decrements size
    virtual short getSize()const{return size;}; //Returns size
    virtual short getTotal()const{return 108;}; //Returns size of standard
                                                //Uno Deck
    virtual char *getColor(int i){return all[i].getColor();};//Returns color
    virtual short getValue(int i){return all[i].getValue();};//Returns value
    virtual void add(char*,int);    //Assigns a color an Uno card in Pile
    //Returns the card on top of the pile
    virtual void top(){cout<<getColor(size-1)<<" "<<getValue(size)<<endl;};
    //Overloaded operator, increments size
    virtual void operator++(){size++;}; //Increments size
};
#endif /* PILE_H */