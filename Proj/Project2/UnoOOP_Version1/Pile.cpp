#include "Pile.h"
//Initialize static variable size
short Pile::size=0;
//display pile
void Pile::display()const{
    cout<<left<<setw(9)<<"Card  #:" 
            <<setw(10)<<"Color"<<setw(5)
            <<"Value"<<endl;
    for(int i=0;i<size;i++){
        cout<<setw(6)<<"Card "<<i<<": "<<setw(10)<<all[i].getColor
            <<setw(5);
            all[i].getValue==SKIP?cout<<"SKIP"<<endl:
            all[i].getValue==REVERSE?cout<<"REVERSE"<<endl:
            all[i].getValue==DRAW?cout<<"DRAW +1"<<endl:
            all[i].getValue==WILD?cout<<"WILDCARD"<<endl:
            all[i].getValue==DRAWWILD?cout<<"DRAW+4"<<endl:
            cout<<all[i].getValue<<endl;
    }
}   