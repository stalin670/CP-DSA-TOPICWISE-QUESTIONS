/**
 * @file LcsBottomUp.cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022
**/

/*                 A Bottom-up(Recursive + Memoize) DP implementation of lcs problem                  */

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

static int dp[10001][10001];

// Lcs Bottom up function starts here
int lcsBottomUp(string s,string t,int n,int m){
    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(s[n-1]==t[m-1]){
        return dp[n][m]= 1+lcsBottomUp(s,t,n-1,m-1);
    }
    
    return dp[n][m]=max(lcsBottomUp(s,t,n-1,m),lcsBottomUp(s,t,n,m-1));
}

// Main function starts here
int main(){
    memset(dp,-1,sizeof(dp));
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<lcsBottomUp(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
