/**
 * @file LetterCasePermutation.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
**/

/*
    Problem Statement:
    Here you have given a string s with chars and number like "ac1B3" and
    you have to generate all permutation with given string with changing
    the case of each char each time.
    But when you encounter with numbers , leave them as they are 
    just you need to change the case 
    small to capital, or vice-versa.

    Example 1:
    Input:
    "a1B"

    Output:
    "a1B"
    "a1b"
    "A1B"
    "A1b"


    Example 2:
    Input:
    "2AB"

    Output:
    "2AB"
    "2Ab"
    "2aB"
    "2ab"


*/


#include<bits/stdc++.h>
using namespace std;

// Letter case permutation func starts here
void LetterCasePermutation(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return ;
    }

    string out1=output;
    string out2=output; 

    while((input[0]-'a')>=-49 && (input[0]-'a')<=-40){
        out1.push_back(input[0]);
        out2.push_back(input[0]);
        input.erase(input.begin()+0);
    }

    if((input[0]-'a')>=0 && (input[0]-'a')<=25){
        out1.push_back(input[0]);
        out2.push_back(toupper(input[0]));
    }
    else {
        out1.push_back(input[0]);
        out2.push_back(tolower(input[0]));
    }

    input.erase(input.begin()+0);
    LetterCasePermutation(input,out1);
    LetterCasePermutation(input,out2);

    return;
}

// Main func starts here
int main(){
    string s; cin>>s;
    string t="";


    LetterCasePermutation(s,t);

    return 0;
}

// You can input any string that you want to output.
// so check it out , go through the code.
