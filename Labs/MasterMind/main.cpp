/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 28, 2020, 1:12 AM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
using namespace std;    //Library Scope

//User Libraries
#include "MM.h"         //MasterMind Libray

//Global Constants
int     DEFAULT_LENGTH       = 4;
bool    DEFAULT_DUPLICATE_OK = false;

//Function Prototypes
string get_str(const int&);
bool check_str(string);
void master_mind(const int&, const bool&);
void main_menu();
void update_length(int&, const bool&);
void update_duplicate_ok(const int&, bool&);
void display_main_menu();
void display_header();

//Execution Starts Here
int main(int argc, char** argv) {

    //Set Random Number Seed Here
    srand(time(0));

    //Declare Variables
    int length       = DEFAULT_LENGTH;
    bool duplicateOk = DEFAULT_DUPLICATE_OK;
    int choice       = 0;
    
    display_header();
    
    do
    {
        display_main_menu();
        cin >> choice;
        cin.clear();
        cin.ignore(1000,'\n');
        if(choice < 1 || choice > 4)
        {
            cout << "ERROR! Please chose a correct option from 1 to 4." << endl;
        }
        switch(choice)
        {
            case 1: master_mind(length,duplicateOk);
                break;
            case 2: update_length(length,duplicateOk);
                break;
            case 3: update_duplicate_ok(length, duplicateOk);
                break;
        }
    }
    while(choice != 4);
    
    return 0;
}

//Function Implementations
bool check_str(string a) {
    //Input validation function (No tolerance for BS entries!)
    bool is_int=true;
    for(int i=0; i<a.length(); i++) {
        if(a[i]< '0' || a[i]> '9') {
            is_int = false;
        }
    }
    return is_int;
};

string get_str(const int& length){
    string str;
    do {
        cout << "Input: ";
        getline(cin,str,'\n');
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(!check_str(str)) {
            cout << "INVALID ENTRY! Please, enter a valid number." << endl;
        }
        if(str.length() != length) {
            cout << "Please enter exactly " << length << " Digits." << endl;
        }
    }
    while(!check_str(str) || str.length() != length);
    return str;
}

void master_mind(const int& length, const bool& duplicateOk) {
    MM a(length,duplicateOk);
    string b;
    int attempts = 0;
    
    cout << "C = Correct value and correct location." << endl;
    cout << "I = Correct value but incorrect location." << endl;
    cout << "X = Incorrect value." << endl;
    
    //To see the code, remove the forward slashes from the next comment!
    //a.display();
    
    //Initiate the game
    do{
        b = get_str(length);
        a.parseGuess(b);
        attempts++;
    }
    while(!a.isCodeBroken());

    //Display the outputs
    cout << "Congratulation! You broke the code in " << attempts << " attempt(s)" << endl << endl;
}

void update_length(int& length, const bool& duplicateOk) {
    int update = 0;
    cout << "The code length is currently set to " << length << " digits." << endl;
    cout << "Enter the desired code length greater than zero (less than 10 if duplicates are not allowed): ";
    do {
        cin >> update;
        cin.clear();
        cin.ignore(1000,'\n');
        if(update < 1 || update > 9 && duplicateOk) {
            cout << "INCORRECT ENTERY! Please input a number (less than 10 if duplicates are not allowed)" << endl;
            cout << "Enter the desired code length: ";
        }
        else{
            cout << "The new code length is : " << update << endl;
            length = update;
        }  
    }
    while(update < 1 || update > 9 && duplicateOk);
}

void update_duplicate_ok(const int& length, bool& duplicateOk) {
    int choice;
    do
    {
        cout << "Duplicates are currently ";
        (duplicateOk)? cout << "allowed!" << endl: cout << "not allowed!" << endl;
        cout << "Make duplicates:" << endl;
        cout << "1) Allowed." << endl;
        cout << "2) Not Allowed." << endl;
        cout << "3) Return." << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(1000,'\n');
        if(choice < 1 || choice > 3)
        {
            cout << "ERROR! Please chose a correct option from 1 to 3." << endl;
        }
        switch(choice)
        {
            case 1: duplicateOk = true;
                break;
            case 2: if(length>9) {
                                    cout << "To prohibit duplicates, code"
                                            " length must be 9 or"
                                            " less!" << endl;
                                 } else {duplicateOk = false;}
                break;
        }
    }
    while(choice != 3);
}

void display_main_menu(){
    cout << "Choose from options 1~4:" << endl;
    cout << "1) Play Master Mind." << endl;
    cout << "2) Change code length." << endl;
    cout << "3) Change duplicate status." << endl;
    cout << "4) Exit." << endl;
}

void display_header(){
    cout << "|*************|" << endl;
    cout << "|*Mastermind*|" << endl;
    cout << "|*************|" << endl;
}