/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on February 26, 2020, 2:46 PM
 * 
 * Purpose: Demonstration of Luhn's Algorithms.
 * 
 */

//System Level Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
using namespace std; //Library Scope

//User Libraries


//Global Constants


//Science and Math, Conversions, Higher Dimensions


//constants to follow


//Function Prototypes
void string_to_int_array(string, int option);
string string_obtainer();
bool check_string(string);
void parity_maker(int*,int);
void check_parity(int*, int);
void option(int);
void menu();
void display_menu();

//Execution Starts Here

int main(int argc, char** argv) {
    menu();
    //Set Random Number Seed Here


    //Declare Variables - Known and Unknown, units, range, description

    
    //Initialize Variables    
    

    //Map inputs to outputs -> i.e. process the inputs
   
    
    //Display the outputs


    //Clean up - File closing, memory deallocation, etc....

    
    //Exit Stage Right!

    return 0;
}

//Function Implementations
void string_to_int_array(string a, int option) {
    //This function converts the string of digits entered by the the user 
    //to an array of integers.
    int len = a.length();
    int nums[len];
    
    //Convert from char to integers
    for(int i=0; i < len; i++) {
        nums[i] =((int)a[i]-48);
    }
    //Branch to the right case
    (option ==1)? parity_maker(nums,len) : check_parity(nums, len);
};

bool check_string(string a) {
    //Input validation function (No tolerance for BS entries!)
    bool is_int=true;
    for(int i=0; i<a.length(); i++) {
        if(a[i]< '0' || a[i]> '9') {
            is_int = false;
        }
    }
    return is_int;
};

string string_obtainer(){
    string str;
    do {
        cout << "CC#: ";
        cin >> str;
        if(!check_string(str)) {
            cout << "INVALID ENTRY! Please, enter a a valid credit card number." << endl;
        }
    }
    while(!check_string(str));
    return str;
}

void check_parity(int* n, int len) {
    int sum = 0;
    for(int i=len-2; i>=0; i--) {
        if((2*n[i])>9 && i%2 == (len)%2) {
            sum += (2*n[i]-9);
        }
        else if(2*n[i]<9 && i%2 == (len)%2) {
            sum += (2*n[i]);
        }
        else {
            sum += n[i];
        }
    }
    sum *= 9;
    int parity = sum%10;
    cout << "Last Digit  : " << n[len-1] << endl;
    cout << "Parity Digit: " <<parity << endl;
    (parity==n[len-1])? cout << "Valid!"<< endl : cout << "Invalid!" << endl;
};

void parity_maker(int* n,int len){
    int sum = 0;        //Initiating sum
    //Applying Luhn's Algorithm to find the parity digit
    for(int i=len-1; i>=0; i--) {
        if((2*n[i])>9 && i%2 == (len-1)%2) {
            sum += (2*n[i]-9);
        }
        else if(2*n[i]<9 && i%2 == (len-1)%2) {
            sum += (2*n[i]);
        }
        else {
            sum += n[i];
        }
    }
    sum *= 9;
    int parity = sum%10;
    cout << "Parity Digit: " << parity << endl;
};

void display_menu() {
    cout << "|||  Main Menu   |||" << endl;
    cout << "Please make a choice 1~3:" << endl;
    cout << "1) Find the parity digit for a string of digits." << endl;
    cout << "2) Check the validity of a string of digits(CC Check)." << endl;
    cout << "3) To close the program." << endl;
};

void menu() {
    int choice;
    do
    {
        display_menu(); //Display the main menu and waits for user's entry.
        cin >> choice;
        cin.clear();
        cin.ignore(1000,'\n');
        if(choice < 1 || choice > 3)
        {
            cout << "ERROR! Please chose a correct option from 1 to 3." << endl;
        }
        switch(choice)
        {
            case 1: option(choice); //Find the parity
                break;
            case 2: option(choice); //Check the parity
                break;
        }
    }
    while(choice != 3);
};

void option(int choice) {
    string str;     //The variable str stores a a string obtained from the user
                    //to check for or create the parity number
    do {
        cout << "CC#: ";
        cin >> str;
        if(check_string(str)) {
            string_to_int_array(str, choice);
        }
        else {
            cout << "INVALID ENTRY! Please, enter a a valid credit card number." << endl;
        }
    }
    while(!check_string(str));
};


