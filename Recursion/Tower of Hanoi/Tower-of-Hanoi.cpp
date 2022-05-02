

/**
 * @file Tower-of-Hanoi.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
 **/

/*
    Problem Statement-
    The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
    Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N.  Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

*/

/*
    Rules:
    1st : You can take only one disk at a time.
    2nd : You can't put bigger disk over smaller disk.
*/

/*
    Approach:
    Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.
    An example with 2 disks :
        Step 1 : Shift first disk from 'A' to 'B'.

        Step 2 : Shift second disk from 'A' to 'C'.

        Step 3 : Shift first disk from 'B' to 'C'.

*/

/*
    Let's take N=16
    so you'll have to lift and put plate for 65535 times
    then it'll complete.

*/

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

// Expected Time Complexity: O(2^N).
// Expected Auxiliary Space: O(N).
int toh(int N, int from, int to, int aux)
{
    if (N == 0)
        return 0;
    if (N == 1)
    {
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        cnt++;
    }
    else
    {
        toh(N - 1, from, aux, to);
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        cnt++;
        toh(N - 1, aux, to, from);
    }
    return cnt;
}

// Main func goes here
int main()
{
    int N;
    int from = 1, to = 3, aux = 2;
    cin >> N;

    cout << toh(N, from, to, aux) << endl;

    return 0;
}

// You can check by test cases:

/*
    First test case:
    Input:
    N = 2
    Output:
    move disk 1 from rod 1 to rod 2
    move disk 2 from rod 1 to rod 3
    move disk 1 from rod 2 to rod 3
    3
    Explanation: For N=2 , steps will be
    as follows in the example and total
    3 steps will be taken.
*/

/*
    Second test case:
    Input:
    N = 3
    Output:
    move disk 1 from rod 1 to rod 3
    move disk 2 from rod 1 to rod 2
    move disk 1 from rod 3 to rod 2
    move disk 3 from rod 1 to rod 3
    move disk 1 from rod 2 to rod 1
    move disk 2 from rod 2 to rod 3
    move disk 1 from rod 1 to rod 3
    7
    Explanation: For N=3 , steps will be
    as follows in the example and total
    7 steps will be taken.
*/
