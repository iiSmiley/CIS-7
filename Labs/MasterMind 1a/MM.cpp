/* 
 * File:   MM.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 28, 2020, 1:12 AM
 * 
 * Purpose: 
 * 
 */
#include "MM.h"

//Default constructor
MM::MM() {
    this->length        = 4;
    this->code          = new int[this->length];
    this->codeStatus    = false;
    this->duplicateOk   = true;
    this->currentRR     = 0;
    this->currentRW     = 0;
    

    for(int i = 0; i < this->length ; i++) {
        this->code[i] = (rand()%10);
    }
}

//Copy constructor
MM::MM(const MM& orig) {
    this->length        = orig.length;
    this->code          = new int[this->length];
    this->codeStatus    = orig.codeStatus;
    this->duplicateOk   = orig.duplicateOk;
    this->currentRR     = orig.currentRR;
    this->currentRW     = orig.currentRW;
    
    //Populate the code array (Create the code)
    for(int i = 0; i < this->length ; i++) {
        this->code[i] = orig.code[i];
    }
}

//Secondary constructor
MM::MM(const int& length, const bool& duplicateOk) {
    this->length        = length;
    this->code          = new int[this->length];
    this->codeStatus    = false;
    this->duplicateOk   = duplicateOk;
    
    //Populate the code array (Create the code)
    for(int i = 0; i < this->length ; i++) {
        this->code[i] = (rand()%10);
        
        //If duplicate is not allowed, then check for duplicates.
        if(i>0 && !duplicateOk) {
            for(int j = i-1; j >= 0; j--) {
                if(this->code[i] == this->code[j]) {
                    i--;
                }
            }
        }
    }
}

//Tertiary constructor
MM::MM(const string& code) {
    this->length        = code.length();
    this->code          = new int[this->length];
    this->codeStatus    = false;
    
    //Populate the code array (Create the code)
    for(int i = 0; i < this->length ; i++) {
        this->code[i] = ((int)code[i]-48);
    }
}

//Destructor
MM::~MM() {
    //Delete the data from memory
    delete this->code;
    //Deallocate the pointer
    this->code = NULL;
}


void MM::display() {
    cout << "The random code to break: ";
    
    //Displaying the code in X X X X pattern
    for(int i = 0; i < this->length ; i++) {
        cout << this->code[i] << " ";
    }
    cout << endl;
}

void MM::displayV2() {
    
    //Displaying the code in XXXX pattern
    for(int i = 0; i < this->length ; i++) {
        cout << this->code[i] << "";
    }
    cout << "   ";
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
    display_resultsV2(corrLoc, incorrLoc);
    this->currentRR = corrLoc;
    this->currentRW = incorrLoc;
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

void MM::display_resultsV2(int corrLoc, int incorrLoc) {
    cout << "rr: " << corrLoc << "  rw: " << incorrLoc;
}

bool MM::isCodeBroken() {
    return this->codeStatus;
}

int MM::getRR() {
    return this->currentRR;
}

int MM::getRW() {
    return this->currentRW;
}