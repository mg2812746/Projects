/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 8, 2021, 4:34 PM
 * Purpose: Mastermind Project AI version 2
 * Description: We will start the algorithm by starting the guess with
 *              "0000" and continue to add 1 to each element to find each 
 *              appropriate peg until we get a total of 4 red pegs. We
 *              will also tally how many red pegs for each possible code
 *              (0-9). We will finish with returning whether the code 
 *              contains duplicates or not.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    //Code
    cout<<"Code: "<<code<<endl;
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw)&&nGuess<12);
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    guess=AI(rr,rw);
    
    //Exit the program
    return 0;
}

string AI(char rr,char rw){
    //Define helper functions here
    void (*print)(string [],char [],char [],int,int)=
        [] (string g[],char r[],char w[],int nb,int ne){ 
            for(int i=nb;i<=ne;i++){
                cout<<g[i]<<" "
                    <<static_cast<int>(r[i])<<" "
                    <<static_cast<int>(w[i])<<endl;
            }
    };
    
    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static int code[4];         //Save the value associated with red pegs
    static short x=0;           //Accumulator for code array
    static short red=0;         //Accumulator for total red pegs
    static short max[2];      //Index for max number of red pegs
    static short y=0;           //Accumulator for total number of duplicates
    static short rrArr[4];      //Array containing number of red pegs 
                                //aligned with code array
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    string sGuess="0000";       //Size the guest string
    static bool dup=false;          //flag for duplicates in array
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    if(red!=4){
        if(guess>0){cout<<"aGuess #"<<guess-1<<": "<<aGuess[guess-1]<<endl;}
        if(guess==1){
            sGuess="1111";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==2){
            sGuess="2222";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==3){
            sGuess="3333";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==4){
            sGuess="4444";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==5){
            sGuess="5555";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==6){
            sGuess="6666";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==7){
            sGuess="7777";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==8){
            sGuess="8888";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }
        }else if(guess==9){
            sGuess="9999";
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }   
        }else if(guess==10){
            if(grr[guess-1]>1){
                dup=1;  //assign flag as true for duplicates
                max[y]=guess-1;  //Save indices of code associated with duplicate
                y++;
            }
            //If there was a red peg save the index into code array
            //until pegs reach 4
            if(grr[guess-1]>0){
                    code[x]=guess-1;//store the index into code array
                    rrArr[x]=grr[guess-1];//Assign no of reds for specific code
                    x++;            //increment x
                    red+=grr[guess-1];    //Red peg accumulator
            }   
        }
    //At this moment, we have found all four reds, we either have 10 
    //guesses or less
    }else{
        //Is duplicate
        if(dup){
            cout<<"It is a duplicate!"<<endl;
        //Not duplicate 
        }else if(!dup){
            cout<<"It is not a duplicate!"<<endl;
        }
    }
    cout<<"Red: "<<red<<endl;
    aGuess[++guess]=sGuess;//Save the result
    //Return the result
    return sGuess;
}
//Evaluates right code in right spot (red) and 
//right code in wrong spot (white)
bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}
//Generates code to be solved by AI
string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}
