/**
 * @file CountSubsetSum.cpp
 * @date 2022-05-04
 * @copyright Copyright (c) 2022 
**/

/*  
    Problem statement:
    Count the total subsets of a given sum present in the array.
    Same Approach of subset sum problem. 

    Problem link -> https://leetcode.com/problems/target-sum/
*/

#include<bits/stdc++.h>
using namespace std;

static int dp[7][11];

// Subset sum function
int SubsetSum(int arr[],int sum,int n){
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
               
                dp[i][j]= dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            

        }
    }

    return dp[n][sum];
    
}

// Main function starts here
int main(){
    int n=6;
    int arr[n]={2,3,5,6,8,10};
    int sum=10;

    memset(dp,-1,sizeof(dp));

    cout<<SubsetSum(arr,sum,n)<<endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
