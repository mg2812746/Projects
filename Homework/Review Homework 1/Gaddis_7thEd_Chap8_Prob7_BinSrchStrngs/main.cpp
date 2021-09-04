/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on September 4 2021
 * Purpose: Search an Array of Strings
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulation Library
#include <string>    //String Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
int binrySrch(string arr[],const char TOTELM, string fndNme);
void selctSrt(string arr[], const char TOTELM);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Constants
    const char TOTELM=20;   //Number of Elements in Integer Array
    //Declare Variables
    string arr[TOTELM] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                        "Taylor, Terri", "Johnson, Jill",
                        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                        "James, Jean", "Weaver, Jim", "Pore, Bob",
                        "Rutherford, Greg", "Javens, Renee",
                        "Harrison, Rose", "Setzer, Cathy",
                        "Pike, Gordon", "Holland, Beth" };
    string fndNme;  //Last Name to be Found in Array
    int nmeLoc;    //Element in Array Associated with Last Name Found
    //Initialize Variables
    
    //Map Inputs to Outputs -> Process
    selctSrt(arr, TOTELM);  //Sort List of Names By Last Name
    //Prompt User Last Name to be Found in Array
    char temp=TOTELM;   //Total Number of Searches
    while(temp--){
        cout<<"Enter the name you would like to search for"
            <<" (example: Last, First)."<<endl;
        getline(cin,fndNme);
        cin.clear();
        nmeLoc=binrySrch(arr, TOTELM, fndNme);
        if(nmeLoc!=-1){
            cout<<arr[nmeLoc]<<" was successfully found"<<endl;
        }else{
            cout<<fndNme<<" was not found."<<endl;
        }
    }
    //Display Inputs/Outputs
   
    //Exit the Program - Cleanup
    return 0;
}
//Binary Search
int binrySrch(string arr[],const char TOTELM, string fndNme){
    int fst=0,    // First array element
    lst=TOTELM-1, // Last array element
    mid,          // Midpoint of search
    pos=-1;       // Position of search value
    bool fnd = false;   // Flag
    while (!fnd && fst <= lst){
        mid = (fst + lst) / 2;
        if (arr[mid] == fndNme){
            fnd = true;
            pos = mid;
        }else if (arr[mid] > fndNme){
            lst = mid - 1;
        }else
            fst = mid + 1;
    }
    return pos;
}
//Selection Sort
void selctSrt(string arr[], const char TOTELM){
    int    strt,
           minIndx;
    string minVal;
    for(strt=0;strt<(TOTELM-1);strt++){
        minIndx=strt;
        minVal=arr[strt];
        for(int indx=strt+1;indx<TOTELM;indx++){
            if(arr[indx]<minVal){
                minVal=arr[indx];
                minIndx=indx;
            }
        }
        arr[minIndx]=arr[strt];
        arr[strt]=minVal;
    }     
}