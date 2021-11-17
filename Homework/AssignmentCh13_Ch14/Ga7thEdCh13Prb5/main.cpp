/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 15th, 2021
 * Purpose: Create a retail items class that holds data about 
 *          various products
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>     //String class
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Classes
class RetailItem{
private:
    string dscrpt;      //Description of the item
    int units;          //The number of units in inventory
    float price;        //The price of the item (USD)
public:
    RetailItem(string,int,float);   //Constructor
    void setD(string);          //Set description (Mutator)
    void setU(int);             //Set unit (Mutator)
    void setP(float);           //set prices (Mutator)
    string getD() const;        //Get description
    int getU() const;           //Get units
    float getP() const;         //Get price
    void display()const;        //Displays data
};

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    //Declare variables here
    const short SIZE=3;
    RetailItem kohls[SIZE]={
        RetailItem("Jacket",12,59.95),
        RetailItem("Designer Jeans",40,34.95),
        RetailItem("Shirt",20,24.95)};
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    for(int i=0;i<SIZE;i++){
        kohls[i].display();
    }
    //Display the results

    return 0;
}
RetailItem::RetailItem(string x, int y, float z){
    dscrpt=x;
    units=y;
    price=z;
}
void RetailItem::setD(string x){          //Set description (Mutator)
    dscrpt=x;
}
void RetailItem::setU(int x){             //Set unit (Mutator)
    units=x;
}
void RetailItem::setP(float x){           //set prices (Mutator)
    price=x;
}
void RetailItem::display()const{        //Displays data
    cout<<"Description: "<<dscrpt<<endl
        <<"Units: "<<units<<endl
        <<"Price: "<<price<<endl;
}