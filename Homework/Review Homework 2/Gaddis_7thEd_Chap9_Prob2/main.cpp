/* 
 * File:   main.cpp
 * Author: Miguel Galvez    
 * Created on July 31, 2021
 * Purpose:  Compute and Display Average Test Scores
 */

//User Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulators Library
using namespace std;
//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Function Prototypes
void readArr(float *,int);
void sortArr(float *,int);
float computeAvg(float *,int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    float *tstScrs,   //To dynamically allocate test scores
            tstAvg;   //Total test average
    int numScrs;      //To hold total number of scores
    
    //Initialize Variables/Prompt User
    cout<<"How many test scores are there?"<<endl;
    cin>>numScrs;
    
    //Map Inputs to Outputs -> Process
    tstScrs=new float[numScrs];     //Dynamically allocate test scores
    readArr(tstScrs,numScrs);       //Read test scores
    sortArr(tstScrs,numScrs);       //Sort test scores in ascending order
    tstAvg=computeAvg(tstScrs,numScrs);    //Compute average of scores
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2)   //Format output
        <<"The Sorted List of Scores: "<<endl;
    for(int i=0;i<numScrs;i++){
        cout<<"Score "<<i+1<<": "<<*(tstScrs+i)<<endl;
    }
    cout<<"Test Average: "<<tstAvg<<endl;
    //Exit the Program - Cleanup
    delete [] tstScrs;
    tstScrs=0;          //Set test scores to null
    return 0;
}
//Function Implementation

//Read Scores into Array
void readArr(float *ptr,int scrs){
    for(int i=0;i<scrs;i++){
        cout<<"Enter score "<<i+1<<": ";
        cin>>*(ptr+i);
        cout<<endl;
    }
}
//Insertion Sort Algorithm
void sortArr(float *ptr,int scrs){
    int j;
    float tmp;
    for(int i=0;i<scrs;i++){
        tmp=*(ptr+i);
        j=i;
        while(j>0&&(*(ptr+j-1)>tmp)){
            *(ptr+j)=*(ptr+j-1);
            j--;
        }
        *(ptr+j)=tmp;
    }
}
//Compute Average
float computeAvg(float *ptr,int tot){
    float avg=0;
    for(int i=0;i<tot;i++){
        avg+=*(ptr+i);
    }
    avg=avg/tot;
    return avg;
}