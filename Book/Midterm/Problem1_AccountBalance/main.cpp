/* 
 * File:   main.cpp
 * Author: mikey
 * Purpose: Create an Account Balance
 * Created on October 21, 2021, 11:32 PM
 */
#include <iostream> //cout,cin
#include <cstring>  //strlen
using namespace std;
//Structures
struct Acc{                 //Account structure
    char *accNum;           //Account Number
    char *nme;              //Name 
    char *addy;             //Address
    int balance;            //Initial balance
    unsigned int *checks;    //Checks written by customer
    unsigned int *deposits;  //Deposits credited to account
};
//Functions
int main(int argc, char** argv) {
    const int SIZE=30;      //Size of Character arrays
    int numChks=3;          //Number of checks
    int numDep=3;           //Number of deposits
    Acc *x;                 //Pointer to account structure
    //Dynamically Allocate Memory
    x=new Acc;                      //Account
    x->accNum= new char [SIZE];     //Account Number
    x->nme   = new char [SIZE];     //Account Name
    x->addy  = new char [SIZE];     //Account Address
    //Get Basic information
    cout<<"Enter the account number (five digits only). ";
    do{
    cin.get(x->accNum,SIZE);
    cin.ignore();
    //Input Validation Message
    if(strlen(x->accNum)!=5){
        cout<<"Error: Account Number is not five digits of length "
            <<"please try again. ";
    }
    }while(strlen(x->accNum)!=5);
    cout<<"Enter your name. ";
    cin.get(x->nme,SIZE);
    cin.ignore();
    cout<<"Enter your address. ";
    cin.get(x->addy,SIZE);
    cin.ignore();
    cout<<"Enter the balance at the beginning of the month. ";
    cin>>x->balance;
    cin.ignore();
    cout<<"Enter the number of checks written this month. ";
    cin>>numChks;
    //Dynamically create number of checks
    x->checks=new unsigned int [numChks];
    //Gather inputs
    for(int i=0;i<numChks;i++){
        cout<<"Enter check "<<i+1<<": $";
        cin>>x->checks[i];
    }
    cout<<"Enter the number of deposits this month. ";
    cin>>numDep;
    x->deposits=new unsigned int [numDep];
    cout<<"Enter all deposits credited to your account this month\n";
    //Gather inputs
    for(int i=0;i<numDep;i++){
        cout<<"Enter deposit "<<i+1<<": $";
        cin>>x->deposits[i];
    }
    //Compute Balance
     for(int i=0;i<numDep;i++){
        x->balance+=x->deposits[i];
    }
    for(int i=0;i<numChks;i++){
        x->balance-=x->checks[i];
    }
    //If customer had an overdraft
    if(x->balance<0){
        cout<<"Overdraft Fee of $25 has been applied to your account.\n";
        cout<<"Balance after fee: $"<<x->balance-25<<endl;     
    }
    //Display Account Information
    cout<<"Account Number: "<<x->accNum<<endl
        <<"Name: "<<x->nme<<endl
        <<"Address: "<<x->addy<<endl
        <<"Balance: "<<x->balance<<endl
        <<"Checks:  \n";
    for(int i=0;i<numChks;i++){
        cout<<"Check "<<i+1<<endl
            <<x->checks[i]<<endl;
    }
    for(int i=0;i<numDep;i++){
        cout<<"Check "<<i+1<<endl
            <<x->deposits[i]<<endl;
    }
    //Cleanup
    delete x->accNum;
    delete x->nme;
    delete x->addy;
    delete x->checks;
    delete x->deposits;
    delete x;
    return 0;
}

