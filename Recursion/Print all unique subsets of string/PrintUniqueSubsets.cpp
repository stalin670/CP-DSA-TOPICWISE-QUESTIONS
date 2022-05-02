
/**
 * @file PrintUniqueSubsets.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
**/

/*
    print all unique subsets of string using recursion only
    and they are in lexicographical order we used set here
    so the elements in set are in order.
*/

/*
    Approach:
    For every element in the string, there are two choices, either to include it in the subsequence or not include it. Apply this for every element in the array starting from index 0 until we reach the last index. Print the subsequence once the last index is reached.
    Think recursively.
*/

#include <bits/stdc++.h>
using namespace std;

set<string> ss;

// Func starts here
void printUniqueSubsets(string s, string output)
{
    static int cnt = 0;
    if (s.length() == 0)
    {
        ss.insert(output);
        return;
    }

    string out1 = output;
    string out2 = output;
    out2.push_back(s[0]);
    s.erase(s.begin() + 0);

    printUniqueSubsets(s, out1);
    printUniqueSubsets(s, out2);

}

// Main func starts here.
int main()
{
    string s;
    cin >> s;
    string output = "";

    printUniqueSubsets(s,output);

    cout<<ss.size()<<endl;
    for(auto x:ss){
        cout<<x<<endl;
    }


    return 0;
}


// Test cases

/*
    First test case
    Input:
    aab
    Output:
    6
    "Empty string here"
    a
    aa
    aab
    ab
    b
    

*/
