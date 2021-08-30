/* 
 * File:   main.cpp
 * Author: Miguel Galvez    
 * Created on August 6, 2021
 * Purpose:  Compute Average Monthly Temperature
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>   //I/O Manipulators Library
using namespace std;

//User Libraries

//Global Constants
//Math, Science, Universal, Conversions, High Dimensioned Arrays

//Structures
struct Weather{
    float totRain,  //Total Rainfall
    highTemp,       //High Temperatures
    lowTemp,        //Low Temperature
    avgTemp;        //Average Monthly Temperature
};
//Enumerators
enum Months {JAN,FEB,MAR,APR,MAY,JUNE,JUL,AUG,SEP,OCT,NOV,DEC};
//Function Prototypes
void ReadWeatherStats(Weather []);
void ComputeMonthlyAvgTemp(Weather []);
float SearchHighestTemp(Weather [],char &);
float SearchLowestTemp(Weather [],char &);
float ComputeTotRainfall(Weather []);
float ComputeMonAvgAvg(Weather []);
//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the Random Number Seed
    
    //Declare Variables
    const char MONTHS = 12; //Total number of months
    char highIndx,          //Index in structure array of highest temp
    lowIndx;                //Index in structure array of lowest temp
    Weather year[MONTHS];   //Weather data for all months
    float highestT,         //Highest temperature for the year
    lowestT,                //Lowest temperature for the year
    totRain,                //Total rainfall of the year
    avgAvgTemp;             //Average of monthly average temperatures
    
    //Initialize Variables/Prompt User
    
    
    //Map Inputs to Outputs -> Process
    ReadWeatherStats(year);
    ComputeMonthlyAvgTemp(year);
    highestT=SearchHighestTemp(year, highIndx);
    lowestT=SearchLowestTemp(year, lowIndx);
    totRain=ComputeTotRainfall(year);
    avgAvgTemp=ComputeMonAvgAvg(year);
    //Display Inputs/Outputs
    cout<<fixed<<setprecision(2);
    for(int i=JAN;i<DEC;i++){
        cout<<"Average Monthly Rainfall: "
            <<year[i].totRain<<endl;
    }
    cout<<"Total Annual Rainfall: "<<totRain<<endl
        <<"Highest Annual Temperature: "<<highestT
        <<"Month With Highest Temperature: "<<highIndx+1<<endl
        <<"Lowest Annual Temperature: "<<lowestT
        <<"Month With Lowest Temperature: "<<lowIndx+1<<endl
        <<"Average of Average Monthly Temperature: "
        <<avgAvgTemp<<endl;
    
    //Exit the Program - Cleanup
    return 0;
}
void ReadWeatherStats(Weather year[]){
    for (int i=JAN;i<DEC;i++){ 
        cout<<"For Month "<<i+1<<": "<<endl
            <<"What is the total rainfall (inches)?";
        cin>>year[i].totRain;
        do{
        cout<<"What is the high temperature (Farenheit)?";
        cin>>year[i].highTemp;
        if(year[i].highTemp<-100||year[i].highTemp>140){
            cout<<"INPUT VALIDATION: Please enter a number "
                <<"between -100 and 140."<<endl;
        }
        }while(year[i].highTemp<-100||year[i].highTemp>140);
        do{
        cout<<"What is the low temperature (Farenheit)?";
        cin>>year[i].lowTemp;
        if(year[i].lowTemp<-100||year[i].lowTemp>140){
            cout<<"INPUT VALIDATION: Please enter a number "
                <<"between -100 and 140."<<endl;
        }
        }while(year[i].lowTemp<-100||year[i].lowTemp>140);
    }
}
void ComputeMonthlyAvgTemp(Weather year[]){
    float totTemp=0;        //accumulator
    for(int i=JAN;i<DEC;i++){
        totTemp+=year[i].highTemp;
        totTemp+=year[i].lowTemp;
        year[i].avgTemp=totTemp/2.0;
        totTemp=0;
    }
}
float SearchHighestTemp(Weather year[], char &highIndx){
    float highTmp;  //Highest Temperature of the Year
    highTmp=year[JAN].highTemp;
    highIndx=JAN;
    for(int i=JAN;i<DEC;i++){
        if(highTmp<year[i+1].highTemp){
            highTmp=year[i+1].highTemp;
            highIndx=i+1;
        }
    }
    return highTmp;
}
float SearchLowestTemp (Weather year[], char &lowIndx){
    float lowTmp;   //Lowest Temperature of the Year
    lowTmp=year[JAN].highTemp;
    lowIndx=JAN;
    for(int i=JAN;i<DEC;i++){
        if(lowTmp<year[i+1].highTemp){
            lowTmp=year[i+1].highTemp;
            lowIndx=i+1;
        }
    }
    return lowTmp;  
}
float ComputeTotRainfall(Weather year[]){
    float totRain=0;  //Total rainfall
    for(int i=JAN;i<DEC;i++){
        totRain+=year[i].totRain;
    }
    return totRain;
}
float ComputeMonAvgAvg(Weather year[]){
    float monAvgAvg=0;    //Average of Monthly Average
    for(int i=JAN;i<DEC;i++){
        monAvgAvg+=year[i].avgTemp;
    }
    monAvgAvg=(monAvgAvg/12);
    return monAvgAvg;
}