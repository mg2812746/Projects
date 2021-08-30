/* 
 * File:   main.cpp
 * Author: mikey
 * Purpose: This program counts the number of words entered by the user
 * Created on August 24, 2021, 10:05 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;
// Function Prototype
int TotalWords(char *ptr);
int main() {
	const int SIZE = 80;	//CONST  - Size of user-entered string
	char userStr[SIZE];	//INPUT  - User-entered string
	char *ptr;		//INPUT  - Pointer to user-entered string
	int totalWords;		//OUTPUT - Total number of words in string
// Assign pointer to user-entered string
	ptr = userStr;
// Prompt user to enter a string
	cout << "Enter a string."<<endl;
	fgets(userStr, SIZE, stdin);    
	totalWords = TotalWords(ptr);   //Compute and assign total words
// Display total number of words
	cout << "The total number of words are " 
		 << totalWords;
	return 0;
}
int TotalWords(char *ptr){
    int totalSize;		//INPUT  - Total characters of user-entered string
    int totalWords;		//INPUT  - Total number of words in string
// Assign Total Size of Characters in Array To Variable
	totalSize = strlen(ptr);
// Initialize total words
	totalWords = 0;
// Display Entire C-String
	for (int counter = 0; counter <= totalSize; counter++)
	{
		if (isspace(ptr[counter]))
			totalWords++;
	}
	return totalWords;
}