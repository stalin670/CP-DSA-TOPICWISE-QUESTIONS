/**
 * @file MinJumpsToReachEndOFTheArray.cpp
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 **/

// Question link -> https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
// Question Level -> Medium

/**
 * Given an array of N integers arr[] where each element represents the max number of
 * steps that can be made   forward from that element. Find the minimum number
 * of jumps to reach the end of the array (starting from the first element).
 * If an element is 0, then you cannot move through that element.
 * Note: Return -1 if you can't reach the end of the array.
 **/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity -> O(N)
int MinJumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int maxReach = arr[0];
    int jump = 1;
    int step = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;

        maxReach = max(maxReach, i + arr[i]);
        step--;

        if (step == 0)
        {
            jump++;
            if (i >= maxReach)
            {
                return -1;
            }
            step = maxReach - i;
        }
    }

    return -1;
}

// Main Funtion
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << MinJumps(arr, n) << endl;

    return 0;
}

// Test cases to run
/**
 *  First test case
 * 	Input:
 * 	11
 *  {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
 *  Output:
 *  3
 *
 **/

/*
 * 	Second test case
 * 	Input:
 * 	6
 * 	{1, 4, 3, 2, 6, 7}
 * 	Output:
 * 	2
 *
 */
