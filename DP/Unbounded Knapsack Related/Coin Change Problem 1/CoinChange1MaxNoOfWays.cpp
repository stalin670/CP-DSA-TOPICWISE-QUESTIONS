/**
 * @file CoinChange1MaxNoOfWays.cpp
 * @date 2022-05-05
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a value N, if we want to make change for N cents, and we have infinite 
    supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we 
    make the change? The order of coins doesn’t matter.

    For example, 
    For N = 4 and S = {1,2,3}, there are four solutions: 
    {1,1,1,1},{1,1,2},{2,2},{1,3}. 
    So output should be 4. 

    For N = 10 and S = {2, 5, 3, 6}, there are five solutions: 
    {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
    So the output should be 5.

    Problem link -> https://practice.geeksforgeeks.org/problems/coin-change2448/1

*/

#include<bits/stdc++.h>
using namespace std;

// Coin change func starts here
int CoinChange1(int arr[],int sum,int n){
    int dp[n+1][sum+1];
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
               
                dp[i][j]= dp[i-1][j] + dp[i][j-arr[i-1]];
            }
            

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

    cout<<CoinChange1(coins,sum,n);

    return 0;
}

// I've provided test case above
// You can dry run with other cases

/*
    Approach:
    See, here each coin of a given denomination can come an infinite number of 
    times. (Repetition allowed), this is what we call UNBOUNDED KNAPSACK. We have 
    2 choices for a coin of a particular denomination, either i) to include, or ii) 
    to exclude.  But here, the inclusion process is not for just once; we can include
    any denomination any number of times until N<0.

    Basically, If we are at s[m-1], we can take as many instances of that coin 
    ( unbounded inclusion ) i.e count(S, m, n – S[m-1] ) ; then we move to s[m-2]. 
    After moving to s[m-2], we can’t move back and can’t make choices for s[m-1] 
    i.e count(S, m-1, n ).

    Finally, as we have to find the total number of ways, so we will add 
    these 2 possible choices, i.e count(S, m, n – S[m-1] ) + count(S, m-1, n ) ; 
    which will be our required answer.
*/
