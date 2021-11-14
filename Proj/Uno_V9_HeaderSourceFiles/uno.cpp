#include "uno.h"
/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 13th 2021, 3:46PM
 * Purpose: All function declarations are here
 */

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
            i==0?x->all[i].value=ZERO:
            i<=2?x->all[i].value=ONE:
            i<=4?x->all[i].value=TWO:
            i<=6?x->all[i].value=THREE:
            i<=8?x->all[i].value=FOUR:
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
void draw1(Deck &plr,Deck fSet,bool stat[],short SZE){
    //Draw four cards into player's hand
    unsigned int indx=rand()%SZE;
    //Keep trying random number until unique
    while(!stat[indx])
        indx=rand()%SZE;
    //Copy Contents from index in deck to player 1 hand
    strcpy(plr.all[plr.size].color,fSet.all[indx].color);
    plr.all[plr.size].value=fSet.all[indx].value;
    //Falsify index in bool array
    stat[indx]=0;
    plr.size++;
}
void draw4(Deck &plr,Deck fSet,bool stat[]
            ,short SZE){
    //Draw four cards into player's hand
    unsigned int indx=rand()%SZE;
    //Increment hand size
        plr.size+=4;
    //Draw four cards and assign them to end of array
    for(int i=plr.size-4;i<plr.size;i++){
        //Keep trying random number until unique
        while(!stat[indx])
            indx=rand()%SZE;
        //Copy Contents from index in deck to player 1 hand
        strcpy(plr.all[i].color,fSet.all[indx].color);
        plr.all[i].value=fSet.all[indx].value;
        //Falsify index in bool array
        stat[indx]=0;
    }
}
void draw7(Deck &plr1,Deck &plr2,Deck fSet,
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
void show(Uno *x){
    cout<<setw(10)<<x->color
        <<setw(5);
        x->value==SKIP?cout<<"SKIP"<<endl:
        x->value==REVERSE?cout<<"REVERSE"<<endl:
        x->value==DRAW?cout<<"DRAW +1"<<endl:
        x->value==WILD?cout<<"WILDCARD"<<endl:
        x->value==DRAWWILD?cout<<"DRAW+4"<<endl:
        cout<<x->value<<endl;
}
void toss(Deck &plr,Uno &pile,int input){
    //Assign color from player's hand to pile
    strcpy(pile.color,plr.all[input].color);
    //Assign value from player's hand to pile
    pile.value=plr.all[input].value;
    //Remove card from player's hand
    for(int i=input;i<plr.size;i++){
        strcpy(plr.all[i].color,plr.all[i+1].color); 
        plr.all[i].value=plr.all[i+1].value;
    }
    //Decrement plr1's hand size
    plr.size--;
}
void wild(Deck &plr,Uno &pile,int input){
    //Assign value from player's hand to pile
    pile.value=plr.all[input].value;
    //Assign a color based off player's decision
    do{
    cout<<"Enter :"<<endl
        <<"1 for yellow\n"
        <<"2 for green\n"
        <<"3 for red\n"
        <<"4 for blue\n";
    cin>>input;
    }while(input>4||input<0);   //Input validation
    //Remove card from player's hand
    for(int i=input;i<plr.size;i++){
        strcpy(plr.all[i].color,plr.all[i+1].color); 
        plr.all[i].value=plr.all[i+1].value;
    }
    input==1?strcpy(pile.color,"Yellow"):
    input==2?strcpy(pile.color,"Green"):
    input==3?strcpy(pile.color,"Red"):
             strcpy(pile.color,"Blue");
    plr.size--;
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