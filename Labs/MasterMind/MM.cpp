/* 
 * File:   CC.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 28, 2020, 1:12 AM
 * 
 * Purpose: 
 * 
 */
#include "MM.h"

MM::MM() {
    this->length     = 4;
    this->code       = new int[this->length];
    this->codeStatus = false;

    for(int i = 0; i < this->length ; i++) {
        this->code[i] = (rand()%10);
    }
}

MM::MM(const MM& orig) {
    this->length     = orig.length;
    this->code       = new int[this->length];
    this->codeStatus = orig.codeStatus;
    
    for(int i = 0; i < this->length ; i++) {
        this->code[i] = orig.code[i];
    }
}

MM::~MM() {
    delete this->code;
    this->code = NULL;
}

void MM::display() {
    cout << "The random code to break: ";
    
    for(int i = 0; i < this->length ; i++) {
        cout << this->code[i] << " ";
    }
    cout << endl;
}

void MM::parseGuess(string str) {
    //Converting the string of digits entered by the the user 
    //to an array of integers.
    int len         = str.length();
    int nums[len];
    int corrLoc     = 0;
    int incorrLoc   = 0;
    bool iIsCounted[len];
    bool jIsCounted[len];
    
    for(int i=0; i < len; i++) {
        iIsCounted[i] = false;
        jIsCounted[i] = false;
    }
    
    //Converting from char to integers
    for(int i=0; i < len; i++) {
        nums[i] =((int)str[i]-48);
    }
    
    //Check for equality
    //Mirror check
    for (int i=0; i < len; i++) {
            if(this->code[i] == nums[i] && !iIsCounted[i] && !jIsCounted[i]) {
                corrLoc++;
                iIsCounted[i] = true;
                jIsCounted[i] = true;
            }
    }
    
    //Cross check
    for(int i=0; i < len; i++) {    
        for (int j=0; j < len; j++) {
            if(this->code[j] == nums[i] && !iIsCounted[i] && !jIsCounted[j]) {
                incorrLoc++;
                iIsCounted[i] = true;
                jIsCounted[j] = true;
            }
        }
    }
    
    if(corrLoc == len) {
        this->codeStatus = true;
    }
    //Display Results
    display_results(corrLoc, incorrLoc);
}

void MM::display_results(int corrLoc, int incorrLoc) {
    int n = 0;
    for(int i=0; i<corrLoc; i++) {
        cout << "C";
        n++;
    }
    for(int i=0; i<incorrLoc; i++) {
        cout << "I";
        n++;
    }
    for(int i=n; i < this->length; i++) {
        cout << "X";
    }
    cout << endl;
}

bool MM::isCodeBroken() {
    return this->codeStatus;
}