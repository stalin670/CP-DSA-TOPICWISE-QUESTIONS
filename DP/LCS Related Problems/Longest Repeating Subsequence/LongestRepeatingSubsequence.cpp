
/**
 * @file LongestRepeatingSubsequence.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Given a string, print the longest repeating subsequence such that 
    the two subsequence don’t have same string character at same position, i.e., 
    any i’th character in the two subsequences shouldn’t have the 
    same index in the original string.

    Examples: 

    Input: str = "aabb"
    Output: "ab"

    Input: str = "aab"
    Output: "a"
    The two subsequence are 'a'(first) and 'a' 
    (second). Note that 'b' cannot be considered 
    as part of subsequence as it would be at same
    index in both.

*/

#include<bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Longest Repeating subsequence function starts here
int LongestRepeatingSubsequence(string s,string t,int n,int m){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1] && i!=j){
                dp[i][j]= 1+dp[i-1][j-1];
            }

            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m];
}

// Main function starts here
int main(){
    string s1,s2; cin>>s1;
    int n=s1.size();
    s2=s1;

    cout<<LongestRepeatingSubsequence(s1,s2,n,n);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
// Link -> https://www.geeksforgeeks.org/longest-repeated-subsequence/
