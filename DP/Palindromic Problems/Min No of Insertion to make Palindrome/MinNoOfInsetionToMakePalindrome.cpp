
/**
 * @file MinNoOfInsetionToMakePalindrome.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022
**/     

/*
    Problem statement:
    Given string str, the task is to find the minimum number of 
    characters to be inserted to convert it to a palindrome.
    
    Example:
    ab: Number of insertions required is 1 i.e. bab
    aa: Number of insertions required is 0 i.e. aa
    abcd: Number of insertions required is 3 i.e. dcbabcd
    abcda: Number of insertions required is 2 i.e. adcbcda which 
    is the same as the number of insertions in the substring bcd(Why?).
    abcde: Number of insertions required is 4 i.e. edcbabcde

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
    string s1; cin>>s1;
    int n=s1.size();
    string s2=s1;
    reverse(s2.begin(),s2.end());

    int MinInsertion=lcsTopDown(s1,s2,n,n);

    cout<<"Min no. of Insertion : "<<n-MinInsertion<<endl;


    return 0;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/
