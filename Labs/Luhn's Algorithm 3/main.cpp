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
const int ITER = 10000;
const int N = 10;

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
    
    valid = invalid = 0;
    cout << "\nTransposing Stats! (Including the Parity Digit)" << endl; 
    for(int j=0; j < N; j++){
        //Recycle the variables
        //valid = invalid = 0;
        for(int i = 0; i < ITER; i++) {
            CC a;
            //cout << fixed << left << setw(6) << setprecision(2) << i+1;
            //a.display();
            a.transpose();
            (a.check())? valid++ : invalid++;
        }
        cout << "N= " << j+1 << "|Valid Percentage  : " << (valid/ITER)*(100/(j+1)) << "%" << endl;
        cout << "N= " << j+1 << "|Invalid Percentage: " << (invalid/ITER)*(100/(j+1)) << "%" << endl << endl;
    }
    cout << "Ave. Valid after transposing   : " << valid/N << endl;
    cout << "Ave. Invalid after transposing : " << invalid/N << endl;
    cout << "Ave. Valid Percentage  : " << (valid/ITER)*(100/N) << "%" << endl;
    cout << "Ave. Invalid Percentage: " << (invalid/ITER)*(100/N) << "%" << endl;
    
    valid = invalid = 0;
    cout << "\nTransposing Stats! (Excluding the Parity Digit)" << endl; 
    for(int j=0; j < N; j++){
        //Recycle the variables
        //valid = invalid = 0;
        for(int i = 0; i < ITER; i++) {
            CC a;
            //cout << fixed << left << setw(6) << setprecision(2) << i+1;
            //a.display();
            a.transposeV2();
            (a.check())? valid++ : invalid++;
        }
        cout << "N= " << j+1 << "|Valid Percentage  : " << (valid/ITER)*(100/(j+1)) << "%" << endl;
        cout << "N= " << j+1 << "|Invalid Percentage: " << (invalid/ITER)*(100/(j+1)) << "%" << endl << endl;
    }
    cout << "Ave. Valid after transposing   : " << valid/N << endl;
    cout << "Ave. Invalid after transposing : " << invalid/N << endl;
    cout << "Ave. Valid Percentage  : " << (valid/ITER)*(100/N) << "%" << endl;
    cout << "Ave. Invalid Percentage: " << (invalid/ITER)*(100/N) << "%" << endl;
    return 0;
}
