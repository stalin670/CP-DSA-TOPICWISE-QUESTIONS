/**
 * @file RodCuttingProblem.cpp
 * @date 2022-05-05
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a rod of length N inches and an array of prices, price[] that contains
    prices of all pieces of size smaller than N. Determine the maximum value 
    obtainable by cutting up the rod and selling the pieces. 
    You can pick more than one instance of the same item, but not fractional.
    So you have to calculate max profit.
    This problem is based on DP.

    For example, if the length of the rod is 8 and the values of different pieces 
    are given as the following, then the maximum obtainable value is 22 
    (by cutting in two pieces of lengths 2 and 6) 

    Example 1:
    Input:
    N = 8
    Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
    Output:
    22
    Explanation:
    The maximum obtainable value is 22 by
    cutting in two pieces of lengths 2 and 
    6, i.e., 5+17=22.

    Example 2:

    Input:
    N=8
    Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
    Output: 24
    Explanation: 
    The maximum obtainable value is 
    24 by cutting the rod into 8 pieces 
    of length 1, i.e, 8*3=24. 

*/

/*
    Approach:
    Again we use the dynamic programming approach with even more 
    optimized space complexity.
    This method called Top Down Approach

    Question practice link -> https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
*/

#include<bits/stdc++.h>
using namespace std;

// Initialize dp with (n+1)(n+1)
static int dp[9][9];

// Top down approach 
int UnboundedKnapsack(int length[],int prices[],int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(length[i-1]<=j){
                dp[i][j] = max(prices[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }

        }
    }

    return dp[n][n];
    
}

// Main func starts here
int main(){
    // set the prices arr by itself or you can change to take input from user.
    int n=8;
    int prices[n]={3, 5, 8, 9, 10, 17, 17, 20};
    int length[n];
    for(int i=1;i<=n;i++){
        length[i-1]=i;
    }

    memset(dp,-1,sizeof(dp));

    cout<<UnboundedKnapsack(length,prices,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// This method is pure DP

