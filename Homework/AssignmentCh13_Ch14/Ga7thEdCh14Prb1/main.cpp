/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 15 2021
 * Purpose: Design a Numbers Class
 */

//User Libraries
#include "Numbers.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int x;
    //Initialize variables here
    cout<<"Enter a nonnegative number 0-9999. ";
    cin>>x;
    //Input validation
    while(x<0||x>9999){
        cout<<"Error: please enter a number 0-9999. ";
        cin>>x;
    }
    Numbers input(x);
    //Map inputs to outputs here, i.e. the process
    input.print();
    //Display the results

    return 0;
}