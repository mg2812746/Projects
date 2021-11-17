/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on 
 * Purpose: Implement an inventory class and test it
 *          in a driver program
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include "Inventory.h"
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    int itmNum;
    int quan;
    float cost;
    Inventory gFarm;
    //Initialize variables here
    do{
    cout<<"Enter the item number: ";
    cin>>itmNum;
    if(itmNum<0)
        cout<<"Error: item number cannot be negative. \n";
    }while(itmNum<0);   
    do{
    cout<<"Enter the quantity: ";
    cin>>quan;
    if(quan<0)
        cout<<"Error: quantity cannot be negative. \n";
    }while(quan<0);  
    do{
    cout<<"Enter the cost: $";
    cin>>cost;
    if(cost<0)
        cout<<"Error: cost cannot be negative. \n";
    }while(cost<0);  
    //Map inputs to outputs here, i.e. the process
    gFarm.setC(cost);
    gFarm.setI(itmNum);
    gFarm.setQ(quan);
    gFarm.setT(quan,cost);
    Inventory gFarm2(itmNum,quan,cost);
    //Display the results
    cout<<"gFarm"<<endl
        <<"Item number: "<<gFarm.getI()<<endl
        <<"Quantity: "<<gFarm.getQ()<<endl
        <<"Cost: $"<<gFarm.getC()<<endl
        <<"Total cost: $"<<gFarm.getT()<<endl;
    cout<<"gFarm2"<<endl
        <<"Item number: "<<gFarm2.getI()<<endl
        <<"Quantity: "<<gFarm2.getQ()<<endl
        <<"Cost: $"<<gFarm2.getC()<<endl
        <<"Total cost: $"<<gFarm2.getT()<<endl;
    return 0;
}
