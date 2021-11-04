/* 
 * File:   main.cpp
 * Author: Miguel Galvez   
 * Purpose: Encrypt data from file and write it out
 * Created on October 13, 2021, 9:03 PM
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
//Function Prototypes
void encrypt(char x[]);
void decrypt(char x[]);
int main(int argc, char** argv) {
    //Declare Variables
    fstream inFile;         //File to be read
    fstream modFile;        //Modified file to be written
    char x;                 //Character array used to modify data
    //Open Input File and Open Output file
    inFile.open("stuff.txt",ios::in);
    modFile.open("mod.dat",ios::out|ios::binary);
    //Modify contents from file and write it to an output file
    if(inFile){
        while(inFile>>noskipws>>x){
            x+=20;
            modFile.write(reinterpret_cast<char*>(&x),sizeof(x));
        }
    }
    //Close files
    inFile.close();
    modFile.close();
    //Open Encrypted file and Outgoing decrypted txt file
    inFile.open("mod.dat",ios::in);
    modFile.open("decrypt.txt",ios::out);
    //Decrypt contents from file and write them to a new txt file
    if(inFile){
        while(inFile>>x){
            x-=20;
            modFile.write(&x,sizeof(x));
        }
    }
    //Close Files
    inFile.close();
    modFile.close();
    return 0;
}