/* 
 * File:   main.cpp
 * Author: Miguel Galvez    
 * Created on September 1, 2021
 * Purpose:  Compute Monthly Sales Tax
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulators Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Constants
    const float SLS_TX=0.06f, //Product Sales Tax
                SLS_TXS=0.04f,//State Sales Tax
                SLS_TXC=0.02f;//County Sales Tax
    
    //Declare Variables
    char mnth[10];//Month of the Year
    short int yr; //Year
    float totCsh, //Total Amount Collected (USD)
             sls, //Total Sales
          cSlsTx, //County Sales Tax
          sSlsTx, //State Sales Tax
          tSlsTx; //Total Sales Tax
            
    //Initialize Variables/Prompt User
    cout<<"What is the month?"<<endl;
    cin>>mnth;
    cout<<"What is the year?"<<endl;
    cin>>yr;
    cout<<"What is the total amount collected? (USD)"<<endl;
    cin>>totCsh;
    
    //Map Inputs to Outputs -> Process
    cSlsTx=totCsh*SLS_TXC;//Total County Sales Tax
    sSlsTx=totCsh*SLS_TXS;//Total State Sales Tax
    tSlsTx=totCsh*SLS_TX; //Total Sales Tax
    sls=totCsh-tSlsTx;    //Total Sales
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)<<"Month: "<<mnth<<endl
        <<"--------------------"<<endl
        <<"Total Collected:       $"<<setw(9)<<totCsh<<endl
        <<"Sales:                 $"<<setw(9)<<sls<<endl
        <<"County Sales Tax:      $"<<setw(9)<<cSlsTx<<endl
        <<"State Sales Tax:       $"<<setw(9)<<sSlsTx<<endl
        <<"Total Sales Tax:       $"<<setw(9)<<tSlsTx<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}