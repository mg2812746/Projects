/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 4, 2021
 * Purpose: Simulate a Soda Machine
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <iomanip> //setw
#include <cstring> //strcpy, strstr
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
//Structure
struct SdaMchn{
    char drnkNme[13];         //Drink Name
    short cst;                //Drink cost
    short tot;                //Total Number of Drinks in the Machine
};
//Enumerated values
enum SODA{COLA,RTBR,LMLM,GRPSDA,CRMSDA};
//Function Prototypes Here
void setDrnk(SdaMchn []);
void simMchn(SdaMchn [], SdaMchn []);
void dspDrnks(SdaMchn []);
char indxDrnk(char [], SdaMchn []);
short getChnge(short , short );
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const char NUMDRNKS=5;
    SdaMchn drnks[5];       //There are five drinks in the soda machine
    SdaMchn user[101];      //Array of User Input Data for soda machine
    //Input or initialize values Here
    setDrnk(drnks);         //Predefined Drink Names, Drink Prices, and Quantity in Soda Machine
    simMchn(drnks,user);    //Simulate Vending machine
    //Output the result
    
    //Exit
    return 0;
}
//Function Implementation
//Sets the Soda Machine Data 
void setDrnk(SdaMchn x[]){
    strcpy(x[COLA].drnkNme,"Cola");
    strcpy(x[RTBR].drnkNme,"Root Beer");
    strcpy(x[LMLM].drnkNme,"Lemon-Lime");
    strcpy(x[GRPSDA].drnkNme,"Grape Soda");
    strcpy(x[CRMSDA].drnkNme,"Cream Soda");
    for(int i=COLA;i<=CRMSDA;i++){
        x[i].tot=20;
        i<3?x[i].cst=75:
            x[i].cst=80;
    }
}
//Simulate a soda machine
void simMchn(SdaMchn soda[], SdaMchn user[]){
    const char SNTNEL[]="Quit";     //Sentinel Value- When User Enters "Quit", end soda simulation
    const short MAX=101;            //Maximum number of iterations possible
    char indx;                      //Indx of associated drink that matches user input
    short chnge;
    //Begin Simulation
    for(int i=0;i<MAX;i++){
        dspDrnks(soda);
        //Read Soda Name or Sentinel Value
        cin.getline(user[i].drnkNme,12);
        //Initialize change to 155
        chnge=155;
        //If Sentinel Value was Detected, No need for any more input 
        if(strstr(user[i].drnkNme,SNTNEL)==NULL){
            cin>>user[i].cst;       //Read money used for purchase
            cin.ignore();           //Ignore newline character
            //Input Validation: Cost is greater than a dollar or negative
            while(user[i].cst>100||user[i].cst<0){
                cout<<"Please enter a value less than 100 or greater than 0"<<endl;
                cin>>user[i].cst;
            }
            //Get Index of Array of Soda Name entered
            indx=indxDrnk(user[i].drnkNme,soda);
            //Update Inventory of Soda
            soda[indx].tot--;
            //Get change of transaction
            chnge=getChnge(user[i].cst,soda[indx].cst);
        }
        else{
            i=MAX;                //If entered drink name matched with sentinel value, exit iteration
        }
        cout<<chnge<<endl;        //Display change
    }
}
//Display drinks
void dspDrnks(SdaMchn x[]){
    for(int i=COLA;i<=CRMSDA;i++){
        cout<<left<<setw(11)<<x[i].drnkNme<<setw(4)<<x[i].cst<<setw(2)<<x[i].tot<<endl;
    }
    cout<<"Quit\n";
}
short getChnge(short x, short y){
    short chnge;
    chnge=x-y;
    return chnge;
}
char indxDrnk(char x[], SdaMchn y[]){
    char indx;
    for(int i=COLA;i<=CRMSDA;i++){
        if(strstr(x,y[i].drnkNme)!=NULL) indx=i;
    }
    return indx;
}