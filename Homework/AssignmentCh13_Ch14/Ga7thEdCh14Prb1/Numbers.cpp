/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 15 2021
 * Purpose: Design a Numbers Class
 */
#include "Numbers.h"
void Numbers::print() const{
    int x;    //ones
    int z;   //hundreds         
    int a;  //thousands      
    if(number<20){
        cout<<less20[number]<<endl;
    }else if(number<1000){           
        z=number/100;
        number-z*100>19?x=number%10:x=number-z*100;
        cout<<less20[z]<<" "<<hund<<" ";
        x==0?cout<<endl:
            cout<<less20[x]<<endl;
    }else{
        x=number%10;
        a=number/1000;
        z=(number-a*1000)/100;
        cout<<less20[a]<<" "<<thous<<" "
            <<less20[z]<<" "<<hund<<" ";
        x==0?cout<<endl:
            cout<<less20[x]<<endl;
    }
}
string Numbers::less20[20]={
    "zero","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve",
    "thirteen","fourteen","fifteen","sixteen",
    "seventeen","eighteen","nineteen"};
string Numbers::hund="hundred";
string Numbers::thous="thousand";