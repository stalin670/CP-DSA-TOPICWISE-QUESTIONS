
/**
 * @file Lcs(Substring).cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

    Examples : 

    Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
    Output : 5 
    Explanation:
    The longest common substring is “Geeks” and is of length 5.

    Input : X = “abcdxyz”, y = “xyzabcd” 
    Output : 4 
    Explanation:
    The longest common substring is “abcd” and is of length 4.

    Input : X = “zxabcdezy”, y = “yzabcdezx” 
    Output : 6 
    Explanation:
    The longest common substring is “abcdez” and is of length 6.

*/

#include<bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Lcs function starts here
int lcSubstring(string s,string t,int n,int m){
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
                dp[i][j]=0;
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

    cout<<lcSubstring(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases

/*
    Approach:
    The longest common suffix has following optimal substructure property. 
    If last characters match, then we reduce both lengths by 1 
    LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1] 
    If last characters do not match, then result is 0, i.e., 
    LCSuff(X, Y, m, n) = 0 if (X[m-1] != Y[n-1])
    Now we consider suffixes of different substrings ending at different indexes. 
    The maximum length Longest Common Suffix is the longest common substring. 
    LCSubStr(X, Y, m, n) = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m and 1 <= j <= n 

*/
