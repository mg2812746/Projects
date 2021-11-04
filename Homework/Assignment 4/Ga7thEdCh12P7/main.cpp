/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 12 2021
 * Purpose: Capitalize the first letter of every word and 
 *          make the rest of the letters lowercase
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <fstream> //Input & Output file stream
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void convert(fstream&,fstream&,char[]);//Apply conversion to input file 
                             //and write to output file
void inFil(fstream &,char[]);//Open input file
void oFil(fstream&,char []);//Open output file
void capital(char []);    //Capitalizes the first letter of every word
void lower(char [],short);//Makes capitals lowercase after first entry
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const char SIZE=60; //Length of file name
    fstream inFile;     //File coming in
    fstream oFile;      //File going out
    char fname[SIZE];   //File name
    //Prompt User for Input File Name and Open File
    inFil(inFile,fname);
    //Prompt User for Output File Name and Open File
    oFil(oFile,fname);
    //Read Contents of File and Write them to output file if opened 
    //successfully
    convert(inFile,oFile,fname);
    //Exit Properly
    inFile.close();
    oFile.close();
    return 0;
}
void capital(char x[]){
    if(x[0]<123&&x[0]>96){
        x[0]-=32;
    }
}
void lower(char x[],short size){
    for(int i=1;i<size;i++){
        if(x[i]>64&&x[i]<91){
            x[i]+=32;
        }
    }
}
void inFil(fstream &file,char fname[]){
    cout<<"Enter the name of the input file. ";
    cin.get(fname,40);          //sentences.txt
    cin.ignore();
    file.open(fname,ios::in);
}
void oFil(fstream &file,char fname[]){
    cout<<"Enter the name of the output file. ";
    cin.get(fname,40);          //output.txt
    cin.ignore();
    file.open(fname,ios::out);
}
void convert(fstream &inFile,fstream &oFile,char word[]){
    if(inFile){
        while(inFile>>word){
            capital(word);     //Capitalize the first letter of every word
            lower(word,strlen(word));//Make the rest of the word lowercase
            oFile<<word<<" ";
        }
    }else{
        cout<<"Error! File undetected."<<endl;
    }
}
