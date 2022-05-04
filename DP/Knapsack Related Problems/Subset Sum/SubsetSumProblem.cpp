/**
 * @file SubsetSumProblem.cpp
 * @date 2022-05-04 
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a set of non-negative integers, and a value sum, determine if there 
    is a subset of the given set with sum equal to given sum. 
    And return true if exist otherwise false.

    Example 1:
    Input:
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;

    Output:
    1(True)

*/

/*
    Approach:
    In this method, we also follow the recursive approach but In 
    this method, we use another 2-D matrix in  we first initialize with 
    -1 or any negative value.
    In this method, we avoid the few of the recursive call which 
    is repeated itself that’s why we use 2-D matrix. In this matrix 
    we store the value of the previous call value.

*/


#include<bits/stdc++.h>
using namespace std;

// Initialize dp with n+1,sum+1
static int dp[6][9];

// SubsetSum func
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


// Main func starts here
int main(){
    int n=5;
    int arr[n]={1,3,5,8,12};
    int sum=8;

    memset(dp,-1,sizeof(dp));

    cout<<SubsetSum(arr,sum,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
