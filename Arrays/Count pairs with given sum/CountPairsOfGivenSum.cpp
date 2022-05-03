/**
 * @file CountPairsOfGivenSum.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    Given an array of N integers, and an integer K, find the number of pairs of
    elements in the array whose sum is equal to K.

    Your Task:
    You don't need to read input or print anything. Your task is to complete
    the function getPairsCount() which takes arr[], n and k as input
    parameters and returns the number of pairs that have sum K.

    Constraints:
    1 <= N <= 10^5
    1 <= K <= 10^8
    1 <= Arr[i] <= 10^6

*/

/*
    Example 1:
    Input:
    N = 4, K = 6
    arr[] = {1, 5, 7, 1}
    Output: 2
    Explanation:
    arr[0] + arr[1] = 1 + 5 = 6
    and arr[1] + arr[3] = 5 + 1 = 6.

    Example 2:
    Input:
    N = 4, K = 2
    arr[] = {1, 1, 1, 1}
    Output: 6
    Explanation:
    Each 1 will produce sum 2 with any 1.
*/

// Question link -> https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
// You can check it out, try it out now
// Go through the code
// Problem level -> Easy

#include <bits/stdc++.h>
using namespace std;

// Get pairs count Function
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int val = k - arr[i];
        if (m[val])
        {
            cnt += m[val];
        }
        m[arr[i]]++;
    }

    return cnt;
}

// Main funtion
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getPairsCount(arr, n, k) << endl;

    return 0;
}

// I've provided the test cases above
// You can check.
