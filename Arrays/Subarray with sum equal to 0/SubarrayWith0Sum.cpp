/**
 * @file SubarrayWith0Sum.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    Given an array of positive and negative numbers. Find if there is a
    subarray (of size at-least one) with 0 sum.

    Your Task:
    You only need to complete the function subArrayExists() that takes array
    and n as parameters and returns true or false depending upon
    whether there is a subarray present with 0-sum or not. Printing
    will be taken care by the drivers code.

    Constraints:
    1 <= n <= 10^4
    -105 <= a[i] <= 10^5

*/

/*
    Example 1:
    Input:
    5
    4 2 -3 1 6
    Output:
    Yes
    Explanation:
    2, -3, 1 is the subarray
    with sum 0.

    Example 2:
    Input:
    5
    4 2 0 1 6
    Output:
    Yes
    Explanation:
    0 is one of the element
    in the array so there exist a
    subarray with sum 0.
*/

// Question link -> https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
// You can check it out, try it out now
// Go through the code
// Problem level -> Easy

#include <bits/stdc++.h>
using namespace std;

// Function to check whether there is a subarray present with 0-sum or not.
bool subArrayExists(int arr[], int n)
{
    int sum = 0;
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (st.find(sum) != st.end() || sum == 0)
        {
            return true;
        }
        st.insert(sum);
    }

    return false;
}

// Main funtion
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << subArrayExists(arr, n) << endl;

    return 0;
}

// I've provided the test cases above
// You can check.
