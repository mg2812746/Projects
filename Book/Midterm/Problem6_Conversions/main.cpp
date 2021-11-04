/* 
 * File:   main.cpp
 * Author: Miguel Galvez
 * Purpose: Display Answers to Conversions from Problem 6
 * Created on October 22, 2021, 2:29 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout<<"x means repeating\n";
    cout<<"Part a) \n"
        <<"49.1875 = 31.6 base 16\n"
        <<"49.1875 = 00110001.0011 base 2\n"
        <<"49.1875 = 61.14 base 8\n"
        <<"49.1875 = 62600006 NASA Format\n"
        <<"3.07421875 = 3.13 base 16\n"
        <<"3.07421875 = 0011.00010011 base 2\n"
        <<"3.07421875 = 3.045 base 8\n"
        <<"3.07421875 = 61300002 NASA Format\n"
        <<"0.2 = 3.333x base 16\n"
        <<"0.2 = 0.00110011xxxx base 2\n"
        <<"0.2 = 0.14631463xxxx base 8\n"
        <<"0.2 = 666666FF NASA Format\n";
    cout<<"Part b) \n"
        <<"-49.1875 = CF.D base 16\n"
        <<"-49.1875 = 11001111.1101 base 2\n"
        <<"-49.1875 = 317.64 base 8\n"
        <<"-49.1875 = 67E80008 NASA Format\n"
        <<"-3.07421875 = D.EE base 16\n"
        <<"-3.07421875 = 1101.11101110 base 2\n"
        <<"-3.07421875 = 15.734 base 8\n"
        <<"-3.07421875 = 6F700004 NASA Format\n"
        <<"-0.2 = Dx base 16\n"
        <<"-0.2 = 0.00110011xxxx base 2\n"
        <<"-0.2 = 0.64xx base 8\n"
        <<"-0.2 = 6EEEEE00 NASA Format\n";
    cout<<"Part c) \n"
        <<"69999902 = 3.4CCCCC8 base 16\n"
        <<"69999903 = 6.99999   base 16\n"
        <<"966667FF = 1.A666C8  base 16\n";
    return 0;
}

