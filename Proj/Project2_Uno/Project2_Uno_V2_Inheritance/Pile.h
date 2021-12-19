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
class Pile{
protected:
    Uno *all;
    short size;
public:
    Pile();
    virtual ~Pile(){delete [] all;};
    virtual void modSize(short x){size+=x;};
    virtual void upSize(){size++;};
    virtual void downSize(){size--;};
    virtual short getSize()const{return size;};
    virtual short getTotal()const{return 108;};
    virtual char *getColor(int i){return all[i].getColor();};
    virtual short getValue(int i){return all[i].getValue();};
    virtual void add(char*,int);
    virtual void top(){cout<<getColor(size-1)<<" "<<getValue(size)<<endl;};
    
};


#endif /* PILE_H */

