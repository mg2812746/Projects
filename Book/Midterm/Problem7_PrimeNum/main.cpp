/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Compute Prime Numbers From Integer
 * Created on October 21, 2021, 11:59 PM
 */
//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;
//structures
struct Prime{
    unsigned short prime;
    unsigned char power;
};
struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};
Primes *factor(int);
void prntPrm(Primes *);
int main(int argc, char** argv) {
    int x;          //Integer to be factored
    Primes *ptr;    //Pointer to Primes structure
    //Prompt user for integer value
    cout<<"Enter an integer value from 2 to 265000. ";
    do{
    cin>>x;
    //Input Validation
    if(x>265000||x<2){
        cout<<"Error: Please enter a value greater than 2 "
            <<"or less than or equal to 265000. ";
    }
    }while(x>265000||x<2);
    //Get Factors
    ptr=factor(x);
    //Display Factors
    prntPrm(ptr);
    //Cleanup
    delete ptr->prime;
    delete ptr;
    return 0;
}
Primes *factor(int x){
    Primes *ptr;                //Pointer to Primes structure
    int tmp=0;                  //Temporary power variable
    ptr= new Primes;            //Dynamically create primes structure
    ptr->nPrimes=0;             //Set Number of primes to 0 (accumulator)
    ptr->prime=new Prime[x/2];  //Dynamically create space for primes
    //Compute and Store Factors
    for(int i=2;i<=x;i++){
        //Initialize number of powers
        tmp=0;
        //For each number of primes, add 1 to power
        while(x%i==0){
            x/=i;
            tmp++;    
        }
        ptr->prime[ptr->nPrimes].prime=i;
        ptr->prime[ptr->nPrimes].power=tmp+48;
        //Increment number of Primes for the next iteration
        if(tmp>0){
        ptr->nPrimes++;
        }
    }
    return ptr;
}
void prntPrm(Primes *ptr){
    cout<<"Prime Numbers: ";
    for(int i=0;i<ptr->nPrimes;i++){
        cout<<ptr->prime[i].prime<<"^"<<ptr->prime[i].power;
        if(i!=ptr->nPrimes-1){
            cout<<"*";
        } 
    }
}