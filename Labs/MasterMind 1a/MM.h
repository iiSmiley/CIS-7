/* 
 * File:   MM.h
 * 
 * Author: Omar Alkendi
 *
 * Created on March 28, 2020, 1:12 AM
 * 
 * Purpose: 
 * 
 */
#ifndef MM_H
#define MM_H
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
#include <ctime>        //C Time Library
#include <iomanip>      //For manipulation
#include <string>       //String Library
#include <algorithm>    //Algorithm Library (Used to remove whitespaces from input)
using namespace std;    //Library Scope

class MM {
public:
    MM();                       //Default constructor
    MM(const MM& orig);         //Copy constructor
    MM(const int&, const bool&);//Secondary constructor
    MM(const string&);//Tertiary   constructor
    virtual ~MM();              //Destructor
    void     display();
    void     displayV2();
    void     parseGuess(string);
    bool     isCodeBroken();
    void     setLength(const int&);
    int      getRR();
    int      getRW();
private:
    int     length;
    bool    duplicateOk;
    int*    code;
    bool    codeStatus;
    int     currentRR;
    int     currentRW;
    void    display_results(int corrLoc, int incorrLoc);
    void    display_resultsV2(int corrLoc, int incorrLoc);
};

#endif /* MM_H */

