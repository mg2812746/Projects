/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Display Corporate Sales Data
 * Created on October 12, 2021, 9:59 PM
 */
//Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;
//Structures
struct Sales{
    string name;        //Name of division
    char qrtr[4];       //There are four quarters 
    unsigned int sls[4];//There are four quarters with sales
};
struct Div{
    Sales *x;          //Each division has a sales record
    int num;           //Total number of divisions
};
//Function Prototypes
void fillArr(unsigned int[],char,string);//Get data from user
void wrteDat(Sales*,fstream &,int);      //Write data to a binary file
int main(int argc, char** argv) {
    //Set the random seed generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    Div x;      //Division structure of Sales structure
    fstream out;
    //Assign the total number of divisions to num member function
    x.num=4;
    //Dynamically Allocate the total number of divisions
    x.x=new Sales [x.num];
    //Set the names for each division
    x.x[0].name="West";
    x.x[1].name="East";
    x.x[2].name="North";
    x.x[3].name="South";
    //Prompt User to enter sales for each division
    for(int i=0;i<x.num;i++){
        fillArr(x.x[i].sls,x.num,x.x[i].name);
    }
    //Write the sales data to binary file
    wrteDat(x.x,out,x.num);
    //Cleanup
    delete [] x.x;
    return 0;
}
//Function Implementation
void fillArr(unsigned int x[],char size,string name){
    cout<<"Division "<<name<<":\n";
    for(int i=0;i<size;i++){
        cout<<"Please enter the sales for quarter "<<i+1<<": ";
        cin>>x[i];
    }
}
void wrteDat(Sales *x,fstream &file,int size){
    file.open("division.dat",ios::out|ios::binary);
    if(file){
        file.write(reinterpret_cast<char*>(x),sizeof(x)*size);
    }else{
        cout<<"Error: Couldn't open file.\n";
    }
    file.close();
}