/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on June 6, 2020, 8:18 PM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
#include <string>
#include <cmath>
#include <algorithm>

using namespace std; //Library Scope

//User Libraries


//Global Constants


//Science and Math, Conversions, Higher Dimensions


//constants to follow


//Function Prototypes
void test(int);
void test2(int);
//Execution Starts Here

int main(int argc, char** argv) {

    //Set Random Number Seed Here
    


    //Declare Variables - Known and Unknown, units, range, description
    //string str1= "00";
    //string str2= "11";
    //string str3= str1+str2;
    //Initialize Variables
    
    int a = numeric_limits<int>::max();
    
    cout << "Size of a: " << sizeof(a) << endl;
    cout << "Value of a: " << a << endl;



    //Map inputs to outputs -> i.e. process the inputs



    //Display the outputs
    //cout << str3 << endl;
    /*
    for(int i=0; i<5; i++) {
        cout << pow(10, i) << endl;
        test2(pow(10,i));
    }
     */
    /*for(int i = 0; i<10; i++) {
        test(i);
    }*/
    //test2(1);



    //Clean up - File closing, memory deallocation, etc....



    //Exit Stage Right!

    return 0;
}

//Function Implementations
void test(int i){
    static int testV = 0;
    cout << testV << endl;
    testV++;
    static int a[] = {0,0,0};
    cout << a[1] << endl;
    a[1] = i;
    for(int j = 0; j<3;j++) {
        cout << a[j];
    }
    cout << endl;
}

void test2(int a) {
    string (*stringify)(int)=
        [] (int n){ 
            if(10>n) {
                return "000"+to_string(n);
            }
            else if(100>n) {
                return "00"+to_string(n);
            }
            else if(1000>n) {
                return "0"+to_string(n);
            }
            else return to_string(n);
    };
    
    string (*response)(char, char)=
        [] (char rr, char rw){ 
            int cc =static_cast<int>(rr);
            int cw =static_cast<int>(rw);
            string str = "";
            for(int i=0; i<cc;i++){
                str +="C";
            }
            for(int i=0; i<cw;i++){
                str +="W";
            }
            return str;
    };
    
    cout << response(1,3) << endl;
}