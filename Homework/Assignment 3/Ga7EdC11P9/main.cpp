/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 5, 2021
 * Purpose: Create Speaker's Bureau Structure 
 */

//System Libraries Here
#include <iostream>//cin,cout,endl

using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
//Structures
//Bureau Information
struct Bur{             //Speaker's Bureau
    char name[30];      //Name of Person
    char phnNum[12];    //Telephone Number
    char spkTop[45];    //Speaking Topic
    int fee;            //Fee Required
};
//Function Prototypes Here
void menu(Bur *[]);         //Display Menu 
Bur *getDat();              //Read Bureau Information
void readDat(Bur *, int);   //Read Data
void inpValid();            //Display Input Validation Message
void menu(Bur *,int);       //Menu Displaying all the Speaker's Bureau
void showDat(Bur *, int);   //Displays Structure Data
void mod(Bur &);            //Modifies a Piece of Structure Data
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    Bur *ptr;
    //Input or initialize values Here
    ptr=getDat();
    //Exit
    delete [] ptr;
    return 0;
}
//Function Implementation
//Display Menu 
//Read Bureau Information
Bur *getDat(){
    Bur *ptr;                //Pointer to Speaker's Bureau Structure
    unsigned short totBur;   //Total number of Speaker's Bureau's 
    //Prompt User for number of Speaker's Bureau arrays
    cout<<"This program uses a structure to store data about a speaker's "
        <<"bureau.\n"
        <<"First enter the number of Speaker's Bureau data you'd like to "
        <<"create.\n"
        <<"Then enter the speaker's name, the speaker's telephone number \n"
        <<"the speaker's speaking topic, and the speaker's fee "
        <<"required(USD).\n\n";    
    cin>>totBur;             //Read number of Speaker's Bureau 
    ptr=new Bur [totBur];    //Dynamically create arrays of Bureau data
    //Read Data
    readDat(ptr,totBur);
    //Show Data
    showDat(ptr,totBur);
    //Display Menu to User
    menu(ptr,totBur);
    return ptr;
}   
//Input Validation Message
void inpValid(){
    cout<<"Enter a value greater than 0 for the speaker's fee.\n";
}
//Displays menu
void menu(Bur *ptr,int n){
    char path;
    cout<<"Would you like to modify any Speaker's Bureau data?\n"
        <<"Enter y to continue or n to end program. ";
    cin>>path;
    while(path=='y'||path=='Y'){
        unsigned short ref;
        cout<<"Enter The Speaker's Reference Number That "
            <<"You'd Like To Modify. ";
        cin>>ref;
        mod(ptr[ref-1]);
        showDat(ptr,n);
        cout<<"Would you like to modify any Speaker's Bureau data?\n"
        <<"Enter y to continue or n to end program. ";
        cin>>path;
    }
}
//Read Speaker's Bureau Data
void readDat(Bur *ptr,int n){
    for(int i=0;i<n;i++){
        cin.ignore();
        cin.get(ptr[i].name,30);
        cin.ignore();
        cin.get(ptr[i].phnNum,12);
        cin.ignore();
        cin.get(ptr[i].spkTop,45);
        cin.ignore();
        cin>>ptr[i].fee;
        while(ptr[i].fee<0){
            inpValid();         //Input Validation Message
            cin>>ptr[i].fee;    //Retry Input
        }
        cout<<endl;
    }
}
//Displays Speaker's Bureau Data
void showDat(Bur *ptr, int n){
    for(int i=0;i<n;i++){
        cout<<"Reference Number: "<<i+1<<endl;
        cout<<"Name: "<<ptr[i].name<<endl
            <<"Telephone Number: "<<ptr[i].phnNum<<endl
            <<"Speaking Topic: "<<ptr[i].spkTop<<endl
            <<"Fee Required: $"<<ptr[i].fee<<endl;
        cout<<endl;
    }
}
//Modify Structure Data
void mod(Bur &per){
    char path;
    cout<<"Enter n to modify name\n"
        <<"Enter t to modify telephone number\n"
        <<"Enter s to modify speaking topic\n"
        <<"Enter f to modify fee required\n";
    cin>>path;
    switch(path){
        case 'n':
            cout<<"Enter the name you would like to replace "
                <<per.name<<" with\n";
            cin.ignore();
            cin.get(per.name,30);
            cout<<endl;
            break;
        case 't':
            cout<<"Enter the telephone number you would like to replace "
                <<per.phnNum<<" with.\n";
            cin.ignore();
            cin.get(per.phnNum,30);
            cout<<endl;
            break;
        case 's':
            cout<<"Enter the speaking topic you would like to replace "
                <<per.spkTop<<" with.\n";
            cin.ignore();
            cin.get(per.spkTop,30);
            cout<<endl;
            break;
        case 'f':
            cout<<"Enter the fee you would like to replace $"
                <<per.fee<<" with.\n";
            cin.ignore();
            cout<<"$";
            cin>>per.fee;
            cout<<endl;
            break;
        default:
            cout<<"You did not enter any of the given options. \n";
            break;
    }
}