/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 17, 2020, 12:45 PM
 * 
 * Purpose: 
 * 
 */
//User Libraries
#include "CC.h"

//Global Constants
const int ITER = 10000;

int main(int argc, char** argv) {
    
    srand(time(0));
    
    float valid   = 0;
    float invalid = 0;
    
    for(int i = 0; i < ITER; i++) {
        CC a;
        //a.display();
        a.flip();
        (a.check())? valid++ : invalid++;
    }
    
    cout << "Valid after flipping   : " << valid << endl;
    cout << "Invalid after flipping : " << invalid << endl;
    cout << "Valid Percentage  : " << (valid/ITER)*100 << "%" << endl;
    cout << "Invalid Percentage: " << (invalid/ITER)*100 << "%" << endl;
    return 0;
}
