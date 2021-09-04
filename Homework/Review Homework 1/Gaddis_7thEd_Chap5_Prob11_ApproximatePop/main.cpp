/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on September 4 2021
 * Purpose: Approximate Total Population 
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    int strtPop, //Starting Number of Organisms
        popSz;   //Size of Population
    float avgInc;//Average Increase (Percentage)
    char numDys; //Number of Days Organisms Will Multiply For
    //Initialize Variables
    cout<<"What is the starting number of organisms?"<<endl;
    cin>>strtPop;
    //Input Validation: Input Needs to be Greater Than 2
    while(strtPop<2){
        cout<<"Please enter a number larger than 2 for the "
            <<"starting number."<<endl
            <<"What is the starting number of organisms?"<<endl;
        cin>>strtPop;
    }
    cout<<"What is the percent average daily population increase?"<<endl;
    cin>>avgInc;
    //Input Validation: Input Needs to be Positive
    while(avgInc<0){
        cout<<"Please enter a percent larger than 0"<<endl
            <<"What is the percent average daily population increase?"<<endl;
        cin>>avgInc;
    }
    cout<<"How many days will they multiply for?"<<endl;
    cin>>numDys;
    //Input Validation: Input Needs to be Larger or Equal to 1
    while(numDys<1){
        cout<<"Number of day(s) need to be at least one."<<endl
            <<"How many days will they multiply for?"<<endl;
        cin>>numDys;
    }
    
    //Map Inputs to Outputs -> Process
    avgInc = avgInc/100.0f;    //Convert Percent to Decimal
    //Display Inputs/Outputs
    for(int i=0;i<=numDys-48;i++){
        popSz=strtPop+(strtPop*avgInc*i);
        i==0?cout<<"Day "<<i+1<<" Population: "<<strtPop<<endl:
            cout<<"Day "<<i+1<<" Population: "<<popSz<<endl;
    }
    
    //Exit the Program - Cleanup
    return 0;
}