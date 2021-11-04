/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 12 2021
 * Purpose: Display array contents from binary file
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <fstream> //Input & Output file stream
#include <cstdlib> //rand()
#include <iomanip> //setw()
#include <ctime>   //time()
#include <valarray>   
using namespace std;
//User Libraries Here
struct File{
    fstream x;      //Input/Output File
    int *ptr;       //Pointer to Integer array
    int *ptr2;      //Pointer to integer array from binary file
    int size;       //Size of Integer array
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int rndDgit();                         //Randomly generates a number
void fillArr(int *,int);                //Fills an array of integers
void arrToFile(fstream &, int*,int);    //Writes an array to binary file
void filToArr(fstream&,int*,int);       //Reads a binary file to an array
void dspArr(int *,int);                 //Displays Array
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    const int SIZE=60;      //Plenty of Entries
    File arr;               //File Structure
    //Dynamically allocate new integer arrays
    arr.ptr= new int [SIZE];
    arr.ptr2=new int [SIZE];
    //Assign size to size of array
    arr.size=SIZE;
    //Fill the Array with Random digits
    cout<<"Contents of array one: "<<endl;
    fillArr(arr.ptr,arr.size);
    //Display the array before writing to binary file
    dspArr(arr.ptr,arr.size);
    //Write the array contents to binary file
    arrToFile(arr.x,arr.ptr,arr.size);
    //Read the binary file to array 
    filToArr(arr.x,arr.ptr2,arr.size);
    //Display the array after being written by binary file
    cout<<"Contents of array two (read from binary file): "<<endl;
    dspArr(arr.ptr2,arr.size);
    //Cleanup
    delete [] arr.ptr;
    delete [] arr.ptr2;
    return 0;
}
int rndDgit(){
    return rand()%1000;
}
void fillArr(int *ptr,int size){
    for(int i=0;i<size;i++){
        ptr[i]=rndDgit();
    }
}
void arrToFile(fstream &x, int *ptr,int size){
    //Open file in binary mode
    x.open("test.dat",ios::out|ios::binary);
    //Write the contents of the array to the file
    if(x){
        x.write(reinterpret_cast<char*>(ptr),sizeof(ptr)*size);
    }else{
        cout<<"Error: file did not open properly";
    }
    //Close file
    x.close();
}
void filToArr(fstream &x,int *ptr,int size){
    //Open file in binary mode
    x.open("test.dat",ios::in|ios::binary);
    //Write Contents of binary file to array
    if(x){
        x.read(reinterpret_cast<char*>(ptr),sizeof(ptr)*size);
    }else{
        cout<<"Error: file did not open properly";
    }
    //Close file
    x.close();
}
void dspArr(int *ptr,int size){
    for(int i=0;i<size;i++){
        cout<<setw(5)<<ptr[i]<<" ";
        //Format
        if(i==9||i==19||i==29|i==39|i==49){
            cout<<endl;
        }
    }
    cout<<endl;
}