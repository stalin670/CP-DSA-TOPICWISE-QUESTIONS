/**
 * @file N-bit-BinaryNumber.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    You have given a integer number N and you have to make all N digit Binary
    number in which number of 1's is >= number of 0's.

    Do by recursion only.

    Approach:
    Every time we call function we have two choices either we include 1 or include 0
    so for the very first time we can't include 0 , if we do so then our condition
    i.e. 1's >= 0's will get fail.
    and after that we'll check if ones > zeroes than we can include zero.

    Example 1:
    Input:
    3
    Output:
    111
    110
    101

    Example 2:
    Input:
    4
    Output:
    1111
    1110
    1101
    1100
    1011
    1010

*/

#include <bits/stdc++.h>
using namespace std;

// NbitBinary func starts here
void NbitBinaryNumber(int n, int ones, int zeroes, string out)
{
    if (n == 0)
    {
        cout << out << endl;
        return;
    }

    // for including 1 we don't need to check condition
    // this will always happen
    string out1 = out;
    out1.push_back('1');
    NbitBinaryNumber(n - 1, ones + 1, zeroes, out1);

    // for including 0 we need to check this condition
    // that 1's > 0's
    if (ones > zeroes)
    {
        string out2 = out;
        out2.push_back('0');
        NbitBinaryNumber(n - 1, ones, zeroes + 1, out2);
    }

    return;
}

// Main func starts here
int main()
{
    int n;
    cin >> n;
    int ones = 0, zeroes = 0;

    string s = "";

    NbitBinaryNumber(n, ones, zeroes, s);

    return 0;
}

// You can input any string that you want to output.
// so check it out , go through the code.
// Think Recursively.
