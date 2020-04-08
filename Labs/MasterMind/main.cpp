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


//Science and Math, Conversions, Higher Dimensions


//constants to follow


//Function Prototypes
string get_str();
bool check_str(string);

//Execution Starts Here

int main(int argc, char** argv) {

    //Set Random Number Seed Here
    srand(time(0));

    //Declare Variables
    MM a;
    string b;
    int attempts;
    
    cout << "C = Correct value and correct location." << endl;
    cout << "I = Correct value but incorrect location." << endl;
    cout << "X = Incorrect value." << endl;
    
    //To see the code, remove the forward slashes from the next comment!
    a.display();
    
    //Initiate the game
    do{
        b = get_str();
        a.parseGuess(b);
        attempts++;
    }
    while(!a.isCodeBroken());

    //Display the outputs
    cout << "Congratulation! You broke the code in " << attempts << " attempt(s)" << endl;
    
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

string get_str(){
    string str;
    do {
        cout << "Input: ";
        getline(cin,str,'\n');
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        if(!check_str(str)) {
            cout << "INVALID ENTRY! Please, enter a valid number." << endl;
        }
    }
    while(!check_str(str));
    return str;
}