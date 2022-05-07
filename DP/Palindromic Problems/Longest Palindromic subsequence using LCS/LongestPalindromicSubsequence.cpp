
/**
 * @file LongestPalindromicSubsequence.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    Given a sequence, find the length of the longest palindromic subsequence in it.

    if the given sequence is “BBABCBCAB”, then the output should be 7 as
    “BABCBAB” is the longest palindromic subsequence in it. “BBBBB” and
    “BBCBB” are also palindromic subsequences of the given sequence,
    but not the longest ones.

*/

#include <bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Lcs function starts here
string lcsTopDown(string s, string t, int n, int m)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string result;

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            result += s[i - 1];
            i--;
            j--;
        }

        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

// Main function starts here
int main()
{
    string s1;
    cin >> s1;
    int n = s1.size();

    // we pass second string as a reverse of 1st string.

    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = s2.size();

    cout << lcsTopDown(s1, s2, n, m);

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
