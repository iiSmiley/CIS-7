/*
 *  Dr. Mark E. Lehr
 *  CSC 7 Template for Mastermind AI
 *  December 1st, 2019
 * 
 *  Omar Alkendi
 *  Final Project: Mastermind AI Using Knuth Five-Guess Algorithm
 *  June 7th, 2020
 */

//System Libraries

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <map>          //Needed to simplify the application of the minimax technique
#include <vector>       //Simplifies the process of finding a next guess (can't push to arrays in C++)
#include <algorithm>    //To use the "find" algorithm
using namespace std;
//Function Prototypes

string AI(char,char);
bool eval(string,string,char &,char &);
string set();

int main(int argc, char** argv) {

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess, temp;         //number of guesses
    
    //Initialize Values
    nGuess=temp=0;
    code=set();
    rr=rw=0;  

    //Loop until solved and count to find solution
    
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw));
    
    cout << code << endl;
    
    //Check evaluation
    cout<<nGuess<<" "<<code<<" "<<guess<<endl;
    //guess=AI(rr,rw);

    /*cout<<code<<endl;

    for(int i=0;i<10000;i++){

        guess=AI(0,0);

        eval(code,guess,rr,rw);

        cout<<setw(5)<<code<<setw(5)<<guess

                <<setw(2)<<static_cast<int>(rr)

                <<setw(2)<<static_cast<int>(rw)<<endl;

    }*/
    //Exit the program

    return 0;
}

string AI(char rr,char rw){
   
    //Helper functions
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
    
    //Saves few lines
    void (*removeGuess) (vector<int> &, int) = 
    [] (vector<int> &set, int guess) {
        int index;
        for(auto it = set.begin(); it != set.end(); it++){
            index = distance(set.begin(), it);
            if(set[index] == guess) {
                set.erase(set.begin()+index);
                break;
            }
        }
    };
    
    string sGuess = "0011";
    static int attempt = 0;         //Holds the number of attempts done by the AI
    const int SIZE = 10000;         //Size of all possible guesses
    static vector<int> allGuesses;  //A vector of all possible combinations
    static vector<int> possibleGuesses; //A vector of the surviving guesses
    static vector<int> nextGuesses;     //Saves guesses with minimax score
    static vector<int> returnedGuesses; //Saves returned guesses by the AI
    map<string,int> possScoreCount;     //See line 131
    map<int,int> possScore;             //See line 135
    int min, max;                       //Used for minimax technique

    /*
     * possScoreCount is used to count the number of times a second gen 
     * possibility can be eliminated from each possible guess
     */ 
    /*
     * possScore is used to record the score of each possible guess 
     */
    
    
    /*
     * If this is the first attempt, populate the allGuesses vector and
     * the possibleGuesses vector, return the initial guess, and remove the
     * used guess from the two sets.
     */
    if(attempt == 0) {
        //sizeOfNextGen= SIZE;
        //nextGenGuesses[sizeOfNextGen];
        for(int i=0; i<SIZE; i++){
            allGuesses.push_back(i);
            possibleGuesses.push_back(i);
        }
        returnedGuesses.push_back(11);
        attempt++;
        //cout << "Hell for AI. Attempt: " << attempt << endl;
        removeGuess(allGuesses, 11);
        removeGuess(possibleGuesses, 11);
        cout << "Guess: " << sGuess << endl;
        return sGuess;
    }
    
    /*
     * If this is not the first attempt, eliminate wrong guesses, find the size
     * of the next gen and return a guess from the surviving
     */
    
    if(attempt > 0) {
        //Start the elimination process 
        /* 
         * Eliminate guesses that would yield similar result to the 
         * previous guess using the eval function
         */
        int index;
        char tempRR, tempRW;
        tempRR = tempRW = 0;
        
        
        
        vector<int>::iterator it = possibleGuesses.begin();
        while (it != possibleGuesses.end()) {
            index = distance(possibleGuesses.begin(), it);
            eval(stringify(returnedGuesses[attempt-1]), 
                stringify(possibleGuesses[index]),tempRR, tempRW);
            if(response(rr,rw) != response(tempRR,tempRW)){ 
                it = possibleGuesses.erase(possibleGuesses.begin()+index);
                //cout << "Erasing!" << endl;
            } else {
                it++;
            }
        }
    
        //The beginning of the minimax calculations
        for(int i=0; i<allGuesses.size(); i++) {
            for(int j=0; j < possibleGuesses.size();j++) {
                tempRR = tempRW = 0;
                eval(stringify(allGuesses[i]),stringify(possibleGuesses[j]),tempRR, tempRW);
                string score = response(tempRR,tempRW);
                if(possScoreCount.count(score) > 0) {
                    //If score exists, then increment
                    possScoreCount.at(score)++;
                }
                else {
                    //If score does exist, then add to the map
                    possScoreCount.emplace(score,1);
                }
            }
            //Find the score for each guess in allGuesses
            max = 0;
            for(auto x:possScoreCount) {
                if(x.second > max ) {
                    max = x.second;
                }
            }
            possScore.emplace(allGuesses[i], max);
            possScoreCount.clear();
        }
        min = numeric_limits<int>::max(); //As big as it can be
        for(auto x:possScore) {
            if(x.second < min) {
                min = x.second;
            }
        }
        for(auto x:possScore) {
            if(x.second == min) {
                nextGuesses.push_back(x.first);
            }
        }
        //Now we can choose a guess, preferably from the possibleGuesses.
        for(int i=0; i<nextGuesses.size(); i++) {
            if(find(possibleGuesses.begin(), possibleGuesses.end(),
                    nextGuesses[i]) != possibleGuesses.end()) {
                attempt++;
                returnedGuesses.push_back(nextGuesses[i]);
                cout << "Guess: " << stringify(nextGuesses[i]) << endl;
                return stringify(nextGuesses[i]);
            }
        }
        for(int i=0; i<nextGuesses.size(); i++) {
            if(find(allGuesses.begin(), allGuesses.end(),
                    nextGuesses[i]) != allGuesses.end()) {
                attempt++;
                returnedGuesses.push_back(nextGuesses[i]);
                cout << "Guess: " << stringify(nextGuesses[i]) << endl;
                return stringify(nextGuesses[i]);
            }
        }
    }     
}

bool eval(string code,string guess,char &rr,char &rw){

    string check="    ";
    rr=0,rw=0;

    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }

    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){

    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}