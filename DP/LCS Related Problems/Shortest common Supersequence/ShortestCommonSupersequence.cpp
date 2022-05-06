
/**
 * @file ShortestCommonSupersequence.cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Given two strings str1 and str2, the task is to find the length of the 
    shortest string that has both str1 and str2 as subsequences.

    Examples : 

    Input:   str1 = "geek",  str2 = "eke"
    Output: 5
    Explanation: 
    String "geeke" has both string "geek" 
    and "eke" as subsequences.

    Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
    Output:  9
    Explanation: 
    String "AGXGTXAYB" has both string 
    "AGGTAB" and "GXTXAYB" as subsequences.

    Approach:
    Len(Sum of the two given string)-Len(Lis)

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

    cout<<m+n-lcsTopDown(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/shortest-common-supersequence/
