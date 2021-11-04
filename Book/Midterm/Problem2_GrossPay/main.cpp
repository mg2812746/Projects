/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Determine Gross Pay
 * Created on October 21, 2021, 11:57 PM
 */
//Libraries
#include <iostream>
#include <iomanip>
using namespace std;
//Structures
struct Gross{       //Gross pay
    char *nme;      //Name of Employee
    int hrs;        //Number of hours worked
    float rate;     //Rate of pay
};
//Functions
void convert(int);
int main(int argc, char** argv){
    Gross *x;        //Structure of structure of Gross pay
    const int INP=30;    //Length of name
    int size;
    //Prompt user for total number of employees.
    cout<<"Enter the total number of employees you will enter.\n";
    //Input Validation
    do{
        cin>>size;
        cin.ignore();
        if(size<0){
            cout<<"Please enter a number greater than 0";
        }
    }while(size<0);
    //Dynamically allocate Gross structure
    x=new Gross [size];
    for(int i=0;i<size;i++){
        x->nme=new char [INP];
    }
    //Create checks
    for(int i=0;i<size;i++){
        //Prompt User to enter data
        cout<<"Enter the name of employee "<<i+1<<": ";
        cin.get(x->nme,INP);
        cin.ignore();
        cout<<"Enter the number of hours worked for "<<x->nme
            <<": ";
        cin>>x->hrs;
        cout<<"Enter the rate of pay for "<<x->nme<<": $";
        do{
            cin>>x->rate;
            if(x->rate<0){
                cout<<"Please enter a nonnegative rate. $";
            }
            cin.ignore();
        }while(x->rate<0);
        //Compute Pay
        int pay=0;
        if(x->hrs<=40){
            pay=x->hrs*x->rate;
        }else if(x->hrs>60){
            x->hrs-=40;        //Subtract 40 hours from total hours
            pay=40*x->rate;    //Base pay
            x->hrs-=20;
            pay+=20*x->rate*2; //Add Double time hours to pay
            pay+=x->hrs*x->rate*3;//Add Triple rate hours to pay
        }else{
            x->hrs-=40;        //Subtract 40 hours from total hours
            pay=40*x->rate;    //Base pay
            pay+=x->hrs*x->rate*2;//Double time
        }
        //Create Check
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<"---------------------------------------------------------\n";
        cout<<"Houseni Coffee & Tea Co."<<endl
            <<"123 Main Street"<<endl
            <<"Anytown, US 12345"<<endl<<endl
            <<"Pay to the                 "
            <<"              $"<<pay<<endl
            <<"order of: "<<x->nme<<endl
            <<"Amount: ";
            convert(pay);
        cout<<endl;
        cout<<"memo:________________   Signature:______________________"
            <<endl;
        cout<<"---------------------------------------------------------\n";
            
    }
    //Cleanup
    for(int i=0;i<size;i++){
        delete [] x->nme;
    }
    delete [] x;
    return 0;
}
void convert(int n2Cnvrt){
//Determine 1000's, 100's, 10's, 1's
    unsigned char n1000s,n100s,n10s,n1s;
    n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
    n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
    n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
    n1s=n2Cnvrt%10;        //Remainder of division by 10
        
    //Output the number of 1000's in Roman Numerals
    //Using the Switch Statement
    switch(n1000s){                
        case 1:
            cout<<"One Thousand ";
            break;
        case 2:
            cout<<"Two Thousand ";
            break;
        case 3:
            cout<<"Three Thousand ";
            break;        
    }
        
    //Output the number of 100's
    //Using the Ternary Operator
    cout<<(n100s==9?"Nine Hundred":
           n100s==8?"Eight Hundred":
           n100s==7?"Seven Hundred":
           n100s==6?"Six Hundred":
           n100s==5?"Five Hundred":
           n100s==4?"Four Hundred":
           n100s==3?"Three Hundred":
           n100s==2?"Two Hundred":
           n100s==1?"One Hundred":"");
    if(n10s!=1&n1s>0){
    //Output the number of 10's
    //Using Independent If Statements
    if(n10s==9)cout<<" Ninety";
    if(n10s==8)cout<<" Eighty";
    if(n10s==7)cout<<" Seventy";
    if(n10s==6)cout<<" Sixty";
    if(n10s==5)cout<<" Fifty";
    if(n10s==4)cout<<" Forty";
    if(n10s==3)cout<<" Thirty";
    if(n10s==2)cout<<" Twenty";
    if(n10s==1)cout<<" Ten";
      
    //Output the number of 1's
    //Using Dependent If Statements
    if(n1s==9)cout<<" Nine";          
    else if(n1s==8)cout<<" Eight";
    else if(n1s==7)cout<<" Seven";
    else if(n1s==6)cout<<" Six";
    else if(n1s==5)cout<<" Five";
    else if(n1s==4)cout<<" Four";
    else if(n1s==3)cout<<" Three";
    else if(n1s==2)cout<<" Two";
    else if(n1s==1)cout<<" One";  
    }else{
    if(n1s==9)cout<<" Nineteen";          
    else if(n1s==8)cout<<" Eighteen";
    else if(n1s==7)cout<<" Seventeen";
    else if(n1s==6)cout<<" Sixteen";
    else if(n1s==5)cout<<" Fifteen";
    else if(n1s==4)cout<<" Fourteen";
    else if(n1s==3)cout<<" Thirteen";
    else if(n1s==2)cout<<" Twelve";
    else if(n1s==1)cout<<" Eleven";  
    }
    cout<<" Dollars. ";
}
