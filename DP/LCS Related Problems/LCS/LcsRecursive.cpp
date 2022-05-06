/**
 * @file LcsRecursive.cpp
 * @date 2022-05-06 
 * @copyright Copyright (c) 2022 
**/

/*                            A Recursive implementation of LCS problem                                  */

/*
    Problem statement:
    Given two sequences, find the length of longest subsequence present in both of 
    them. A subsequence is a sequence that appears in the same relative order, 
    but not necessarily contiguous. 
    For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are 
    subsequences of “abcdefg”. 

    Examples: 
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4. 
*/


#include<bits/stdc++.h>
using namespace std;

// Lcs Recursive approach
int lcsRecursive(string s,string t,int n,int m){
    if(n==0 || m==0){
        return 0;
    }

    if(s[n-1]==t[m-1]){
        return 1+lcsRecursive(s,t,n-1,m-1);
    }
    
    return max(lcsRecursive(s,t,n-1,m),lcsRecursive(s,t,n,m-1));
}

int main(){
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<lcsRecursive(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
