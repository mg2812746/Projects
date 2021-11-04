/* 
 * File:   
 * Author: Miguel Galvez
 * Created on Sept 30, 2021
 * Purpose:  Display Weather Statistics
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;
// Structure Definition
struct Rain{
    float tot;
    short high;
    short low;
    float avg;
};
//Enumerated Data types
enum MONTHS {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
// Function Prototype
float avgRain(Rain []);
float avgTemp(Rain []);
short lowTmp(Rain []);
short highTmp(Rain []);
void getTemp(Rain []);
  int main(int argc, char** argv){
    //Declare Variables
    const char YR=12;//Total number of months out of the year
  	Rain months[YR]; //Array of 12 Rain structs
  	short high;      //Highest temperature of the year
  	short low;       //Lowest Temperature of the year
  	float avgR;       //Monthly Average Rainfall
  	float avgT;      //Monthly average temperature
  	float tot;       //Total rainfall for the year
  	//Gather Inputs
  	getTemp(months);
    //Compute Monthly Average Rainfall
    avgR=avgRain(months);
    //Computer Average temperature
    avgT=avgTemp(months);
    //Find lowest temperatures 
    low=lowTmp(months);
    //Find highest temperatures 
    high=highTmp(months);
    //Display Results
    cout<<fixed<<showpoint;
    cout<<setprecision(2)<<"Average monthly rainfall:"<<avgR<<endl
        <<"High Temp:"<<high<<endl
        <<"Low Temp:"<<low<<endl
        <<setprecision(1)<<"Average Temp:"<<avgT;
    return 0;
    }
void getTemp(Rain months[]){
    for(int i=JAN;i<JUL;i++){
        cout<<"Enter the total rainfall for the month:\n";
        cin>>months[i].tot;
        cout<<"Enter the high temp:\n";
        cin>>months[i].high;
        cout<<"Enter the low temp:\n";
        cin>>months[i].low;
    }
}
float avgRain(Rain months[]){
    float avg=0;
	for(int i=JAN;i<JUL;i++){
	    avg+=months[i].tot;
	}
	avg/=JUL;
	return avg;
}
float avgTemp(Rain months[]){
    float avgT=0;
    for(int i=JAN;i<JUL;i++){
	    avgT+=months[i].high+months[i].low;
	}avgT/=static_cast<float>(JUL*2);
    return avgT;
}
short lowTmp(Rain months[]){
	short low=months[JAN].low;
	for (int i=FEB;i<JUL;i++){
		if (months[i].low<low)
			low=months[i].low;
	}
	return low;
}
short highTmp(Rain months[]){
    short high=months[JAN].high;
	for (int i=FEB;i<JUL;i++){
		if (months[i].high>high)
			high=months[i].high;
	}
    return high;
}