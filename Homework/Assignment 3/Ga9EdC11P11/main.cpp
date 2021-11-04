/* 
 * File:   
 * Author: Miguel Galvez
 * Created on October 3, 2021
 * Purpose: Display Monthly Budget
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct Budget{          //Monthly Budget
    float hse;          //Housing
    float util;         //Utilities
    float hseExp;       //House Expenses
    float trns;         //Transportation
    float fud;          //Food
    float med;          //Medical
    float insrnce;      //Insurance
    float entrtnmnt;    //Entertainment
    float cloth;        //Clothing
    float misc;         //Miscellaneious
};
//Function Prototypes
void setBud(Budget &);      //Set Budget
void getDat(Budget &);      //Get Expenses
float cmpBud(Budget,Budget); //Compare Budget with Expenses 
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Budget rule;        //Set budget for the month
    Budget expense;     //Expenses for the month
    float net;          //Total money over or under budget
    //Initialize Variables
    setBud(rule);       //Allocate Budget for the month
    getDat(expense);    //Read expenses from the user
    //Process or map Inputs to Outputs
    net=cmpBud(rule,expense);   //Compute net expenses (over or under budget)
    //Display Outputs
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"You were ";
    net>0?cout<<"$"<<net<<" under budget":
          cout<<"$"<<net*-1<<" over budget";
    //Exit stage right!
    return 0;
}
//Set Monthly Budget Data
void setBud(Budget &x){
    x.hse=500;
    x.util=150;
    x.hseExp=65;
    x.trns=50;
    x.fud=250;
    x.med=30;
    x.insrnce=100;
    x.entrtnmnt=150;
    x.cloth=75;
    x.misc=50;
}
void getDat(Budget &x){
    cout<<"Enter housing cost for the month:$";
    cin>>x.hse;
    cout<<endl;
    cout<<"Enter utilities cost for the month:$";
    cin>>x.util;
    cout<<endl;
    cout<<"Enter household expenses cost for the month:$";
    cin>>x.hseExp;
    cout<<endl;
    cout<<"Enter transportation cost for the month:$";
    cin>>x.trns;
    cout<<endl;
    cout<<"Enter food cost for the month:$";
    cin>>x.fud;
    cout<<endl;
    cout<<"Enter medical cost for the month:$";
    cin>>x.med;
    cout<<endl;
    cout<<"Enter insurance cost for the month:$";
    cin>>x.insrnce;
    cout<<endl;
    cout<<"Enter entertainment cost for the month:$";
    cin>>x.entrtnmnt;
    cout<<endl;
    cout<<"Enter clothing cost for the month:$";
    cin>>x.cloth;
    cout<<endl;
    cout<<"Enter miscellaneous cost for the month:$";
    cin>>x.misc;
    cout<<endl;
}
float cmpBud(Budget x,Budget y){
    float net=0;
    cout<<"Housing ";
    if(x.hse==y.hse)cout<<"Even\n";
    else if(x.hse>y.hse) cout<<"Under\n"; 
    else cout<<"Over\n";
    net+=x.hse-y.hse;
    cout<<"Utilities ";
    if(x.util==y.util) cout<<"Even\n";
    else if(x.util>y.util) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.util-y.util;
    cout<<"Household Expenses ";
    if(x.hseExp==y.hseExp) cout<<"Even\n";
    else if(x.hseExp>y.hseExp) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.hseExp-y.hseExp;
    cout<<"Transportation ";
    if(x.trns==y.trns) cout<<"Even\n";
    else if(x.trns>y.trns) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.trns-y.trns;
    cout<<"Food ";
    if(x.fud==y.fud) cout<<"Even\n";
    else if(x.fud>y.fud) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.fud-y.fud;
    cout<<"Medical ";
    if(x.med==y.med) cout<<"Even\n";
    else if(x.med>y.med) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.med-y.med;
    cout<<"Insurance ";
    if(x.insrnce==y.insrnce) cout<<"Even\n";
    else if(x.insrnce>y.insrnce) cout<<"Under\n";
    else cout<<"Over\n";
    net+=x.insrnce-y.insrnce;
    cout<<"Entertainment";
    if(x.entrtnmnt==y.entrtnmnt) cout<<" Even\n";
    else if(x.entrtnmnt>y.entrtnmnt) cout<<" Under\n";
    else cout<<" Over\n";
    net+=x.entrtnmnt-y.entrtnmnt;
    cout<<"Clothing";
    if(x.cloth==y.cloth) cout<<" Even\n";
    else if(x.cloth>y.cloth) cout<<" Under\n";
    else cout<<" Over\n";
    net+=x.cloth-y.cloth;
    cout<<"Miscellaneous";
    if(x.misc==y.misc) cout<<" Even\n";
    else if(x.misc>y.misc) cout<<" Under\n";
    else cout<<" Over\n";
    net+=x.misc-y.misc;
    return net;
}
