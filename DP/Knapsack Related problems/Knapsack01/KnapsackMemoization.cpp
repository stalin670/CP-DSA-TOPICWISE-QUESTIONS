/**
 * @file KnapsackMemoization.cpp
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
    We can solve this problem by simply creating a 2-D array that can store a 
    particular state (n, w) if we get it the first time. Now if we come across 
    the same state (n, w) again instead of calculating it in exponential 
    complexity we can directly return its result stored in the table in 
    constant time. This method gives an edge over the recursive approach 
    in this aspect.

*/


#include<bits/stdc++.h>
using namespace std;

static int dp[5][8];

// Knapsack function
int knapsackMamoization(int wt[],int val[],int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+knapsackMamoization(wt,val,w-wt[n-1],n-1),knapsackMamoization(wt,val,w,n-1));
    }
    else return dp[n][w]=knapsackMamoization(wt,val,w,n-1);
}

// Main func starts here
int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;

    memset(dp,-1,sizeof(dp));

    cout<<knapsackMamoization(wt,val,w,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// This method is not pure DP
// This is something, Recursive + Memoization
