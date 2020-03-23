/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 22, 2020, 11:05 PM
 * 
 * Purpose: 
 * 
 */
//User Libraries
#include "CC.h"

//Global Constants
const int ITER = 1000000;
const int N = 20;

int main(int argc, char** argv) {
    
    srand(time(0));
    
    float valid   = 0;
    float invalid = 0;
    /*
    for(int i = 0; i < ITER; i++) {
        CC a;
        //cout << fixed << left << setw(6) << setprecision(2) << i+1;
        //a.display();
        a.double_flip();
        (a.check())? valid++ : invalid++;
    }
    cout << "Double Flipping  Stats!" << endl; 
    cout << "Valid after double flipping   : " << valid << endl;
    cout << "Invalid after double flipping : " << invalid << endl;
    cout << "Valid Percentage  : " << (valid/ITER)*100 << "%" << endl;
    cout << "Invalid Percentage: " << (invalid/ITER)*100 << "%" << endl;
    */
    
    cout << "\nTransposing Stats!" << endl; 
    for(int j=0; j < N; j++){
        //Recycle the variables
        valid = invalid = 0;
        for(int i = 0; i < ITER; i++) {
            CC a;
            //cout << fixed << left << setw(6) << setprecision(2) << i+1;
            //a.display();
            a.transpose();
            (a.check())? valid++ : invalid++;
        }
    }
    cout << "Ave. Valid after transposing   : " << valid/N << endl;
    cout << "Ave. Invalid after transposing : " << invalid/N << endl;
    cout << "Ave. Valid Percentage  : " << (valid/ITER)*100 << "%" << endl;
    cout << "Ave. Invalid Percentage: " << (invalid/ITER)*100 << "%" << endl;
    return 0;
}
