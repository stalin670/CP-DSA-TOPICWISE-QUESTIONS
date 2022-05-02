

/**
 * @file K-th-Symbol-in-Grammar.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement-
    We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

    For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
    Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

    so for n=1 and k=1 the value is 0;

    for row 1 -> 0                 k=1    ->  2^(0) 
    for row 2 -> 0 1               k=2    ->  2^(1)
    for row 3 -> 0 1 1 0           k=4    ->  2^(2)
    for row 4 -> 0 1 1 0 1 0 0 1   k=8    ->  2^(3)

    observe that for every row It's first half is same as upper row
    and second half just a complement of upper row

    so we've solved this problem using recursion 

    problem level -> Medium

    Question link -> https://leetcode.com/problems/k-th-symbol-in-grammar/

*/

#include<bits/stdc++.h>
using namespace std;


int kthGrammar(int n,int k){
    if(n==1 and k==1){
        return 0;
    }

    int mid=pow(2,n-1)/2;

    if(k<=mid){
        return kthGrammar(n-1,k);
    }

    return !kthGrammar(n-1,k-mid);
}


// Main function starts here
int main(){
    int n,k; cin>>n>>k;
    
    cout<<kthGrammar(n,k);

    return 0;
}

// Test cases 

/*
    First test case
    Input: n = 1, k = 1
    Output: 0

*/

/*
    Second test case
    Input: n = 2, k = 2
    Output: 1

*/
