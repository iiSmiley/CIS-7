/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on April 7, 2020, 9:56 PM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library

using namespace std; //Library Scope

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants
const string str =  "Then out spake brave Horatius,\n\n"
                    "The Captain of the Gate:\n\n"
                    "To every man upon this earth\n\n"
                    "Death cometh soon or late.\n\n"
                    "And how can man die better\n\n"
                    "Than facing fearful odds,\n\n"
                    "For the ashes of his fathers,\n\n"
                    "And the temples of his gods.";

int main(int argc, char** argv) {

    //Display The string before hashing
    cout << "The string to be hashed: " << endl << endl;
    cout << str << endl << endl;
    
    //Displaying the hashed values
    cout << " 1. RS-Hash Function Value:   " << RSHash  (str) << endl;
    cout << " 2. JS-Hash Function Value:   " << JSHash  (str) << endl;
    cout << " 3. PJW-Hash Function Value:  " << PJWHash (str) << endl;
    cout << " 4. ELF-Hash Function Value:  " << ELFHash (str) << endl;
    cout << " 5. BKDR-Hash Function Value: " << BKDRHash(str) << endl;
    cout << " 6. SDBM-Hash Function Value: " << SDBMHash(str) << endl;
    cout << " 7. DJB-Hash Function Value:  " << DJBHash (str) << endl;
    cout << " 8. DEK-Hash Function Value:  " << DEKHash (str) << endl;
    cout << " 9. FNV-Hash Function Value:  " << FNVHash (str) << endl;
    cout << "10. BP-Hash Function Value:   " << BPHash  (str) << endl;
    cout << "11. AP-Hash Function Value:   " << APHash  (str) << endl;


    //Exit Stage Right!

    return 0;
}