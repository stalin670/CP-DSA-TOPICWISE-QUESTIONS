
/**
 * @file PrintLongestCommonSubsequence.cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given two sequences, print the longest subsequence present in both of them. 

    Examples: 
    LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/

#include<bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// PrintLcs function starts here
string PrintLongestSubsequences(string s,string t,int n,int m){
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
    
    string result;
    
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            result+=s[i-1];
            i--;
            j--;
        }

        else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }

    reverse(result.begin(),result.end());
    

    return result;
}

// Main function starts here
int main(){
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<PrintLongestSubsequences(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
