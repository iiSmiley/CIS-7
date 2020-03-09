/* 
 * File:   main.cpp
 * 
 * Author: Omar Alkendi
 *
 * Created on March 9, 2020, 1:12 AM
 * 
 * Purpose: 
 * 
 */

//System Level Libraries
#include <cstdlib>      //C Standard Library
#include <iostream>     //I/O Library
using namespace std; //Library Scope

//Global Constants
const bool p[] = {true, true, false, false};
const bool q[] = {true, false, true, false};

int main() {

    //Display the outputs
    cout<<"p q ~p ~q p&&q p||q p^q p^q^q p^q^p !(p&&q) !p||!q !(p||q) !p^!q"<<endl;
    for(int i=0; i < 4; i++) {
        if(p[i]){
            cout << "T ";
        }
        else {
            cout << "F ";
        }
        
        if(q[i]){
            cout << "T  ";
        }
        else {
            cout << "F  ";
        }
        
        if(!p[i]){
            cout << "T  ";
        }
        else {
            cout << "F  ";
        }
        
        if(!q[i]){
            cout << "T   ";
        }
        else {
            cout << "F   ";
        }
        
        if(p[i] && q[i]){
            cout << "T   ";
        }
        else {
            cout << "F   ";
        }
        
        if(p[i] || q[i]){
            cout << "T   ";
        }
        else {
            cout << "F   ";
        }
        
        if(p[i] ^ q[i]){
            cout << "T    ";
        }
        else {
            cout << "F    ";
        }
        
        if(p[i] ^ q[i] ^ q[i]){
            cout << "T     ";
        }
        else {
            cout << "F     ";
        }
        
        if(p[i] ^ q[i] ^ p[i]){
            cout << "T      ";
        }
        else {
            cout << "F      ";
        }
        
        if(!(p[i] && q[i])){
            cout << "T       ";
        }
        else {
            cout << "F       ";
        }
        
        if(!p[i] || !q[i]){
            cout << "T       ";
        }
        else {
            cout << "F       ";
        }
        
        if(!(p[i] || q[i])){
            cout << "T       ";
        }
        else {
            cout << "F       ";
        }
        
        if(!p[i] ^ !q[i]){
            cout << "T       ";
        }
        else {
            cout << "F       ";
        }
        
        cout << endl;
        
    }




    //Exit Stage Right!

    return 0;
}
