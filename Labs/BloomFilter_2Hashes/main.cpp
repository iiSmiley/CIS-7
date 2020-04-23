/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on April 22, 2020, 4:32 PM
 * 
 * Purpose: 
 * 
 */

//User Libraries
#include "BloomFilter.h"

//Global Constants
const int N = 15;       //Length of BitVector
const int M = 4;        //Number of elements to add to the list
const int K = 2;        //Number of of hashes to be used
const string NAMES[] = {"Mark", "Omar", "The Weird Dude", "Karmin"};
//Execution Starts Here

int main(int argc, char** argv) {

    //Set Random Number Seed Here
    srand(time(0));
    

    //Initialize Variables
    BloomFilter a(N,K);
    string* key= new string[M];
    int lookUp = rand()%4;
    
    //Generate and push keys
    for(int i = 0; i < M; i++) {
        key[i] = to_string(rand()%10000);
        a.pushItem(key[i]);
    }

    //Display the outputs
    a.print_BitVector();
    a.print_elementList();
    
    cout << endl;
    
    cout << "Is " << key[lookUp] << " in the list?" << endl;
    (a.itemLookUp(key[lookUp]))? cout << "maybe!" << endl << endl : cout << "Noop!" << endl << endl;
    
    cout << "Is " << NAMES[lookUp] << " in the list?" << endl;
    (a.itemLookUp(NAMES[lookUp]))? cout << "maybe!" << endl << endl : cout << "Noop!" << endl << endl;
    cout << "Probability of a false positive: "
            << setprecision(2) << a.falsePositiveRate()*100 << "%" << endl;

    //Clean up - File closing, memory deallocation, etc....
    delete[] key;
    key = NULL;

    //Exit Stage Right!

    return 0;
}
