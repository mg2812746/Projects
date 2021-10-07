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
    char mnth[10];  //Name of the month
    float tot;      //Total rainfall inches
    short high;     //The highest temperature of that month in degrees Fahrenheit
    short low;      //The lowest temperature of that month in degrees Fahrenheit
    float avg;      //The average temperature of that month in degrees Fahrenheit
};
//Enumerated Data types
enum MONTHS {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
// Function Prototype
float avgRain(Rain []);
float avgTemp(Rain []);
short lowTmp(Rain [],char &);
short highTmp(Rain [], char &);
void getTemp(Rain []);
  int main(int argc, char** argv){
    //Declare Variables
    const char YR=12;//Total number of months out of the year
  	Rain months[YR]; //Array of 12 Rain structs
  	short high;      //Highest temperature of the year
  	short low;       //Lowest Temperature of the year
  	float avgR;      //Monthly Average Rainfall
  	float avgT;      //Monthly average temperature
  	float tot;       //Total rainfall for the year
  	char highIndx;   //Indx of month with the highest temperature
  	char lowIndx;    //Indx of month with the lowest temperature
  	//Gather Inputs
  	getTemp(months);
    //Compute Monthly Average Rainfall
    avgR=avgRain(months);
    //Computer Average temperature
    avgT=avgTemp(months);
    //Find lowest temperatures 
    low=lowTmp(months,lowIndx);
    //Find highest temperatures 
    high=highTmp(months,highIndx);
    //Display Results
    cout<<fixed<<left;
    cout<<"Average Rainfall "<<setprecision(1)<<avgR<<" inches/month"<<endl
        <<"Lowest  Temperature "<<months[lowIndx].mnth
        <<"  "<<low<<" Degrees Fahrenheit"<<endl
        <<"Highest Temperature "<<months[highIndx].mnth
        <<"  "<<high<<" Degrees Fahrenheit"<<endl
        <<setprecision(0)<<"Average Temperature for the year "
        <<avgT<<" Degrees Fahrenheit"<<endl;
    return 0;
    }
void getTemp(Rain months[]){
    for(int i=JAN;i<=DEC;i++){
        int j=0;
        cin>>months[i].mnth;
        cin>>months[i].tot;
        cin>>months[i].low;
        cin>>months[i].high;
        months[i].avg=((months[i].low+months[i].high)/2);
        cin.ignore();
    }
}
float avgRain(Rain months[]){
    float avg=0;
	for(int i=JAN;i<=DEC;i++){
	    avg+=months[i].tot;
	}
	avg/=DEC+1;
	return avg;
}
float avgTemp(Rain months[]){
    float avgT=0;
    for(int i=JAN;i<=DEC;i++){
	    avgT+=months[i].avg;
	}avgT/=static_cast<float>((DEC+1));
    return avgT;
}
short lowTmp(Rain months[],char &lowIndx){
	short low=months[JAN].low;
	lowIndx=JAN;
	for (int i=FEB;i<=DEC;i++){
		if (months[i].low<low)
			low=months[i].low;
	}
	return low;
}
short highTmp(Rain months[],char &highIndx){
    short high=months[JAN].high;
    highIndx=JAN;
	for (int i=FEB;i<=DEC;i++){
		if (months[i].high>high){
			high=months[i].high;
			highIndx=i;
		}
	}
    return high;
}