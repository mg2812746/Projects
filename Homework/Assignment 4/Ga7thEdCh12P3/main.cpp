/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Read a joke.txt file and punchline.txt file and Display
 *          a complete joke
 * Created on October 13, 2021, 4:26 PM
 */
//Libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
//Function Prototypes
void dspJoke(fstream&);
void dspPunch(fstream&);
int main(int argc, char** argv) {
    //Declare variables
    fstream joke;   //Joke file (Input)
    fstream punch;  //Punchline file (Input)
    //Read joke and display joke
    dspJoke(joke);
    //Read punchline and display punchline
    dspPunch(punch);
    return 0;
}
void dspJoke(fstream &x){
    const int SIZE=30;
    char arr[SIZE];
    x.open("joke.txt",ios::in);
    if(x){
        while(x>>arr){
            cout<<arr<<" ";
        }
        cout<<endl;
    }else{
        cout<<"Error, could not read file.\n";
    }
    x.close();
}
void dspPunch(fstream &x){
    const int SIZE=30;
    long cursor=-14L;
    char arr[SIZE];
    x.open("punchline.txt",ios::in);
    if(x){
        x.seekg(cursor,ios::end);
        while(x>>arr){
            cout<<arr<<" ";
        }
    }else{
        cout<<"Error, could not read file.\n";
    }
    x.close();
}
