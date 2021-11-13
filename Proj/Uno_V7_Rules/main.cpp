/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on October 29th 2021, 7:22PM
 * Purpose: Now we will create rules that we need
 *          in order to play uno
 */

//System Libraries Here
#include <iostream> //cin,cout,endl
#include <cstring>  //strcpy, strstr
#include <iomanip>  //xprecision,fixed,showpoint
#include <fstream>
#include <valarray>  //file operations
using namespace std;
//User Libraries Here
//Structures
struct Uno{                 //Deck of Uno Cards
    char color[8];          //Color associated with uno card
    unsigned short value;   //Value associated with the card
};
struct Deck{        //Structure of structure containing deck of uno cards
    unsigned short size;        //Size of Uno Deck
    Uno *all;                   //Data of all uno cards
};
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
enum Values{        //Card Values
    ZERO,ONE,TWO,THREE,FOUR,    //0-4
    FIVE,SIX,SEVEN,EIGHT,NINE,  //5-9
    SKIP,           //Skip Next Player's Turn
    REVERSE,        //Reverse The Turn Order
    DRAW,           //Next Person Draws a Card
    WILD,           //Wildcard
    DRAWWILD        //Wildcard Draw +4 Cards
};
//Function Prototypes Here
void create(Deck&,Deck&,short);
void define(Deck *);
void destroy(Deck&,Deck&,Deck&,Deck&);
void display(Deck *);
void draw(bool [],short,Uno &,Deck);
void show(Uno *);
void wrteRd(Deck &set,Deck &fSet,fstream &out,
        fstream &in);
void svnCrds(Deck&,Deck&,Deck,bool [],short);
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Generator Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare all Variables Here
    const short SZE=108;    //Uno Deck Size
    const short PLR=54;     //Player hand size
    bool stat[SZE]; //Status of Deck array
    bool reverse;   //Status for reverse, true for order player 1 to 
                    //last player and false for opposite order
    fstream in;     //input file
    fstream out;    //output file
    Deck set;       //Deck of uno cards
    Deck fSet;      //Deck of uno cards from file
    Deck plr1;      //Player 1
    Deck plr2;      //Player 2
    Uno pile;       //Current card on the pile
    int input;      //user input
    //Display Uno game header
    cout<<"Welcome to the game of Uno! "<<endl
        <<"Enter 0 to begin, or anything else to "
        <<"end this program. ";
    cin>>input;
    if(input==0){
        
        //Dynamically Allocate Memory for Deck and Players
        create(set,fSet,SZE);
        create(plr1,plr2,PLR);
        //Players start off with 0 cards before drawing 
        //Define Uno Cards for Deck
        define(&set);
        //Write and read deck of cards
        wrteRd(set,fSet,out,in);
        //Default bool values to true
        for(int i=0;i<SZE;i++)
            stat[i]=1;
        //Draw cards from fSet into Players
        svnCrds(plr1,plr2,fSet,stat,SZE);
        //Draw a card for pile
        draw(stat,SZE,pile,fSet);
        while(plr1.size!=0&&plr2.size!=0){
        //Show player 1's hands
        cout<<"Player 1's hand: "<<endl;
        display(&plr1);
        //Display card on top of pile
        cout<<"Card on top of pile: ";
        show(&pile);
        //Prompt player 1 for an applicable card to throw to the pile
        //Otherwise draw a card
        cout<<"Enter the card # to throw to the pile. "<<endl;
        cin>>input;
        //Input Validation
        while(input>plr1.size){
            cout<<"Error: enter a valid number."<<endl;
            cout<<"Enter the card # to throw to the pile. "<<endl;
            cin>>input;
        }
        //If card is valid, toss card onto pile
        if(!strcmp(plr1.all[input].color,pile.color)){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr1.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr1.all[input].value;
            //Remove card from player's hand
            for(int i=input-1;i<plr1.size;i++){
            strcpy(plr1.all[i].color,plr1.all[i+1].color); 
            plr1.all[i].value=plr1.all[i+1].value;
            }
            //Decrement plr1's hand size
            plr1.size--;
        }else if(plr1.all[input].value==pile.value){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr1.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr1.all[input].value;
            //Remove card from player's hand
            for(int i=input-1;i<plr1.size;i++){
            strcpy(plr1.all[i].color,plr1.all[i+1].color); 
            plr1.all[i].value=plr1.all[i+1].value;
            }
            //Decrement plr1's hand size
            plr1.size--;
        }else if(plr1.all[input].value>NINE){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr1.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr1.all[input].value;
            //Remove card from player's hand
            for(int i=input-1;i<plr1.size;i++){
            strcpy(plr1.all[i].color,plr1.all[i+1].color); 
            plr1.all[i].value=plr1.all[i+1].value;
            }
            plr1.size--;
        }
        //Display player 2's hand
        cout<<"Player 2's hand: "<<endl;   
        display(&plr2);
        //Display top of pile
        cout<<"Card on top of pile: ";
        show(&pile);
        //Prompt player 1 for an applicable card to throw to the pile
        //Otherwise draw a card
        cout<<"Enter the card # to throw to the pile. "<<endl;
        cin>>input;
        //Input Validation
        while(input>plr2.size){
            cout<<"Error: enter a valid number."<<endl;
            cout<<"Enter the card # to throw to the pile. "<<endl;
            cin>>input;
        }
        //If card is valid, toss card onto pile
        if(!strcmp(plr2.all[input].color,pile.color)){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr2.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr2.all[input].value;
            //Remove card from player's hand
            for(int i=input-1;i<plr2.size;i++){
            strcpy(plr2.all[i].color,plr2.all[i+1].color); 
            plr2.all[i].value=plr2.all[i+1].value;
            }
            //Decrement plr2's hand size
            plr2.size--;
        }else if(plr2.all[input].value==pile.value){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr2.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr2.all[input].value;
            //Decrement plr1's hand size
            plr2.size--;
        }else if(plr2.all[input].value>NINE){
            //Assign color from player's hand to pile
            strcpy(pile.color,plr2.all[input].color);
            //Assign value from player's hand to pile
            pile.value=plr2.all[input].value;
            //Remove card from player's hand
            for(int i=input-1;i<plr1.size;i++){
            strcpy(plr2.all[i].color,plr2.all[i+1].color); 
            plr2.all[i].value=plr2.all[i+1].value;
            }
            plr2.size--;
        }
        }
    //Cleanup
    destroy(set,fSet,plr1,plr2);
    }
    //Exit
    return 0;
}
void create(Deck &set,Deck &fSet,short SZE){
    set.all=new Uno [SZE];
    set.size=SZE;
    fSet.all=new Uno [SZE];
    fSet.size=SZE;
}
void define(Deck *x){
    //Define x of Uno cards
    for(int i=0;i<x->size;i++){
        //First 25 cards are Green
        if(i<25){
            strcpy(x->all[i].color, "Green");
            i==ZERO?x->all[i].value=ZERO:
            i<=TWO?x->all[i].value=ONE:
            i<=FOUR?x->all[i].value=TWO:
            i<=SIX?x->all[i].value=THREE:
            i<=EIGHT?x->all[i].value=FOUR:
            i<=10?x->all[i].value=FIVE:
            i<=12?x->all[i].value=SIX:
            i<=14?x->all[i].value=SEVEN:
            i<=16?x->all[i].value=EIGHT:
            i<=18?x->all[i].value=NINE:
            i<=20?x->all[i].value=SKIP:
            i<=22?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Blue
        }else if(i<50){
            strcpy(x->all[i].color, "Blue");
            i==25?x->all[i].value=ZERO:
            i<=27?x->all[i].value=ONE:
            i<=29?x->all[i].value=TWO:
            i<=31?x->all[i].value=THREE:
            i<=33?x->all[i].value=FOUR:
            i<=35?x->all[i].value=FIVE:
            i<=37?x->all[i].value=SIX:
            i<=39?x->all[i].value=SEVEN:
            i<=41?x->all[i].value=EIGHT:
            i<=43?x->all[i].value=NINE:
            i<=45?x->all[i].value=SKIP:
            i<=47?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Red
        }else if(i<75){
            strcpy(x->all[i].color, "Red");
            i==50?x->all[i].value=ZERO:
            i<=52?x->all[i].value=ONE:
            i<=54?x->all[i].value=TWO:
            i<=56?x->all[i].value=THREE:
            i<=58?x->all[i].value=FOUR:
            i<=60?x->all[i].value=FIVE:
            i<=62?x->all[i].value=SIX:
            i<=64?x->all[i].value=SEVEN:
            i<=66?x->all[i].value=EIGHT:
            i<=68?x->all[i].value=NINE:
            i<=70?x->all[i].value=SKIP:
            i<=72?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Next 25 are Yellow
        }else if(i<100){
            strcpy(x->all[i].color, "Yellow");
            i==75?x->all[i].value=ZERO:
            i<=77?x->all[i].value=ONE:
            i<=79?x->all[i].value=TWO:
            i<=81?x->all[i].value=THREE:
            i<=83?x->all[i].value=FOUR:
            i<=85?x->all[i].value=FIVE:
            i<=87?x->all[i].value=SIX:
            i<=89?x->all[i].value=SEVEN:
            i<=91?x->all[i].value=EIGHT:
            i<=93?x->all[i].value=NINE:
            i<=95?x->all[i].value=SKIP:
            i<=97?x->all[i].value=REVERSE:
            x->all[i].value=DRAW;
        //Last 8 are Black wildcards
        }else{
            strcpy(x->all[i].color, "Black");
            i<=103?x->all[i].value=WILD:
            x->all[i].value=DRAWWILD;
        }
    }
}
void destroy(Deck &set,Deck &fSet,Deck &plr1,
                Deck &plr2){
    delete [] set.all;
    delete [] fSet.all;
    delete [] plr1.all;
    delete [] plr2.all;
}
void display(Deck *x){
    cout<<left<<setw(9)<<"Card  #:" 
            <<setw(10)<<"Color"<<setw(5)
            <<"Value"<<endl;
    for(int i=0;i<x->size;i++){
        cout<<setw(6)<<"Card "<<i<<": " 
            <<setw(10)<<x->all[i].color
            <<setw(5);
            x->all[i].value==SKIP?cout<<"SKIP"<<endl:
            x->all[i].value==REVERSE?cout<<"REVERSE"<<endl:
            x->all[i].value==DRAW?cout<<"DRAW +1"<<endl:
            x->all[i].value==WILD?cout<<"WILDCARD"<<endl:
            x->all[i].value==DRAWWILD?cout<<"DRAW+4"<<endl:
            cout<<x->all[i].value<<endl;
    }
}
void draw(bool stat[],short SZE,Uno &pile,Deck fSet){
    //Draw a card for the pile
    unsigned int indx=rand()%SZE;
    //Keep trying random number until unique
    while(!stat[indx])
        indx=rand()%SZE;
    //Copy Contents from index in deck to player 1 hand
        strcpy(pile.color,fSet.all[indx].color);
        pile.value=fSet.all[indx].value;
    //Falsify index in bool array
    stat[indx]=0;
}
void show(Uno *x){
    cout<<left<<setw(10)<<"Color"<<setw(5)
        <<"Value"<<endl;
    cout<<setw(10)<<x->color
        <<setw(5);
        x->value==SKIP?cout<<"SKIP"<<endl:
        x->value==REVERSE?cout<<"REVERSE"<<endl:
        x->value==DRAW?cout<<"DRAW +1"<<endl:
        x->value==WILD?cout<<"WILDCARD"<<endl:
        x->value==DRAWWILD?cout<<"DRAW+4"<<endl:
        cout<<x->value<<endl;
}
void wrteRd(Deck &set,Deck &fSet,fstream &out,
        fstream &in){
    //Write Uno cards to file
    out.open("unoCards.dat",ios::out|ios::binary);
    out.write(reinterpret_cast<char *>(&set),sizeof(set)*set.size);
    out.close();
    //Read Uno cards to separate variable
    in.open("unoCards.dat",ios::in|ios::binary);
    in.read(reinterpret_cast<char *>(&fSet),sizeof(fSet)*fSet.size);
    in.close();
}
void svnCrds(Deck &plr1,Deck &plr2,Deck fSet,
                bool stat[],short SZE){
    //Players start off with 0 cards
    plr1.size=0;
    unsigned int indx=rand()%SZE;
    for(int i=0;i<7;i++){
        //Keep trying random number until unique
        while(!stat[indx])
            indx=rand()%SZE;
        //Increment hand size
        plr1.size++;
        //Copy Contents from index in deck to player 1 hand
        strcpy(plr1.all[i].color,fSet.all[indx].color);
        plr1.all[i].value=fSet.all[indx].value;
        //Falsify index in bool array
        stat[indx]=0;
    }
    plr2.size=0;
    indx=rand()%SZE;
    for(int i=0;i<7;i++){
        //Keep trying random number until unique
        while(!stat[indx])
            indx=rand()%SZE;
        //Increment hand size
        plr2.size++;
        //Copy Contents from index in deck to player 1 hand
        strcpy(plr2.all[i].color,fSet.all[indx].color);
        plr2.all[i].value=fSet.all[indx].value;
        //Falsify index in bool array
        stat[indx]=0;
    }
}