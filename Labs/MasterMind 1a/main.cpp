/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on May 5, 2020, 3:12 AM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
using namespace std;    //Library Scope

//User Libraries
#include "MM.h"         //MasterMind Class

//Execution Starts Here
int main(int argc, char** argv) {

    //Set Random Number Seed Here
    srand(time(0));

    //Declare Variables
    MM a("9876");
    string b = "";
    int rr1, rr2, rr3, rr4, rw1, rw2, rw3, rw4, sum, s1, s2, s3, s4;
    rr1 = rr2 = rr3 = rr4 = rw1 = rw2 = rw3 = rw4 = sum = s1 = s2 = s3 = s4 = 0;
    bool sumMoreThanFour = false;
    
    for(int i = 0; i < 10000; i++) {
        b = to_string(i);
        a.displayV2();
        cout << b << "  ";
        a.parseGuess(b);
        
        if(a.getRR() == 1) rr1++;
        else if (a.getRR() == 2) rr2++;
        else if (a.getRR() == 3) rr3++;
        else if (a.getRR() == 4) rr4++;
        
        if (a.getRW() == 1) rw1++;
        else if (a.getRW() == 2) rw2++;
        else if (a.getRW() == 3) rw3++;
        else if (a.getRW() == 4) rw4++;
        
        sum = a.getRR() + a.getRW();
        if(sum == 1) s1++;
        else if (sum == 2) s2++;
        else if (sum == 3) s3++;
        else if (sum == 4) s4++;
        
        if(sum > 4) sumMoreThanFour = true;
        cout << "  Sum: " << sum;
        cout << endl;
    }
    cout << endl;
    
    cout << "Times 4 right come up " << rr4 << endl;
    cout << "Times 3 right come up " << rr3 << endl;
    cout << "Times 2 right come up " << rr2 << endl;
    cout << "Times 1 right come up " << rr1 << endl << endl;
    
    cout << "Times 4 wrong come up " << rw4 << endl;
    cout << "Times 3 wrong come up " << rw3 << endl;
    cout << "Times 2 wrong come up " << rw2 << endl;
    cout << "Times 1 wrong come up " << rw1 << endl << endl;
    
    cout << "Times sum = 4 come up " << s4 << endl;
    cout << "Times sum = 3 come up " << s3 << endl;
    cout << "Times sum = 2 come up " << s2 << endl;
    cout << "Times sum = 1 come up " << s1 << endl << endl;
    
    cout << "Any sum more than 4? ";
    (sumMoreThanFour)? cout << "Yes!" << endl : cout << "No!" << endl;
    return 0;
}
