/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on December 11, 2021, 11:51 AM
 * Purpose: Mastermind Project AI version 3
 * Description: Version 3 adds a "type" which signifies the type of 
 *              code that we're dealing with. Depending on the type
 *              we then crack the code accordingly. 
 *              
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
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw));
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
    void (*findMax)(char [],bool&,short[],short[],short&,int)= 
        [] (char grr[],bool &dup,short max[],short indxMax[],
            short &y,int guess){
        if(grr[guess]>1){
            dup=1;  //assign flag as true for duplicates
            max[y]=grr[guess];  //Store the max red pegs into max array
            indxMax[y]=guess-1; //Store the index associated with max
            y++;
        }
    };
    void (*saveCode)(char [],int[],short[],short&,short&,int)=
        [] (char grr[],int code[],short rrArr[],short &x,
            short &red,int guess){
            if(grr[guess]>0){
                    code[x]=guess-1;    //store the index into code array
                    rrArr[x]=grr[guess];//Assign no of reds for specific code
                    x++;                //increment x
                    red+=grr[guess];    //Red peg accumulator
        }
    };
    void (*assign)(string [],short,short,short,short)=
        [] (string sGuess[],short a,short b,short c,short d){
            sGuess[0]=a+'0';
            sGuess[1]=b+'0';
            sGuess[2]=c+'0';
            sGuess[3]=d+'0';
    };
    //Save the historical values of guesses and results
    static const int SIZE=10000;//How many guesses to save
    static int code[4];         //Save the value associated with red pegs
    static short x=0;           //Accumulator for code array
    static short red=0;         //Accumulator for total red pegs
    static short max[2];        //max number of red pegs
    static short y=0;           //Accumulator for total number of duplicates
    static short indxMax[2];    //Index of the element with the most red pegs
    static short rrArr[4];      //Array containing number of red pegs 
                                //aligned with code array
    static string aGuess[SIZE]; //Save the guesses
    static char grr[SIZE];      //Save right guess in right spot
    static char grw[SIZE];      //Save right guess in wrong spot
    static int guess=0;         //Increment the guess number
    static int redG=0;          //Number of guess after all 4 red pegs
    string sGuess="0000";       //Size the guest string
    static bool dup=0;          //flag for duplicates in array
    static short type=0;        //the type of duplicate default to 0
    static short inA,inB,       //place holders for sGuess
                inC,inD;
    //Store the results from the last guess
    grr[guess]=rr;
    grw[guess]=rw;
    //Test the helper function
    if(rr==4)print(aGuess,grr,grw,
            guess-10>0?guess-10:0,guess);
    //Return a guess depending on which guess we're on
    //Unless we found a total of 4 red pegs
    if(red!=4){
        if(guess==1){
            sGuess="1111";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==2){
            sGuess="2222";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==3){
            sGuess="3333";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==4){
            sGuess="4444";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==5){
            sGuess="5555";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==6){
            sGuess="6666";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==7){
            sGuess="7777";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==8){
            sGuess="8888";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);
        }else if(guess==9){
            sGuess="9999";
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);  
        }else if(guess==10){
            findMax(grr,dup,max,indxMax,y,guess);
            //If there was a red peg save the index into code array
            //until pegs reach 4
            saveCode(grr,code,rrArr,x,red,guess);   
        }
        if(red==4){
            redG=guess;     //Store the number of the guess once
        //We will determine the type of code that we're dealing with
        //Is duplicate    
            if(dup){
                //Find what kind of duplicate it is
                max[0]==2&&max[1]==2?type=3:        //aabb
                max[0]==2?type=2:                   //aabc
                type=4;                             //aaab
            //Not duplicate 
            }else if(!dup){
                type=1;                             //abcd
            }
        //We will store the number of guesses that we left off on to 
        //number our permutations
        //Assign into inA,inB,inC,inD depending on the type
            type==1?inA=code[0],inB=code[1],inC=code[2],inD=code[3]:
            type==2?inA=indxMax[0]:   
            type==3?inA=indxMax[0],inB=indxMax[1]:
            inA=indxMax[0];
            if(type==2){
                for(int i=0;i<x;i++){
                    if(inA!=code[i]){
                        inB=code[i];
                    }
                }
                for(int i=0;i<x;i++){
                    if(inA!=code[i]&&inB!=code[i]){
                        inC=code[i];
                    }
                }
            }else if (type==4){
                for(int i=0;i<x;i++){
                    if(inA!=code[i]){
                        inB=code[i];
                    }
                }
            }
        }
    //At this moment, we have found all four reds, we either have 10 
    //guesses or less
    }
    //Try every permutation of codes with red pegs
    if(type!=0){
        switch(type){
            case 1:
                //No duplicates abcd
                if(guess==redG){
                    //abcd 
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+1){
                    //bacd
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+2){
                    //cabd 
                    sGuess[0]=inC+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+3){
                    //dabc 
                    sGuess[0]=inD+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+4){
                    //abdc
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+5){
                    //badc
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+6){
                    //CADB 
                    sGuess[0]=inC+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+7){
                    //DACB 
                    sGuess[0]=inD+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+8){
                    //ACBD 
                    sGuess[0]=inA+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+9){
                    //BCAD 
                    sGuess[0]=inB+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+10){
                    //CBAD 
                    sGuess[0]=inC+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inD+'0';
                }else if(guess==redG+11){
                    //DBAC
                    sGuess[0]=inD+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+12){
                    //ACDB 
                    sGuess[0]=inA+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+13){
                    //BCDA 
                    sGuess[0]=inB+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+14){
                    //CBDA 
                    sGuess[0]=inC+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inD+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+15){
                    //DBCA
                    sGuess[0]=inD+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+16){
                    //ADBC 
                    sGuess[0]=inA+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+17){
                    //BDAC 
                    sGuess[0]=inB+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+18){
                    //CDAB
                    sGuess[0]=inC+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+19){
                    //DCAB
                    sGuess[0]=inD+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+20){
                    //ADCB
                    sGuess[0]=inA+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+21){
                    //BDCA 
                    sGuess[0]=inB+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+22){
                    //CDBA
                    sGuess[0]=inC+'0';
                    sGuess[1]=inD+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+23){
                    //DCBA 
                    sGuess[0]=inD+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }
                break;
            case 2:
                //max[0]==2
                //aabc
                if(guess==redG){
                    //aabc 
                    sGuess[0]=inA+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+1){
                    //baac 
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+2){
                    //abac
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inC+'0';
                }else if(guess==redG+3){
                    //BACA
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+4){
                    //ABCA
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+5){
                    //CBAA
                    sGuess[0]=inC+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+6){
                    //BCAA
                    sGuess[0]=inB+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+7){
                    //ACBA
                    sGuess[0]=inA+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+8){
                    //CABA
                    sGuess[0]=inC+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+9){
                    //AACB
                    sGuess[0]=inA+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inC+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+10){
                    //CAAB
                    sGuess[0]=inC+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+11){
                    //ACAB
                    sGuess[0]=inA+'0';
                    sGuess[1]=inC+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }
                break;
            case 3:
                //max[0]==2&&max[1]==2
                //aabb
                if(guess==redG){
                    //aabb
                    sGuess[0]=inA+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+1){
                    //baab
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+2){
                    //aabb
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inB+'0';
                }else if(guess==redG+3){
                    //aabb
                    sGuess[0]=inB+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+4){
                    //aabb
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+5){
                    //aabb
                    sGuess[0]=inB+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inA+'0';
                }
                break;
            default:
                if(guess==redG){
                    //aaab
                    for(int i=0;i<3;i++){
                        sGuess[i]=inA+'0';
                    }
                    sGuess[3]=inB+'0';
                }else if(guess==redG+1){
                    //aaba
                    sGuess[0]=inA+'0';
                    sGuess[1]=inA+'0';
                    sGuess[2]=inB+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+2){
                    //abaa
                    sGuess[0]=inA+'0';
                    sGuess[1]=inB+'0';
                    sGuess[2]=inA+'0';
                    sGuess[3]=inA+'0';
                }else if(guess==redG+3){
                    //baaa
                    for(int i=1;i<4;i++){
                        sGuess[i]=inA+'0';
                    }
                    sGuess[0]=inB+'0';
                }
                break;
        }
    }
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
