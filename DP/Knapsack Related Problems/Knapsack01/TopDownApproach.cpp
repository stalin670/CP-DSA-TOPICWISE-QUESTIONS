/**
 * @file TopDownApproach.cpp
 * @date 2022-05-04 
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    You have given two array of same length in with one for weight arr
    and other one is value array, and you have a kanpsack of weight 
    capacity 'W' so you have to put some items it this bag so that the
    profit is maximum and weight of items should be less than or equal to 
    given max wt. of bag.
    So you have to calculate max profit.
    This problem is based on DP.

    Example:
    Input:
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;

    Output:
    9

*/

/*
    Approach:
    Again we use the dynamic programming approach with even more 
    optimized space complexity.
    This method called Top Down Approach
*/

#include<bits/stdc++.h>
using namespace std;

static int dp[5][8];

// Top down approach 
int TopDownknapsack(int wt[],int val[],int w,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }

        }
    }

    return dp[n-1][w];
    
}

// Main func starts here
int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;

    memset(dp,-1,sizeof(dp));

    cout<<TopDownknapsack(wt,val,w,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// This method is pure DP

