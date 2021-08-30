/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Created on August 23, 2021, 10:16 AM
 * Purpose: Reverse Order of Cstring
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
// Function Prototype
void ReverseCString(char *ptr);
int main() {
	const int SIZE = 80;	//CONST  - Size of user-entered string
	char userStr[SIZE];	//INPUT  - User-entered string
	char *ptr;		//INPUT  - Pointer to user-entered string
// Assign pointer to user-entered string
	ptr = userStr;
// Prompt user to enter a string
	cout << "Enter a string.";
	cin >> userStr;
	cout << endl;
// Output
	ReverseCString(ptr);    //Display reversed c-string
	return 0;
}
void ReverseCString(char *ptr)
{
	int totalSize;	//INPUT  - Total characters of user-entered string
	char temp;	//INPUT  - Temporary Placeholder
// Assign Total Size of Characters in Array To Variable
	totalSize = strlen(ptr);
// Reverse Order of String
	for (int count = 0; count < totalSize / 2; count++)
	{
		temp = ptr[count];
		ptr[count] = ptr[totalSize - count];
		ptr[totalSize - count] = temp;
	}
// Display Entire C-String
	for (int counter = 0; counter <= totalSize; counter++)
		cout << ptr[counter];
}