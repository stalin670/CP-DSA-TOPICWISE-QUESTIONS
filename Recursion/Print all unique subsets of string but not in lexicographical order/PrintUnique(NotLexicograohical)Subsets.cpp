
/**
 * @file PrintUnique(NotLexicograohical)Subsets.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
**/

/*
    print all unique subsets of string using recursion only
    and the difference is that they are not in lexicographical oreder 
    they are printed by recursive tree order.
*/

/*
    Approach:
    For every element in the string, there are two choices, either to include it in the subsequence or not include it. Apply this for every element in the array starting from index 0 until we reach the last index. Print the subsequence once the last index is reached.
    Think recursively.
*/

/*
    So if you want elements in lexicographical order use set<int>
    if you want elements by recursive tree order use map<int>
*/

#include <bits/stdc++.h>
using namespace std;

map<string,int> m;

// Func starts here
int printUniqueSubsets(string s, string output)
{
    static int cnt = 0;
    if (s.length() == 0)
    {
        if(m[output]==0){
            cout<<output<<endl;
            m[output]++;
            cnt++;
        }
        return cnt;
    }

    string out1 = output;
    string out2 = output;
    out2.push_back(s[0]);
    s.erase(s.begin() + 0);

    printUniqueSubsets(s, out1);
    printUniqueSubsets(s, out2);

    return cnt;

}

// Main func starts here.
int main()
{
    string s;
    cin >> s;
    string output = "";

    cout<<printUniqueSubsets(s,output)<<endl;

    return 0;
}


// Test cases

/*
    First test case
    Input:
    aab
    Output:
    "Empty string here"
    b 
    a 
    ab
    aa
    aab
    6

    They are not in lexicographical order but in recursive order.


*/
