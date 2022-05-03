/**
 * @file PermutationWithSpaces.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Here you have given a string s and you have to output all permutation
    that can be generated using '_' to be inserted in between the chars
    in all possible places.

    Example:
    Input: 
    "abc"
    Output:
    "a_b_c"
    "a_bc"
    "ab_c"
    "abc"

    You can't inserted space at first and last position.

*/

#include<bits/stdc++.h>
using namespace std;

// Here Permutation func begins
void PermutationSpaces(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }

    string out1=output;
    string out2=output;

    out1.push_back('_');
    out1.push_back(input[0]);
    out2.push_back(input[0]);
    input.erase(input.begin()+0);

    PermutationSpaces(input,out1);
    PermutationSpaces(input,out2);

    return;
}

// Main func starts here.
int main(){
    string s; cin>>s;
    string t="";
    t.push_back(s[0]);
    s.erase(s.begin()+0);

    PermutationSpaces(s,t);

    return 0;
}


// You can input any string that you want to output.
// so check it out , go through the code.
