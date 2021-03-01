/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on May 30, 2020, 3:47 AM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
using namespace std; //Library Scope

//User Libraries
#include "GeneralHashFunctions.h"

//Global Constants
const string L1 = "Then out spake brave Horatius,\nThe Captain of the Gate:";
const string L2 = "To every man upon this earth\nDeath cometh soon or late.";
const string L3 = "And how can man die better\nThan facing fearful odds,\nand";
const string L4 = "For the ashes of his fathers,\nAnd the temples of his Gods.";
const string L1_modified = "Then out spake brave Mark,\nThe Captain of the Gate:";

//Functions Prototypes
void check(unsigned int, unsigned int*, unsigned int*,string);
int main(int argc, char** argv) {
    unsigned int merkleRoot = 0;
    unsigned int merkleBranch[2];
    unsigned int merkleLeaf[4];
    
    merkleLeaf[0]=ELFHash(L1);
    merkleLeaf[1]=ELFHash(L2);
    merkleLeaf[2]=ELFHash(L3);
    merkleLeaf[3]=ELFHash(L4);
    
    merkleBranch[0]= ELFHash(to_string(merkleLeaf[0])+to_string(merkleLeaf[1]));
    merkleBranch[1]= ELFHash(to_string(merkleLeaf[2])+to_string(merkleLeaf[3]));
    
    merkleRoot = ELFHash(to_string(merkleBranch[0])+to_string(merkleBranch[1]));
    
    cout << L1 << endl << endl
            << L2 << endl << endl
            << L3 << endl << endl
            << L4 << endl << endl;
    
    
    check(merkleRoot,merkleBranch,merkleLeaf,L1);
    check(merkleRoot,merkleBranch,merkleLeaf,L1_modified);

    return 0;
}
void check(unsigned int mRoot, unsigned int* mB, unsigned int* mL, string key) {
    cout << "Does:\n\n" << key << endl << endl << "exist in the tree?" << endl;

    if(mRoot == ELFHash(to_string(mB[0])+to_string(ELFHash(to_string(ELFHash(key))+to_string(mL[3]))))) {
        cout << "The string exist in the tree!" << endl;
        cout << "1-0" << endl << endl;
    }
    else if(mRoot == ELFHash(to_string(mB[0])+to_string(ELFHash(to_string(mL[2])+to_string(ELFHash(key)))))) {
        cout << "The string exist in the tree!" << endl;
        cout << "1-1" << endl << endl;
    }
    else if(mRoot == ELFHash(to_string(ELFHash(to_string(ELFHash(key))+to_string(mL[1])))+to_string(mB[1]))) {
        cout << "The string exist in the tree!" << endl;
        cout << "0-0" << endl << endl;
    }
    else if(mRoot == ELFHash(to_string(ELFHash(to_string(mL[0])+to_string(ELFHash(key))))+to_string(mB[1]))) {
        cout << "The string exist in the tree!" << endl;
        cout << "0-1" << endl << endl;
    }
    else {
        cout << "The string doesn't exist in the tree!" << endl << endl;
    }
            
}