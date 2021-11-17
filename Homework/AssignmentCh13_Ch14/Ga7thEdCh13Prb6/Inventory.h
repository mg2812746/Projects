/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: mikey
 *
 * Created on November 15, 2021, 6:52 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H
class Inventory{
private:
    int itemNumber;     //item's item number
    int quantity;       //quantity of items
    float cost;         //per-unit cost
    float total;        //Total inventory cost
public:
    Inventory();    //Constructor #1
    Inventory(int,int,float);//Constructor #2
    void setT(int,float);   //Sets total cost
    void setI(int);         //Sets item number
    void setC(float);       //Sets item cost
    void setQ(int);         //Sets quantity
    float getT()const;      //Gets total cost
    int getI()const;        //Gets item number
    float getC()const;      //Gets item cost
    int getQ()const;        //Gets quantity
};


#endif /* INVENTORY_H */

