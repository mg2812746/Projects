/* 
 * File:   Numbers.cpp
 * Author: Miguel Galvez
 * Created on November 15 2021
 * Purpose: Design a Numbers Class
 */

#ifndef NUMBERS_H
#define NUMBERS_H
//System Libraries
#include <iostream>   //Input/Output Library
#include <string>     //string object
using namespace std;  //STD Name-space where Library is compiled
//Classes
class Numbers{
private:
    int number;
    static string less20[20];
    static string hund;
    static string thous;
public:   
    Numbers(int x){number=x;};  //Constructor
    void print()const;          //Prints English description of number
};

#endif /* NUMBERS_H */

