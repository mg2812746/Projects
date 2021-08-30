/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on February 22 2021
 * Purpose: Convert From Fahrenheit to Celsius
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
float celsius(float fhrenht);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Constant
    const int MAX=21;  //Maximum Total of Loops Desired
    //Declare Variables
    float fhrenht,  //Fahrenheit Temperature
          clsius;   //Celsius Temperature
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    
    
    //Display Inputs/Outputs
    for(int i=0; i<MAX;i++){
        fhrenht = i;
        clsius = celsius(fhrenht);
        cout<<fixed<<setprecision(2)
            <<"Fahrenheit: "<<fhrenht<<endl
            <<"Celsius   : "<<clsius<<endl;
    }
    
    //Exit the Program - Cleanup
    return 0;
}
float celsius(float fhrenht){
    float clsius;   //Celsius Temperature
    clsius = (5.0/9.0)*(fhrenht-32);
    return clsius;
}