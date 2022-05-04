/**
 * @file Min-SubsetSum-Diff.cpp
 * @date 2022-05-04
 * @copyright Copyright (c) 2022 
**/

/*
    Problem Statement:
    Given a set of integers, the task is to divide it into two sets S1 and S2 
    such that the absolute difference between their sums is minimum. 
    If there is a set S with n elements, then if we assume Subset1 has m elements, 
    Subset2 must have n-m elements and the value of 
    abs(sum(Subset1) – sum(Subset2)) should be minimum.

    Example: 
    Input:  arr[] = {1, 6, 11, 5} 
    Output: 1
    Explanation:
    Subset1 = {1, 5, 6}, sum of Subset1 = 12 
    Subset2 = {11}, sum of Subset2 = 11        


    Problem link -> https://practice.geeksforgeeks.org/problems/sum-of-subset-differences/1
*/

/*
    Approach :
    The problem can be solved using dynamic programming when the sum of the elements 
    is not too big. We can create a 2D array dp[n+1][sum+1] where n is the 
    number of elements in a given set and sum is the sum of all elements. 
    We can construct the solution in a bottom-up manner.
*/

#include<bits/stdc++.h>
using namespace std;

// Min Subset sum diff function
int minSubsetSumDiff(int arr[],int range,int n){
    int dp[n+1][range+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<range+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<range+1;j++){
            if (arr[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            if(arr[i-1]<=j){
               
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    int diff=INT_MAX;

    for(int i=0;i<range+1;i++){
        if(dp[n][i]){
            diff=min(diff,abs(range-2*i));
        }
    }

    return diff;
}

// Main Function starts here
int main(){
    int n; cin>>n;
    int arr[n];
    int range=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        range+=arr[i];
    }

    // From abs(S1-S2) there is two variable
    // we've changes upto single variable
    // abs(range-2*S1)

    int minDiff=minSubsetSumDiff(arr,range,n);

    cout<<minDiff<<endl;


    return 0;
}

// I've provided test case above
// You can dry run with other cases
