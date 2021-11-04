/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Encrypt and Decrypt Data
 * Created on October 21, 2021, 7:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
//Function Prototypes
void encrypt(char*);     //Encrypt Data
void decrypt(char*);     //Decrypt Data
bool check(char*,short); //Input Validation
int main(int argc, char** argv) {
    //Declare variables
    const short SIZE=10;  //Size of character array
    char *in;            //User-input
    bool crypt;          //Crypt or Decrypt
    //Dynamically allocate character array
    in=new char [SIZE];
    //Prompt User to enter data
    cout<<"Enter a four-digit integer 0-7. ";
    do{
    cin>>in;
    cin.ignore();
    //Display Input Validation Message if necessary
    if(check(in,SIZE)){
        cout<<"Please enter a four-digit integer 0-7. \n";
    }
    }while(check(in,SIZE));
    //Prompt User to encrypt or decrypt data
    cout<<"Enter 1 to encrypt or 0 to decrypt. ";
    cin>>crypt;
    
    //Encrypt Data
    if(crypt){
        encrypt(in);
    }
    //Decrypt Data
    else{
        decrypt(in);
    }
    //Cleanup
    delete [] in;
    return 0;
}
bool check(char *in,short size){
    //If size of input exceeds 4
    if(strlen(in)!=4){
        return true;
    }
    for(int i=0;i<4;i++){
        //If an incorrect number is entered
        if(in[i]>55||in[i]<48){
            return true;
        }
    }
    //If both conditions are not flagged, return false
    return false;
}
void encrypt(char *in){
    short temp;
    //Add each value by 3 and mod by 8
    for(int i=0;i<4;i++){
        temp=in[i]-48;
        temp+=3;
        temp%=8;
        temp+=48;
        in[i]=temp;
    }
    //Swap places 1&3 2&4
    for(int i=0;i<2;i++){
        temp=in[i];
        in[i]=in[i+2];
        in[i+2]=temp;
    }
    cout<<"Encrypted number: "<<in<<endl;
}
void decrypt(char *in){
    short temp;
   //Swap places 1&3 2&4
    for(int i=0;i<2;i++){
        temp=in[i];
        in[i]=in[i+2];
        in[i+2]=temp;
    }
    //Decrypt code
    for(int i=0;i<4;i++){
        temp=in[i]-48;
        temp+=5;
        temp%=8;
        temp+=48;
        in[i]=temp;
    }
    cout<<"Decrypted number: "<<in<<endl;
}