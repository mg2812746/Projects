/* 
 * File:   
 * Author: Miguel Galvez
 * Created on Sept 30, 2021
 * Purpose: Display Division's Quarterly Sales
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
//Structures
struct Division{         //Division Name
    float frstQ;        //First Quarter Sales
    float scndQ;        //Second Quarter Sales
    float thrdQ;        //Third Quarter Sales
    float frthQ;        //Fourth Quarter Sales
    float tot;          //Total annual sales 
    float avg;          //Annual average sales
};
//Function Prototypes
float avgSales(float);      //Return average
float totSales(Division);   //Return total sales
void  getDat(Division &);   //Read Quarterly Sales For Each Division 
void  stats(float,float);   //Display Statistics
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    //Declare Variable Data Types and Constants
    Division north;
    Division west;
    Division east;
    Division south;
    //Gather Sales Data, Compute Total Annual Sales, Compute Average Quarterly Sales, and Display Statistics
    //North
    cout<<"North\n";
    getDat(north);
    north.tot=totSales(north);
    north.avg=avgSales(north.tot);
    stats(north.tot,north.avg);
    cout<<endl;
    //West
    cout<<"West\n";
    getDat(west);
    west.tot=totSales(west);
    west.avg=avgSales(west.tot);
    stats(west.tot,west.avg);
    cout<<endl;
    //East
    cout<<"East\n";
    getDat(east);
    east.tot=totSales(east);
    east.avg=avgSales(east.tot);
    stats(east.tot,east.avg);
    cout<<endl;
    //South
    cout<<"South\n";
    getDat(south);
    south.tot=totSales(south);
    south.avg=avgSales(south.tot);
    stats(south.tot,south.avg);
    //Process or map Inputs to Outputs
    //Display Outputs
    
    //Exit stage right!
    return 0;
}
//Function Implementation
float avgSales(float tot){
    const char QRTRS=4;     //Total number of quarters
    float avg;              //Annual average of sales
    avg=tot/QRTRS;          //Compute average annual sales
    return avg;
}
float totSales(Division x){
    float tot;              //Total Annual Sales
    tot=0;
    tot+=x.frstQ+x.scndQ+x.thrdQ+x.frthQ;   //Compute Total Annual Sales
    return tot;
}
void  getDat(Division &x){
    const char QRTRS=4;     //Total number of quarters
    cout<<"Enter first-quarter sales:\n";
    cin>>x.frstQ;
    cout<<"Enter second-quarter sales:\n";
    cin>>x.scndQ;
    cout<<"Enter third-quarter sales:\n";
    cin>>x.thrdQ;
    cout<<"Enter fourth-quarter sales:\n";
    cin>>x.frthQ;
}
void  stats(float tot,float avg){
    cout<<fixed<<setprecision(2);
    cout<<"Total Annual sales:$"<<tot<<endl
        <<"Average Quarterly Sales:$"<<avg;
}