/**
 * @file PermutationWithCaseChange.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Here you have given a string s and you have to output all permutation
    that can be generated with change the case of that character means if 
    the char in small case then take both the possible case to generate
    two string, in one string the case of that char in small and in 
    another it will be capital letter.

    Example 1:
    Input:
    "ab"

    Output:
    "ab"
    "aB"
    "Ab"
    "AB"
    
    Example 2:
    Input: 
    "abc"

    Output:
    "abc"
    "abc"
    "abC"
    "aBc"
    "aBC"
    "Abc"
    "AbC"
    "ABc"
    "ABC"

*/


#include<bits/stdc++.h>
using namespace std;

// Here Permutation func begins
void PermutationWithCaseChange(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return ;
    }

    string out1=output;
    string out2=output;
    out1.push_back(input[0]);
    out2.push_back(toupper(input[0]));
    input.erase(input.begin()+0);
    PermutationWithCaseChange(input,out1);
    PermutationWithCaseChange(input,out2);

    return;
}

// Main func starts here
int main(){
    string s; cin>>s;
    string t="";


    PermutationWithCaseChange(s,t);

    return 0;
}

// You can input any string that you want to output.
// so check it out , go through the code.
