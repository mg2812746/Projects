/* 
 * File:   Inventory.cpp
 * Author: Miguel Galvez
 * Created on November 15th, 2021
 * Purpose: Inventory source file containing data
 *          and member/accessor/constructor functions
 */
#include "Inventory.h"
Inventory::Inventory(){
    itemNumber=0;
    quantity=0;
    cost=0;
    total=0;
}
Inventory::Inventory(int x,int y,float z){
    itemNumber=x;
    quantity=y;
    cost=z;
    setT(quantity,cost);
}
void Inventory::setT(int x,float y){    //Sets total cost
    total=x*y;
}
void Inventory::setI(int x){    //Sets item number        
    itemNumber=x;
}
void Inventory::setC(float x){  //Sets item cost       
    cost=x;
}
void Inventory::setQ(int x){    //Sets quantity      
    quantity=x;
}
float Inventory::getT()const{   //Gets total cost     
    return total;
}
int Inventory::getI()const{     //Gets item number   
    return itemNumber;
}
float Inventory::getC()const{   //Gets item cost     
    return cost;
}
int Inventory::getQ()const{     //Gets quantity   
    return quantity;
}