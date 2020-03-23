/* 
 * File:   CC.cpp
 * Author: User 1
 * 
 * Created on March 22, 2020, 11:05 PM
 */

#include "CC.h"

//Default Constructor
CC::CC() {
    int r = rand()%4;
    
    //0 = Visa
    //1 = MasterCard
    //2 = Discover
    //3 = American Express
    
    if(r == 0) {
        this->type      = "Visa";
        this->len       = 16;
        this->ccNum     = new int[this->len];
        this->ccNum[0]  = 4;
        //Populate
        for(int i = 1; i < (this->len-1); i++){
            this->ccNum[i] = rand()%10;
        }
        this->ccNum[this->len-1] = luhn();
    }
    else if(r == 1) {
        this->type      = "Master Card";
        this->len       = 16;
        this->ccNum     = new int[this->len];
        this->ccNum[0]  = 5;
        this->ccNum[1]  = rand()%6;
        
        for(int i = 2; i < (this->len-1); i++){
            this->ccNum[i] = rand()%10;
        }
        this->ccNum[this->len-1] = luhn();
    } 
    else if(r == 2) {
        this->type = "Discover";
        this->len = 16;
        this->ccNum = new int[this->len];
        this->ccNum[0]  = 6;
        this->ccNum[1]  = 0;
        this->ccNum[2]  = 1;
        this->ccNum[3]  = 1;
        
        for(int i = 4; i < (this->len-1); i++){
            this->ccNum[i] = rand()%10;
        }
        this->ccNum[this->len-1] = luhn();
    }
    else if(r == 3) {
        this->type = "American Express";
        this->len = 15;
        this->ccNum = new int[this->len];
        this->ccNum[0]  = 3;
        if(rand()%2 == 0) {
            this->ccNum[1]  = 4;
        }
        else {
            this->ccNum[1]  = 7;
        }
        
        for(int i = 2; i < (this->len-1); i++){
            this->ccNum[i] = rand()%10;
        }
        this->ccNum[this->len-1] = luhn();
    }
    else {
        this->type  = "";
        this->len   = 0;
        this->ccNum = NULL;
        cout << "Error Generating the Credit Card!" << endl;
    }
    
}
//Copy constructor
CC::CC(const CC& orig) {
    this->type = orig.type;
    this->len  = orig.len;
    for(int i = 0; i < this->len; i++) {
        this->ccNum[i] = orig.ccNum[i];
    }
}
//Destructor
CC::~CC() {
    delete[] this->ccNum;
    this->ccNum = NULL;
}

int CC::luhn() {
    int sum = 0;        //Initiating sum
    //Applying Luhn's Algorithm to find the parity digit
    for(int i=(this->len-2); i>=0; i--) {
        if((2*this->ccNum[i])>9 && i%2 == (this->len-2)%2) {
            sum += (2*this->ccNum[i]-9);
        }
        else if(2*this->ccNum[i]<9 && i%2 == (this->len-2)%2) {
            sum += (2*this->ccNum[i]);
        }
        else {
            sum += this->ccNum[i];
        }
    }
    sum *= 9;
    sum %= 10;
    return sum;
}

bool CC::check() {
    int sum = 0;        //Initiating sum
    //Applying Luhn's Algorithm to find the parity digit
    for(int i=(this->len-2); i>=0; i--) {
        if((2*this->ccNum[i])>9 && i%2 == (this->len-2)%2) {
            sum += (2*this->ccNum[i]-9);
        }
        else if(2*this->ccNum[i]<9 && i%2 == (this->len-2)%2) {
            sum += (2*this->ccNum[i]);
        }
        else {
            sum += this->ccNum[i];
        }
    }
    sum *= 9;
    sum %= 10; 
    if(sum == this->ccNum[len-1]) {
        return true;
    }
    else {
        return false;
    }
}

void CC::flip() {
    this->ccNum[(rand()%this->len)] = rand()%10;
}

void CC::display() {
    cout << left << setw(20) << this->type << setw(1) << "|";
    cout << left << setw(6) << this->len  << setw(1) << "|";
    cout << left;
    for(int i = 0; i < this->len; i++) {
        cout << this->ccNum[i];
    }
    cout << endl;
}

void CC::double_flip() {
    int first  = 0;
    int second = 0;
    bool exit  = false;
    
    do {
        first  = rand()%this->len;
        second = rand()%this->len;
        
        if(first != second) {
            this->ccNum[first] = rand()%10;
            this->ccNum[second] = rand()%10;
            exit = true;
            //cout << "Done double flipping " << first+1 << " and " << second+1 << endl;
        }    
    }
    while(!exit);
}

void CC::transpose() {
    int first  = 0;
    int second = 0;
    int temp   = 0;
    bool exit  = false;
    
    do {
        first  = rand()%this->len;
        second = rand()%this->len;
        
        if(first != second) {
            temp = this->ccNum[first];
            //swap!
            this->ccNum[first] = this->ccNum[second];
            this->ccNum[second] = temp;
            exit = true;
            //cout << "Done transposing " << first+1 << " and " << second+1 << endl;
        }
    }
    while(!exit);
}