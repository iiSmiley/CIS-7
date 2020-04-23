/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BloomFilter.h
 * Author: User 1
 *
 * Created on April 22, 2020, 4:33 PM
 */

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
#include <ctime>        //C Time Library
#include <cmath>        //Power functions
#include <iomanip>      //For manipulation
#include <string>       //String Library
#include "GeneralHashFunctions.h"   //Hash Functions

using namespace std;    //Library Scope
class BloomFilter {
public:
    BloomFilter();                          //Default constructor
    BloomFilter(int, int);                       //Secondary constructor
    BloomFilter(const BloomFilter& orig);   //Copy constructor
    virtual ~BloomFilter();                 //Destructor
    void  pushItem(string);
    void  print_BitVector();
    void  print_elementList();
    bool  itemLookUp(string);
    float falsePositiveRate();
private:
    int     n;
    int     m;
    int     k;
    bool*   bitVector;
    string* elementsList;
    
};

#endif /* BLOOMFILTER_H */

