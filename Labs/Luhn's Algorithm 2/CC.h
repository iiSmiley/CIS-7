/* 
 * File:   CC.h
 * Author: Omar Alkendi
 *
 * Created on March 17, 2020, 12:46 PM
 */
#ifndef CC_H
#define CC_H
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

class CC {
public:
    CC();                   //Default constructor
    CC(const CC& orig);     //Copy Constructor
    void flip();            //Randomly flips one digit
    bool check();           //Check for parity
    void display();         //Display Credit Card information
    
    virtual ~CC();
private:
    string  type;
    int     len;
    int*    ccNum;
    int     luhn();
};

#endif /* CC_H */

