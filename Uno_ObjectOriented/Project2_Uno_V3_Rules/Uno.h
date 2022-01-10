/* 
 * File:   Uno.h
 * Author: Miguel Galvez
 * Created on December 13, 2021, 3:52 PM
 * Purpose: Uno class, create a basic definition/characteristic 
 *          of an Uno card.
 */

#ifndef UNO_H
#define UNO_H
//Enumerated Values
enum Values{        //Card Values
    ZERO,ONE,TWO,THREE,FOUR,    //0-4
    FIVE,SIX,SEVEN,EIGHT,NINE,  //5-9
    SKIP,           //Skip Next Player's Turn
    REVERSE,        //Reverse The Turn Order
    DRAW,           //Next Person Draws a Card
    WILD,           //Wildcard (Pick a color for pile)
    DRAWWILD        //Wildcard Draw +4 Cards
};
//Uno Class
class Uno{
private: 
    char *color;     //Color associated with Uno card       
    int value;       //Value associated with Uno card
public:
    Uno(){color=new char [8];}      //Default constructor
    Uno(char *x,short y){color=x;   //Constructor 2 (overloading)
                        value=y;}   
    Uno(const char []);                 //Copy constructor
    virtual ~Uno(){delete [] color;}    //Destructor                                   
    void operator=(const char[]);       //Assign card color to string   
    void operator=(const short x);      //Assign value of card
    virtual bool operator==(const char x[]);    //Assign value of card
    virtual bool operator==(const short x);     //Assign value of card
    virtual char *getColor()const{return color;};//get color
    virtual int getValue(){return value;}  //returns value
    virtual void setColor(char *);         //Mutator-sets color of card
    virtual void setValue(int);            //Mutator-sets value of card
};
#endif /* UNO_H */