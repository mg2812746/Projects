/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;
//Structures
struct Acc{                 //Account structure
    char *accNum;           //Account Number
    char *nme;              //Name 
    char *addy;             //Address
    int balance;            //Initial balance
    unsigned int *checks;    //Checks written by customer
    unsigned int *deposits;  //Deposits credited to account
};
struct Gross{       //Gross pay
    char *nme;      //Name of Employee
    int hrs;        //Number of hours worked
    float rate;     //Rate of pay
};
struct Prime{
    unsigned short prime;
    unsigned char power;
};
struct Primes{
    unsigned char nPrimes;
    Prime *prime;
};
//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();             //Menu
void prblm1();           //Problem 1
void prblm2();           //Problem 2
void prblm3();           //Problem 3
void prblm4();           //Problem 4
void prblm5();           //Problem 5
void prblm6();           //Problem 6
void prblm7();           //Problem 7
void convert(int);       //For Problem 2-Convert from number to English
void encrypt(char*);     //Encrypt Data
void decrypt(char*);     //Decrypt Data
bool check(char*,short); //Input Validation
Primes *factor(int);
void prntPrm(Primes *);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;
        cin.ignore();
        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl; 
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;  
    cout<<"Type 6 for Problem 6"<<endl;  
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    const int SIZE=30;      //Size of Character arrays
    int numChks=3;          //Number of checks
    int numDep=3;           //Number of deposits
    Acc *x;                 //Pointer to account structure
    //Dynamically Allocate Memory
    x=new Acc;                      //Account
    x->accNum= new char [SIZE];     //Account Number
    x->nme   = new char [SIZE];     //Account Name
    x->addy  = new char [SIZE];     //Account Address
    //Get Basic information
    cout<<"Enter the account number (five digits only). ";
    do{
    cin.get(x->accNum,SIZE);
    cin.ignore();
    //Input Validation Message
    if(strlen(x->accNum)!=5){
        cout<<"Error: Account Number is not five digits of length "
            <<"please try again. ";
    }
    }while(strlen(x->accNum)!=5);
    cout<<"Enter your name. ";
    cin.get(x->nme,SIZE);
    cin.ignore();
    cout<<"Enter your address. ";
    cin.get(x->addy,SIZE);
    cin.ignore();
    cout<<"Enter the balance at the beginning of the month. ";
    cin>>x->balance;
    cin.ignore();
    cout<<"Enter the number of checks written this month. ";
    cin>>numChks;
    //Dynamically create number of checks
    x->checks=new unsigned int [numChks];
    //Gather inputs
    for(int i=0;i<numChks;i++){
        cout<<"Enter check "<<i+1<<": $";
        cin>>x->checks[i];
    }
    cout<<"Enter the number of deposits this month. ";
    cin>>numDep;
    x->deposits=new unsigned int [numDep];
    cout<<"Enter all deposits credited to your account this month\n";
    //Gather inputs
    for(int i=0;i<numDep;i++){
        cout<<"Enter deposit "<<i+1<<": $";
        cin>>x->deposits[i];
    }
    //Compute Balance
     for(int i=0;i<numDep;i++){
        x->balance+=x->deposits[i];
    }
    for(int i=0;i<numChks;i++){
        x->balance-=x->checks[i];
    }
    //If customer had an overdraft
    if(x->balance<0){
        cout<<"Overdraft Fee of $25 has been applied to your account.\n";
        cout<<"Balance after fee: $"<<x->balance-25<<endl;     
    }
    //Display Account Information
    cout<<"Account Number: "<<x->accNum<<endl
        <<"Name: "<<x->nme<<endl
        <<"Address: "<<x->addy<<endl
        <<"Balance: "<<x->balance<<endl
        <<"Checks:  \n";
    for(int i=0;i<numChks;i++){
        cout<<"Check "<<i+1<<endl
            <<x->checks[i]<<endl;
    }
    for(int i=0;i<numDep;i++){
        cout<<"Check "<<i+1<<endl
            <<x->deposits[i]<<endl;
    }
    //Cleanup
    delete x->accNum;
    delete x->nme;
    delete x->addy;
    delete x->checks;
    delete x->deposits;
    delete x;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
    Gross *x;            //Structure of structure of Gross pay
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
        //Input Validation
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
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3 is included in Problem3_Stats"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
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
            cout<<"One Thousand";
            break;
        case 2:
            cout<<"Two Thousand";
            break;
        case 3:
            cout<<"Three Thousand";
            break;        
    }
        
    //Output the number of 100's
    //Using the Ternary Operator
    cout<<(n100s==9?" Nine Hundred":
           n100s==8?" Eight Hundred":
           n100s==7?" Seven Hundred":
           n100s==6?" Six Hundred":
           n100s==5?" Five Hundred":
           n100s==4?" Four Hundred":
           n100s==3?" Three Hundred":
           n100s==2?" Two Hundred":
           n100s==1?" One Hundred":"");
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
void prblm5(){
    cout<<"Largest n for n! for...\n"
        <<"char:               5"<<endl
        <<"unsigned char:      5"<<endl
        <<"short:              7"<<endl
        <<"unsigned short:     8"<<endl
        <<"float:              10"<<endl
        <<"int:                12"<<endl
        <<"unsigned int:       12"<<endl
        <<"long:               12"<<endl
        <<"unsigned long:      12"<<endl
        <<"double:             17"<<endl
        <<"long long:          20"<<endl
        <<"unsigned long long: 20"<<endl;
        
}
void prblm7(){
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
void prblm6(){
    cout<<"x means repeating\n";
    cout<<"Part a) \n"
        <<"49.1875 = 31.6 base 16\n"
        <<"49.1875 = 00110001.0011 base 2\n"
        <<"49.1875 = 61.14 base 8\n"
        <<"49.1875 = 62600006 NASA Format\n"
        <<"3.07421875 = 3.13 base 16\n"
        <<"3.07421875 = 0011.00010011 base 2\n"
        <<"3.07421875 = 3.045 base 8\n"
        <<"3.07421875 = 61300002 NASA Format\n"
        <<"0.2 = 3.333x base 16\n"
        <<"0.2 = 0.00110011xxxx base 2\n"
        <<"0.2 = 0.14631463xxxx base 8\n"
        <<"0.2 = 666666FF NASA Format\n";
    cout<<"Part b) \n"
        <<"-49.1875 = CF.D base 16\n"
        <<"-49.1875 = 11001111.1101 base 2\n"
        <<"-49.1875 = 317.64 base 8\n"
        <<"-49.1875 = 67E80008 NASA Format\n"
        <<"-3.07421875 = D.EE base 16\n"
        <<"-3.07421875 = 1101.11101110 base 2\n"
        <<"-3.07421875 = 15.734 base 8\n"
        <<"-3.07421875 = 6F700004 NASA Format\n"
        <<"-0.2 = Dx base 16\n"
        <<"-0.2 = 0.00110011xxxx base 2\n"
        <<"-0.2 = 0.64xx base 8\n"
        <<"-0.2 = 6EEEEE00 NASA Format\n";
    cout<<"Part c) \n"
        <<"69999902 = 3.4CCCCC8 base 16\n"
        <<"69999903 = 6.99999   base 16\n"
        <<"966667FF = 1.A666C8  base 16\n";
}