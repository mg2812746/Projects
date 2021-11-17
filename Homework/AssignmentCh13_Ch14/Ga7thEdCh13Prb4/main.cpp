/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 15th, 2021
 * Purpose: Create a Personal Information Class
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <iomanip> //setprecision,fixed,showpoint
#include <string>  //string class
#include <cstring> //strcpy() strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Classes
class Tmi{              //Too much info class containing personal info
private:
    string name;        //String containing name of person
    char address[30];   //Pointer to char array containing address
    char age;           //Age of person
    char *phone;        //Pointer to char array containing phone number
public:
    Tmi(string,char[],char,char*);
    ~Tmi();
    string getNm(){
        return name;
    }
    char *getAd(){
        return address;
    }
    char getAge(){
        return age;
    }
    char *getPhn(){
        return phone;
    }
};

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const char TOT=3;         //Total number of people 
    Tmi *info;
    char *phn1;               //Pointer to first phone number
    char *phn2;               //Pointer to second phone number
    char *phn3;               //Pointer to third phone number
    //Dynamically allocate memory for phone numbers
    phn1=new char[12];
    phn2=new char[12];
    phn3=new char[12];
    //Assign phone numbers accordingly
    strcpy(phn1,"9098008000");
    strcpy(phn2,"6265559999");
    strcpy(phn3,"8182225546");
    //Dynamically create and instantiate array of classes 
    info=new Tmi[TOT]{Tmi("Name1","Addy1",48,phn1),
                      Tmi("Name2","Addy2",49,phn2),
                      Tmi("Name3","Addy3",50,phn3)};     
    //Output the result
    for(int i=0;i<TOT;i++){
    cout<<"Name: "<<info[i].getNm()<<endl
        <<"Address: "<<info[i].getAd()<<endl
        <<"Age: "<<info[i].getAge()<<endl
        <<"Phone: "<<info[i].getPhn()<<endl;
    }
    
    //Cleanup
    delete [] info;
    delete [] phn1;
    delete [] phn2;
    delete [] phn3;
    //Exit
    return 0;
}
Tmi::Tmi(string a,char b[],char c,char d[]){
    name=a;
    strcpy(address,b);
    age=c;
    phone=new char [strlen(d)+1];
    for(int i=0;i<strlen(d);i++){
        phone[i]=d[i];
    }
}
Tmi::~Tmi(){
    delete [] phone;
};