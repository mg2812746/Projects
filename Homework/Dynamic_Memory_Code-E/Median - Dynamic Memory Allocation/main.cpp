/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on Sept 26th, 2021, 6:14 PM
 * Purpose:  Template which is to be copied for all future
 *           Homework, Labs, Projects, Test, etc...
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>  //setprecision(),fixed
using namespace std;

//User Libraries

//Function Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int );     //Print the median Array
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    //Declare all variables for this function
    int *ptr;
    int size;
    float *med;
    //Initialize all known variables
    ptr=getData(size);
    //Process Inputs to Outputs -> Mapping Process
    med=median(ptr,size);
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    prntDat(ptr,size);
    prntMed(med, size);
    //Clean up the code, close files, deallocate memory, etc....
    delete [] ptr;
    delete [] med;
    //Exit stage right
    return 0;
}

//Function Implementations
//Return the array size and the array
int *getData(int &size){
    cin>>size;
    int *p=new int [size];
    for(int i=0;i<size;i++){
       cin>>p[i];
    }
    return p;
}    
 //Print the integer array
void prntDat(int *arr,int size){
    for(int i=0;i<size;i++){
        if(i==size-1){cout<<arr[i];}
        else{cout<<arr[i]<<" ";}
    }
    cout<<endl;
}  
//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *arr,int size){
    float *ptr=new float [size+2];
    ptr[0]=size+2;
    float mean;
    mean=0; //Initialize mean
    //Assign values to float array
    //Compute the mode, and assign it to appropriate element
    for(int i=0;i<size;i++){
        ptr[i+2]=arr[i];
        mean +=arr[i];
    }
    mean/=size;
    ptr[1]=mean;
    
    return ptr;
}
//Print the median Array
void prntMed(float *med,int size){
    cout<<med[0]<<" "<<setprecision(2)<<fixed<<med[1]<<" ";
    for(int i=2;i<size+2;i++){
        if(i==size+1){cout<<setprecision(2)<<fixed<<med[i];}
        else{cout<<setprecision(2)<<fixed<<med[i]<<" ";}
    }

}    