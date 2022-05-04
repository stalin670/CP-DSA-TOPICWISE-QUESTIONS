/**
 * @file EqualSumPartition.cpp
 * @date 2022-05-04 
 * @copyright Copyright (c) 2022 
**/

/*
    Problem Description:
    Given an array arr[] of size N, check if it can be partitioned into two 
    parts such that the sum of elements in both parts is the same.

    Example 1:
    Input: N = 4
    arr = {1, 5, 11, 5}
    Output: YES
    Explaination: 
    The two parts are {1, 5, 5} and {11}.

    Example 2:
    Input: N = 3
    arr = {1, 3, 5}
    Output: NO
    Explaination: This array can never be 
    partitioned into two such parts.

*/

// This is problem almost same as subset sum problem

#include<bits/stdc++.h>
using namespace std;

static int dp[6][12];

// Subset sum func
bool SubsetSum(int arr[],int sum,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if (arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            if(arr[i-1]<=j){
               
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            

        }
    }

    return dp[n][sum];
    
}

// Equal partition function
bool EqualSumPartition(int arr[],int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }   

    if(totalSum&1){
        return false;
    }

    return SubsetSum(arr,totalSum/2,n);
}

// Main function starts here
int main(){
    int n=5;
    int arr[n]={1,5,11,5,6};

    memset(dp,-1,sizeof(dp));

    cout<<EqualSumPartition(arr,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// Question link -> https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
