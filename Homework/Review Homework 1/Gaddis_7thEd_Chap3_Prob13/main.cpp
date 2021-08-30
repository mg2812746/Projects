/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on February 20 2021
 * Purpose: Compute Property Tax
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Constants
    const float ASM_TX=0.60f,  //Assessment Tax (Decimal Form)
                P_TX=0.64f/100;//Property Tax Formula
    //Declare Variables
    unsigned int valPrp;   //Value of Property (USD)
    float asmVal,          //Assessment Value
          pTx;             //Property Tax
    //Initialize Variables/Prompt User
    cout<<"What is the value of the property?"<<endl;
    cin>>valPrp;
    
    //Map Inputs to Outputs -> Process
    asmVal=valPrp*ASM_TX;  //Assessment Value
    pTx=asmVal*P_TX;       //Property Tax
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)
        <<"Assessment Value: $"<<setw(8)<<asmVal<<endl
        <<"Property Tax:     $"<<setw(8)<<pTx<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}