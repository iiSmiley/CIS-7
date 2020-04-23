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
const int N[]   = {12,13,14};
const int M     = 1;        //Number of elements to add to the list
const int K     = 9;        //Number of of hashes to be used
const int COMP_N= 3;        //Number of comparisons
const float RESULTS_TABLE[] = {0.00317, 0.00194, 0.00121};  //From pages.cs.wisc.edu/~cao/papers/summary-cache/node8.html



//Execution Starts Here

int main(int argc, char** argv) {

    //Set Random Number Seed Here
    srand(time(0));
    

    for(int i = 0; i < COMP_N; i++) {
        BloomFilter a(N[i],K);
        string* key= new string[M];
        for(int i = 0; i < M; i++) {
            key[i] = to_string(rand()%10000);
            a.pushItem(key[i]);
        }
        

        cout << "Probability of a false positive for n/m = " << N[i]/M << " and k = " << K <<endl
                << "From table: " << RESULTS_TABLE[i] << endl
                << "Calculated: " << setprecision(3) << a.falsePositiveRate() << endl;
        
        delete[] key;
        key = NULL;
    }
    cout << endl;

    //Exit Stage Right!
    

    return 0;
}
