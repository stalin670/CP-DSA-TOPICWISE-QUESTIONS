
/**
 * @file McmFormat.cpp
 * @date 2022-05-08
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
    We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words, no matter how we parenthesize the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have: 
    (ABC)D = (AB)(CD) = A(BCD) = ....

    Example:
    Input: p[] = {40, 20, 30, 10, 30}   
    Output: 26000  
    There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
    Let the input 4 matrices be A, B, C and D.  The minimum number of 
    multiplications are obtained by putting parenthesis in following way
    (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

    Input: p[] = {10, 20, 30, 40, 30} 
    Output: 30000 
    There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
    Let the input 4 matrices be A, B, C and D.  The minimum number of 
    multiplications are obtained by putting parenthesis in following way
    ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

    Input: p[] = {10, 20, 30}  
    Output: 6000  
    There are only two matrices of dimensions 10x20 and 20x30. So there 
    is only one way to multiply the matrices, cost of which is 10*20*30

*/


#include<bits/stdc++.h>
using namespace std;

// MCM recursive function
int mcmRecursive(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }

    int ans=INT_MAX;

    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate count of multiplications for
    // each parenthesis placement and return the
    // minimum count
    for(int k=i;k<=j-1;k++){
        int temp=mcmRecursive(arr,i,k)+mcmRecursive(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);

        ans=min(ans,temp);
    }

    return ans;

}

// Main function starts here
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=1,j=n-1;

    cout<<mcmRecursive(arr,i,j);

}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
