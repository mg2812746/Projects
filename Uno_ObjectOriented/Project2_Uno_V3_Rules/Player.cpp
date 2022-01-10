#include "Player.h"
//Default Constructor
Player::Player(){
    //Default skip to false 0
    skip=0;
}
//Draw Member Function- Draws a card
void Player::draw(char *colr,int val){
    try{
        //Assign color and value and increment total size
        all[size]=colr;
        all[size]=val;
        upSize();
    }catch(...){
        cout<<"Error in draw() player member function"
            <<endl;
    }
}
//Displays player's hand
void Player::hand(){
    try{
        cout<<left<<setw(9)<<"Card  #:" 
                <<setw(10)<<"Color"<<setw(5)
                <<"Value"<<endl;
        for(int i=0;i<size;i++){
            cout<<setw(6)<<"Card "<<i<<": " 
                <<setw(10)<<all[i].getColor()
                <<setw(5);
                all[i].getValue()==SKIP?cout<<"SKIP"<<endl:
                all[i].getValue()==REVERSE?cout<<"REVERSE"<<endl:
                all[i].getValue()==DRAW?cout<<"DRAW +1"<<endl:
                all[i].getValue()==WILD?cout<<"WILDCARD"<<endl:
                all[i].getValue()==DRAWWILD?cout<<"DRAW+4"<<endl:
                cout<<all[i].getValue()<<endl;
        }
    }catch(...){
        cout<<"Error in hand() Player member function"
            <<endl;
    }
}
//Removes the specified card from player's hand
void Player::remove(int index){
    try{
        for(int i=index;i<size;i++){
            all[i]=all[i+1].getColor();
            all[i]=all[i+1].getValue();
        }
        //Decrease total number of cards in player's hand
        downSize();
    }catch(...){
        cout<<"Error in remove() Player member function"
            <<endl;    
    }
}
//Returns a color of player's choice
char *Player::wild(){
    int input;          //Player input
    static char yel[]="Yellow",
         gr[]="Green",
        red[]="Red",
        blue[]="Blue";
    //Assign a color based off player's decision
    do{
    cout<<"Enter :"<<endl
        <<"1 for yellow\n"
        <<"2 for green\n"
        <<"3 for red\n"
        <<"4 for blue\n";
    //Exception handling, if an unacceptable input was entered
    try{
        cin>>input;
    }catch(...){
        //Clear the previous input
        cin.clear();
        //Discard the previous input
        cin.ignore();
    }
    }while(input>4||input<0);   //Input validation
    //Return a string color depending on what the 
    //player entered
    if(input==1){           //For 1 - Return Yellow
        return yel;
    }else if(input==2){     //For 2 - Return Green
        return gr;
    }else if(input==3){     //For 3 - Return Red
        return red;
    }else{          
        return blue;        //For 4 - Return Blue
    }
}