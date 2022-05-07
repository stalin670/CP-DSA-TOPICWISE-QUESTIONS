
/**
 * @file MInNoOfDeletionTomakePalindromic.cpp
 * @date 2022-05-07 
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a string of size ‘n’. The task is to remove or delete the minimum
    number of characters from the string so that the resultant string is a palindrome.

    Note: The order of characters should be maintained.

    Examples :

    Input : aebcbda
    Output : 2
    Remove characters 'e' and 'd'
    Resultant string will be 'abcba'
    which is a palindromic string

    Input : geeksforgeeks
    Output : 8

*/

#include <bits/stdc++.h>
using namespace std;

static int dp[10001][10001];
// Lcs function starts here
int lcsTopDown(string s, string t, int n, int m)
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

    return dp[n][m];
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

    int LenOfLps = lcsTopDown(s1, s2, n, m);

    int deletion = n - LenOfLps;

    cout << "Min no. of Deletion to make Palindrom : " << deletion << endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/
