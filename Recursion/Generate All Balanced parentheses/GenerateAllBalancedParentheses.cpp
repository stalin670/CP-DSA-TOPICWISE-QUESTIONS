/**
 * @file GenerateAllBalancedParentheses.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    You have given n , a integer and means you have two more integer
    open=n, closes=n and these are no. of open brackets and closes brackets
    and here you have to generate all balanced parentheses.

    Example 1:
    Input:
    2

    Output:
    ()()
    (())

    Example 2:
    Input :
    3

    Output:
    ((()))
    (()())
    (())()
    ()(())
    ()()()

*/


#include<bits/stdc++.h>
using namespace std;

// Balanced parentheses function
void AllBalancedParentheses(int open,int closes,string out,vector<string> &v){
    if(open==0 and closes==0){
        v.push_back(out);
        return ;
    }

    if(open!=0) {
        string out1=out;
        out1.push_back('(');
        AllBalancedParentheses(open-1,closes,out1,v);
    }

    if(closes>open){
        string out2=out;
        out2.push_back(')');
        AllBalancedParentheses(open,closes-1,out2,v);
    }
   

    return;
}

// Main func starts here
int main(){
    int n; cin>>n;
    int open=n,closes=n;
    string out="";

    vector<string> v;
    AllBalancedParentheses(open,closes,out,v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }

    return 0;
}

// You can input any string that you want to output.
// so check it out , go through the code.
// Think Recursively.
