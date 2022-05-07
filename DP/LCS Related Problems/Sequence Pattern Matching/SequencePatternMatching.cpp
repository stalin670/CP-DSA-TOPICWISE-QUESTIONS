
/**
 * @file SequencePatternMatching.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given two sequences, You just have to check weather a given sequence
    is subsequence in other string or not ,
    Basically just return boolean value true or false.

    Example:

    Input:
    abc
    axybfc
    Ouput:
    true

    Input:
    axytlm
    axyhjtln
    Output:
    false

*/

#include<bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Matching function starts here
bool SequencePatternMatching(string s,string t,int n,int m){
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
    

    if(result==s) return true;
    return false;
}

// Main function starts here
int main(){
    string s1,s2; cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();

    cout<<SequencePatternMatching(s1,s2,n,m);


    return 0;
}

// I've provided test case above
// You can dry run with other cases
