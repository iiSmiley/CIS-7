/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BloomFilter.cpp
 * Author: User 1
 * 
 * Created on April 22, 2020, 4:33 PM
 */

#include "BloomFilter.h"

BloomFilter::BloomFilter() {
    this->n = 0;
    this->m = 0;
    this->k = 2;
    this->bitVector = new bool[this->n];
    this->elementsList = new string[this->m];
}

BloomFilter::BloomFilter(int n, int k) {
    this->n = n;
    this->m = 0;
    this->k = k;
    this->bitVector = new bool[this->n];
    this->elementsList = new string[this->m];
}

BloomFilter::BloomFilter(const BloomFilter& orig) {
    this->n = orig.n;
    this->m = orig.m;
    this->k = orig.k;
    this->bitVector = new bool[this->n];
    this->elementsList = new string[this->m];
    
    for(int i = 0; i < this->n; i++) {
        this->bitVector[i] = orig.bitVector[i];
    }
    
    for(int i = 0; i < this->m; i++) {
        this->elementsList[i] = orig.elementsList[i];
    }
}

BloomFilter::~BloomFilter() {
    //delete dynamically allocated arrays
    delete[] this->bitVector ;
    delete[] this->elementsList;
    
    //deallocate the memory
    this->bitVector = NULL;
    this->elementsList= NULL;
}

void BloomFilter::pushItem(string key) {
    //increment the size of elementList
    this->m++;
    
    //Create a temporary array with the new size, copy everything, then add the new element
    string* temp = new string[this->m];
    for(int i = 0; i < this-> m-1; i++) {
        temp[i] = this->elementsList[i];
    }
    temp[this->m-1] = key;
    
    //Clean and prepare the elementList 
    delete[] this->elementsList;
    this->elementsList = NULL;
    this->elementsList = new string[this->m];
    
    //Populate elementList
    for(int i = 0; i < this-> m; i++) {
        this->elementsList[i] = temp[i];
    }
    
    //Delete and deallocate the temporary array
    delete[] temp;
    temp = NULL;
    
    //Update the bitVector
    if(this->k == 2) {
        this->bitVector[(FNVHash(key)%this->n)] = true;
        this->bitVector[(ELFHash(key)%this->n)] = true;
    }
    else if(this->k == 9) {
        this->bitVector[(RSHash(key)%this->n)]   = true;
        this->bitVector[(JSHash(key)%this->n)]   = true;
        this->bitVector[(ELFHash(key)%this->n)]  = true;
        this->bitVector[(BKDRHash(key)%this->n)] = true;
        this->bitVector[(SDBMHash(key)%this->n)] = true;
        this->bitVector[(DJBHash(key)%this->n)]  = true;
        this->bitVector[(DEKHash(key)%this->n)]  = true;
        this->bitVector[(FNVHash(key)%this->n)]  = true;
        this->bitVector[(BPHash(key)%this->n)]   = true;
        this->bitVector[(APHash(key)%this->n)]   = true;
    }
    else {
        cout << "ERROR! Couldn't push the item!" << endl;
    }
}

void BloomFilter::print_BitVector(){
    cout << "BitVictor:" << endl;
    cout << "|";
    for(int i = 0; i < this->n; i++) {
        cout << setw(2) << left <<  i << "|";
    }
    cout << endl;
    
    cout << "|";
    for(int i = 0; i < this->n; i++) {
        cout << setw(2) << left << this->bitVector[i] << "|";
    }
    cout << endl;
}

void BloomFilter::print_elementList() {
    cout << "Elements in the list:" << endl;
    for(int i = 0; i < this->m; i++) {
        cout << this->elementsList[i]<< ", ";
        if(i%6 == 5) {
            cout << endl;
        }
    }
    cout << endl;
}

bool BloomFilter::itemLookUp(string key) {
    //Update the bitVector
    if(this->k == 2) {
        if(this->bitVector[(FNVHash(key)%this->n)]
            && this->bitVector[(ELFHash(key)%this->n)] == true) {return true;}
        else return false;
    }
    else if(this->k == 9) {
        if(this->bitVector[(RSHash(key)%this->n)]
            && this->bitVector[(JSHash(key)%this->n)]   
            && this->bitVector[(ELFHash(key)%this->n)]  
            && this->bitVector[(BKDRHash(key)%this->n)] 
            && this->bitVector[(SDBMHash(key)%this->n)] 
            && this->bitVector[(DJBHash(key)%this->n)]  
            && this->bitVector[(DEKHash(key)%this->n)]  
            && this->bitVector[(FNVHash(key)%this->n)]  
            && this->bitVector[(BPHash(key)%this->n)]   
            && this->bitVector[(APHash(key)%this->n)] == true)  {return true;} 
        else return false;
    }
}

float BloomFilter::falsePositiveRate() {  
    float c = exp(-(this->k * this->m * 1.0)/(this->n*1.0));
    float rate = pow((1.0-c),this->k*1.0);
    return rate;
}

