
/**
 * @file kadaneAlgo.cpp
 * @date 2022-04-29
 * @copyright Copyright (c) 2022
**/

// Question link -> https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// You can just click to this link and check it out !!!
// Go to bottom for Test Cases

#include <bits/stdc++.h>
using namespace std;

// Max. SubArray Sum Function
int maxSubArraySum(int arr[], int size)
{
    int FinalSum = INT_MIN;
    int curr = 0;

    for (int i = 0; i < size; i++)
    {
        curr = curr + arr[i];
        FinalSum = max(FinalSum, curr);

        if (curr < 0)
            curr = 0;
    }
    return FinalSum;
}

// Main funtion
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout << maxSubArraySum(arr, n);

    return 0;
}


 // Test cases to run
 /**
 *  First test case
 * 	Input:
 * 	5
 *  1 2 -9 4 5
 *  Output:
 * 	9
 * 
 **/
	
/*
 * 	Second test case
 * 	Input:
 * 	6
 * 	-1 -2 -3 -4 -5 -6
 * 	Output:
 * 	-1
 *  
 */

/*
 * 	Third test case
 * 	Input:
 * 	6
 * 	-1 -2 -3 0 -5 -6
 * 	Output:
 * 	0
 *  
 */
