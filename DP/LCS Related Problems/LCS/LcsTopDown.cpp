
/**
 * @file LcsTopDown.cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022
 * 
**/
             
/*                            A Top-Down DP implementation of LCS problem                                  */

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
// Lcs function starts here
int lcsTopDown(string s,string t,int n,int m){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s[i-1]==t[j-1]){
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
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<lcsTopDown(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
