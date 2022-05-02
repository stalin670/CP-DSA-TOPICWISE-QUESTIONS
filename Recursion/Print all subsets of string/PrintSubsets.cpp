
/**
 * @file PrintSubsets.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
 **/

/*
    print all subsets of string using recursion only
*/

/*
    Approach:
    For every element in the string, there are two choices, either to include it in the subsequence or not include it. Apply this for every element in the array starting from index 0 until we reach the last index. Print the subsequence once the last index is reached.
    Think recursively.
*/

#include <bits/stdc++.h>
using namespace std;

// Func starts here
int printSubsets(string s, string output)
{
    static int cnt = 0;
    if (s.length() == 0)
    {
        cout << output << endl;
        cnt++;
        return cnt;
    }

    string out1 = output;
    string out2 = output;
    out2.push_back(s[0]);
    s.erase(s.begin() + 0);

    printSubsets(s, out1);
    printSubsets(s, out2);

    return cnt;
}

// Main func starts here.
int main()
{
    string s;
    cin >> s;
    string output = "";

    cout << printSubsets(s, output) << endl;


    return 0;
}


// Test cases

/*
    First test case
    Input:
    abc
    Output:
    "Empty string here"
    c  
    b  
    bc 
    a  
    ac 
    ab 
    abc
    8  

*/
