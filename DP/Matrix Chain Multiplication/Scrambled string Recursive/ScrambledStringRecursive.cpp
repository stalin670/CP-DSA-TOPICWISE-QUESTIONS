
/**
 * @file ScrambledStringRecursive.cpp
 * @date 2022-05-12
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement: ( Recursive )
    Given two strings S1 and S2 of equal length, the task is to determine if S2 is a scrambled form of S1.
    Scrambled string: 
    Given string str, we can represent it as a binary tree by partitioning it into two non-empty substrings recursively.

    link -> https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/

    Examples:
    Input: S1=”coder”, S2=”ocder” 
    Output: Yes 
    Explanation: 
    “ocder” is a scrambled form of “coder”

    Input: S1=”abcde”, S2=”caebd” 
    Output: No 
    Explanation: 
    “caebd” is not a scrambled form of “abcde”
        
    
    Problem Level -> Hard

*/

#include <bits/stdc++.h>
using namespace std;

// Scrambled string (Recursive) function
bool isScrambled(string a,string b)
{
    if (a.length() != b.length()) {
        return false;
    }
 
    int n = a.length();
 
    // Empty strings are scramble strings
    if (n == 0) {
        return true;
    }
 
    // Equal strings are scramble strings
    if (a == b) {
        return true;
    }

    string s1 = a, s2 = b;
 
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
 
    if (s1 != s2) {
        return false;
    }

    for (int i = 1; i < n; i++) {
        if (isScrambled(a.substr(0, i), b.substr(0, i))
            && isScrambled(a.substr(i, n - i),
                          b.substr(i, n - i))) {
            return true;
        }
 
        if (isScrambled(a.substr(0, i),
                       b.substr(n - i, i))
            && isScrambled(a.substr(i, n - i),
                          b.substr(0, n - i))) {
            return true;
        }
    }
 
    return false;

}

// Main function starts here
int main()
{
    string s1,s2; cin>>s1>>s2;

    if(isScrambled(s1,s2)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;

}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/
