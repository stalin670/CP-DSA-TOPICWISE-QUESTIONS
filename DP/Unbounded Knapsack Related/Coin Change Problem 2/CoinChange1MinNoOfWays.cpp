
/**
 * @file CoinChange2MinNoOfCoins.cpp
 * @date 2022-05-06
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a value V, if we want to make a change for V cents, and we have 
    an infinite supply of each of C = { C1, C2, .., Cm} valued coins, what 
    is the minimum number of coins to make the change? If it’s not possible 
    to make a change, print -1.

    Examples:  
    Input: coins[] = {25, 10, 5}, V = 30
    Output: Minimum 2 coins required
    We can use one coin of 25 cents and one of 5 cents 

    Input: coins[] = {9, 6, 5, 1}, V = 11
    Output: Minimum 2 coins required
    We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include<bits/stdc++.h>
using namespace std;

// Coin change func starts here
// Min. no. of coins to get the desired sum
int CoinChange2(int coins[],int sum,int n){
    // Initiallize dp with [n+1][sum+1]
    int dp[n+1][sum+1];

    // This for loop is for initiallizing row i=0 and column=0 only
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0) dp[i][j]=0;
            if(i==0) dp[i][j]=INT_MAX-1;
        }
    }

    // This for loop is for initiallizing row i=1 only
    for(int i=1;i<2;i++){
        for(int j=1;j<sum+1;j++){
            if(j%coins[i]==0){
                dp[i][j]=j/coins[i];
            }
            else dp[i][j]=INT_MAX-1;
        }
    }

    // Top down approach
    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][sum];


}

// Main function starts here
int main(){
    int n; cin>>n;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    int sum; cin>>sum;

    cout<<CoinChange2(coins,sum,n);

    return 0;
}

// I've provided test case above
// You can dry run with other cases
