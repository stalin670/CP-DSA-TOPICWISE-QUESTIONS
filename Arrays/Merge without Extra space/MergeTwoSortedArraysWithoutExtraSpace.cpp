
/**
 * @file MergeWithoutExtraSpace.cpp
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
 */

// Question link -> https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
// One of the good question
// Level -> Hard

/*
    Problem statement:
    You have given two sorted arrays and you have to do something without
    using any extra space so that after we print arr1 and then arr2
    we will get whole array to be sorted

    Main point -> You can't use any extra space.

*/

#include <bits/stdc++.h>
using namespace std;

// Best and Efficient way
void merge1(int arr1[], int arr2[], int n, int m)
{
    // code here
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            // swapping the largest element in arr1 to that element in arr2
            swap(arr2[j++], arr1[k--]);
        }
    }

    sort(arr1, arr1 + n); // O(N)
    sort(arr2, arr2 + m); // O(M)
}

// This will give TLE in GEEKSFORGEEKS
void merge2(int M, int N, int A[], int B[])
{
    // Traverse first array and check each element

    for (int i = 0; i < M; i++)
    {
        // check if first element of second array
        // is smaller

        if (A[i] > B[0])
        {
            swap(A[i], B[0]);
            int j = 0;

            // shift B[0 ] to its correct position in
            // second array

            while (j + 1 < N && B[j] > B[j + 1])

                swap(B[j], B[j + 1]), j++;
        }
    }
}

// Main function
int main()
{
    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // Calling to merge func
    merge1(arr1, arr2, n, m);

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}


// Test cases to run
/**
 *  First test case
 * 	Input:
 * 	5
 *  {0,2,6,8,9}
 *  4
 *  {1,3,5,7}
 *  Output:
 *  {0,1,2,3,5,6,8,9}
 *
 **/

/*
 * 	Second test case
 * 	Input:
 * 	2
 * 	{10,12}
 *  3
 *  {5,18,20}
 * 	Output:
 * 	{5,10,12,18,20}
 *
 */
