/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on November 14th 2021
 * Purpose: Create a class called Date and implement it
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <iomanip> //setprecision,fixed,showpoint
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Classes
class Date{
private:
    int month;
    int day;
    int year;
public:
    void setData(int,int,int);      //Set date
    int getMonth() const;           //Get month
    int getDay() const;             //Get day
    int getYear() const;            //Get Year
    void showDate() const;          //Displays date
};


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    Date fecha;     //Spanish for date
    int x;          //Month
    int y;          //Day
    int z;          //Year
    //Input or initialize values Here
    //Prompth user for month,day and year
    do{
    cout<<"Enter the month as a number. ";
    cin>>x;
    }while(x>12&&x<1);  //Input validation
    do{
    cout<<"Enter the day as a number. ";
    cin>>y;
    }while(y>31&&y<1);  //Input validation
    do{
    cout<<"Enter the year as a number. ";
    cin>>z;
    }while(z>2099&&z<0);    //Input Validation
    //Store month day and year into class
    fecha.setData(x,y,z);
    //Display month day and year
    fecha.showDate();
    //Output the result
    
    //Exit
    return 0;
}
void Date::setData(int x,int y,int z){
    month=x;
    day=y;
    year=z;
}
int Date::getMonth() const{
    return month;
}
int Date::getDay() const{
    return day;
}
int Date::getYear() const{
    return year;
}
void Date::showDate() const{
    cout<<month<<"/"<<day<<"/"<<year<<endl;
    month==1?cout<<"January ":
    month==2?cout<<"February ":
    month==3?cout<<"March ":
    month==4?cout<<"April ":
    month==5?cout<<"May ":
    month==6?cout<<"June ":
    month==7?cout<<"July ":
    month==8?cout<<"August ":
    month==9?cout<<"September ":
    month==10?cout<<"October ":
    month==11?cout<<"November ":
              cout<<"December ";
    cout<<day<<", "<<year<<endl;
    cout<<day<<" ";
    month==1?cout<<"January ":
    month==2?cout<<"February ":
    month==3?cout<<"March ":
    month==4?cout<<"April ":
    month==5?cout<<"May ":
    month==6?cout<<"June ":
    month==7?cout<<"July ":
    month==8?cout<<"August ":
    month==9?cout<<"September ":
    month==10?cout<<"October ":
    month==11?cout<<"November ":
              cout<<"December ";
    cout<<year<<endl;
}