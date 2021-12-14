/* 
 * File:   Pile.h
 * Author: Miguel Galvez
 * Created on December 13, 2021, 6:37 PM
 * Purpose: Aggregate Pile derived class from Deck
 */
#include "Uno.h"
#ifndef PILE_H
#define PILE_H

class Pile{
protected:
    static short size;      //Size of Uno Deck
    Uno *all;               //Pointer to an array of Uno objects
public:
    Pile(){size=0;}         //Default Constructor
    Pile(const short x){all=new Uno [x];    //Constructor 1
                        size=x;}            
    Pile(Uno *x,short y){all=x,size=y;}     //Constructor 2     
    virtual ~Pile(){delete [] all;}         //Destructor    
    virtual short getSize()const            //Returns the size of deck
    {return size;}     
    virtual void display()const;
    virtual void operator++(){size++;}
};


#endif /* PILE_H */

