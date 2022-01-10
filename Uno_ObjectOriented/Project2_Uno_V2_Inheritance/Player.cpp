#include "Player.h"
//Default Constructor
Player::Player(){
    //Default skip to false 0
    skip=0;
}
//Draw Member Function- Draws a card
void Player::draw(char *colr,int val){
    //Assign color and value and increment total size
    all[size]=colr;
    all[size]=val;
    upSize();
}
void Player::hand(){
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
}
