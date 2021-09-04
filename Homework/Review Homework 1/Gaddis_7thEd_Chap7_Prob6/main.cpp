/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on September 4 2021
 * Purpose: Determine Lowest/Highest/Total/Average Number
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation Library
#include <fstream>   //File Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void selctSrt(float arNum[], int totNum);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Constants
    const int MX_NUM=100;
    //Declare Variables
    char iflnm[20];       //Input File Name    
    ifstream inFile;    //File to be Read
    float arNum[MX_NUM],//Array of Numbers From File
          tot,          //Total Sum of Numbers in File
          avg;          //Average Number in File
    int totNum;         //Accumulator
    //Initialize Variables
    cout<<"What is the file name?"<<endl;
    cin>>iflnm;
    tot=0;
    avg=0;
    //Map Inputs to Outputs -> Process
    inFile.open(iflnm); //Open File
    //Initialize Accumulator
    totNum=0;
    //Read&Write File Into Array 
    while(!inFile.eof()){
        inFile>>arNum[totNum];
        totNum++;
    }inFile.close();    //Close File
    //Compute Total Sum 
    for(int i=0;i<totNum;i++){
        tot+=arNum[i];  //Compute Total Sum of Array
    }
    selctSrt(arNum,totNum);//Sort Array From Smallest to Largest
    avg =tot/totNum;         //Compute Average Number of Array
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)
        <<"Lowest Number : "<<arNum[0]<<endl
        <<"Highest Number: "<<arNum[totNum-1]<<endl
        <<"Total Sum     : "<<tot<<endl
        <<"Average       : "<<avg<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}
//Selection Sort
void selctSrt(float arNum[], int totNum){
    int   strt,
          minIndx;
    float minVal;
    for(strt=0;strt<(totNum-1);strt++){
        minIndx=strt;
        minVal=arNum[strt];
        for(int indx=strt+1;indx<totNum;indx++){
            if(arNum[indx]<minVal){
                minVal=arNum[indx];
                minIndx=indx;
            }
        }
        arNum[minIndx]=arNum[strt];
        arNum[strt]=minVal;
    }         
}