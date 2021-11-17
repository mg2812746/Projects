/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 14th, 2021
 * Purpose: Create a Car Class and incorporate a 
 *          constructor, accessor, an accelerate function
 *          and a brake function
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <iomanip> //setprecision,fixed,showpoint
#include <string>  //string class
#include <cstring>
#include <valarray> //strcpy
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Classes
class Car{
private: 
    short yrMdl;    //Car's year model
    string make;    //Car's make
    short speed;    //Car's speed
public:
    Car(string x,short y,short z);      //constructor
    void accel(){  //Mutator - Adds five mph to speed
        speed+=5;
    }
    void brk(){    //Mutator - Subtracts five mph to speed
        speed-=5;
    }
    void data() const;          //Shows speed of car
    short getYr() const{        //Access year
        return yrMdl;}
    short getSp() const{        //Access Speed
        return speed;}
    string getmk() const{       //Access make
        return make;}
};


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    Car toyota("Toyota",2002,0);     //Toyota avalon 2002
    //Display basic information about car
    cout<<"Make: "<<toyota.getmk()<<endl
        <<"Year: "<<toyota.getYr()<<endl;
    //Process 
    cout<<"Initial ";
    toyota.data();
    for(int i=0;i<5;i++){
        toyota.accel();
        toyota.data();
    }
    for(int i=0;i<5;i++){
        toyota.brk();
        toyota.data();
    }
    //Output the result
    
    //Exit
    return 0;
}
Car::Car(string x, short y, short z){
    make=x;        //Create make
    yrMdl=y;       //Create year model
    speed=z;       //Create speed
}
void Car::data() const{
    cout<<"Speed: "<<speed<<" mph"<<endl;
}