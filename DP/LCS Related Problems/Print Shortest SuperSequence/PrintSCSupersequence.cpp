
/**
 * @file PrintSCSupersequence.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Given two strings X and Y, print the shortest string that has both 
    X and Y as subsequences. If multiple shortest super-sequence 
    exists, print any one of them. 

    Examples: 

    Input: X = "AGGTAB",  Y = "GXTXAYB"
    Output: "AGXGTXAYB" OR "AGGXTXAYB" 
    OR Any string that represents shortest
    supersequence of X and Y

    Input: X = "HELLO",  Y = "GEEK"
    Output: "GEHEKLLO" OR "GHEEKLLO"
    OR Any string that represents shortest 
    supersequence of X and Y

*/

#include<bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Print Scs function starts here
string PrintShortestSuperSubsequences(string s,string t,int n,int m){
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
                result.push_back(s[i-1]);
                i--;
            }
            else {
                result.push_back(t[j-1]);
                j--;
            }
        }
    }

    while(i>0){
        result.push_back(s[i-1]);
        i--;
    }

    while(j>0){
        result.push_back(t[j-1]);
        j--;
    }

    reverse(result.begin(),result.end());
    

    return result;
}

// Main function starts here
int main(){
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<PrintShortestSuperSubsequences(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
// Link -> https://www.geeksforgeeks.org/print-shortest-common-supersequence/
