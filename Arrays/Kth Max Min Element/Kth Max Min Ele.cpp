
/**
 * @file Kth-max-ele.cpp
 * @date 2022-04-30
 * @copyright Copyright (c) 2022
**/

// Same approach for finding the Kth smallest element.
// Question link -> https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Check it out and try by yourself

/*
    Problem statement:
    Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth largest element in the given array. It is given that all array elements are distinct.
*/

#include <bits/stdc++.h>
using namespace std;


int kthMaximum(int arr[], int l, int r, int k)
{
    // code here
    sort(arr, arr + r + 1, greater<int>());
    return arr[k - 1];
}

// Main Funtion
int main()
{
    cout<<"Enter the value of total no. of elements of array :"<<endl;
    int n;
    cin >> n;
    cout<<"Enter the value of K :"<<endl;
    int k;
    cin >> k;
    cout<<"Enter the array elements :"<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << kthMaximum(arr, 0, n - 1, k) << endl;

    return 0;
}
