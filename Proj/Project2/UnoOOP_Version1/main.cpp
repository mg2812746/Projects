/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 13, 2021, 3:51 PM
 * Purpose: Uno OOP Version 1
 *          We will begin with our classes for our Uno game. We will create
 *          an Uno deck and Uno card class. We will also feature their
 *          respective constructor/destructors.
 */

//System Libraries
#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strcmp
#include <iomanip>  //xprecision,fixed,showpoint
#include <string>   //string class
#include <valarray> //
#include <ctime>    //time()
#include <cstdlib>  //rand()
#include "Uno.h"    //Uno class
#include "Deck.h"   //Deck Derived class
#include "Pile.h"   //Pile class
using namespace std;
//Function Prototypes

//Code Begins Execution Here with function main

int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables here
    const short SZE=108;    //Uno Deck Size
    const short PLR=54;     //Player hand size
    bool stat[SZE];         //Status of Deck array
    bool skip=0;            //Skip flag
    Deck set(SZE);
    //Initialize variables here
    set.define();
    //Map inputs to outputs here, i.e. the process
    //Display the results

    return 0;
}
//Function Implementation
