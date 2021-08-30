/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on February 21 2021
 * Purpose: Compute Total Cost of Purchase
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
    const char MIN=0;   //Number of Units Sold Need to Exceed 0
               CST=99;  //Cost of Package (USD)
    const float TN_NNTN=0.20f,  //Discount For Purchase of 10-19 Items
                TT_FTNN=0.30f,  //Discount For Purchase of 20-49 Items
                FTY_NTYNN=0.40f,//Discount For Purchase of 50-99 Items
                HNDRD=0.50f;//Discount For Purchase of 100 or more Items
    
    //Declare Variables
    int untsSld;   //Number of Units Sold
    float bsCst,   //Base Cost of Purchase
          totCst;  //Total Cost of Purchase
    //Initialize Variables
    cout<<"How many units are sold?"<<endl;
    cin>>untsSld;
    //Input Validation: Units Sold Need to be Greater Than 0
    while(untsSld<=MIN){
        cout<<"Number of Units Sold Need to be Greater Than 0"<<endl
            <<"How many units are sold?"<<endl;
        cin>>untsSld;
    }
    
    //Map Inputs to Outputs -> Process
    bsCst=untsSld*CST;
    totCst=untsSld<=9?bsCst:
           untsSld<=19?bsCst-bsCst*TN_NNTN:
           untsSld<=49?bsCst-bsCst*TT_FTNN:
           untsSld<=99?bsCst-bsCst*FTY_NTYNN:bsCst-bsCst*HNDRD;
    
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)
        <<"Total Cost of Purchase:  $"<<setw(10)<<totCst<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}