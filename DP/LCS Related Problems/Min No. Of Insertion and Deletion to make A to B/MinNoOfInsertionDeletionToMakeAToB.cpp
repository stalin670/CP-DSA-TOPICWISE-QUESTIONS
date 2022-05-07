
/**
 * @file MinNoOfInsertionDeletionToMakeAToB.cpp
 * @date 2022-05-07
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task
    is to remove/delete and insert the minimum number of characters from/in
    str1 to transform it into str2. It could be possible that the same character
    needs to be removed/deleted from one point of str1 and inserted to some
    another point.

    Example 1:
    Input :
    str1 = "heap", str2 = "pea"
    Output :
    Minimum Deletion = 2 and
    Minimum Insertion = 1
    Explanation:
    p and h deleted from heap
    Then, p is inserted at the beginning
    One thing to note, though p was required yet
    it was removed/deleted first from its position and
    then it is inserted to some other position.
    Thus, p contributes one to the deletion_count
    and one to the insertion_count.

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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    // Till here we use LCS code now the code for min no. of insertion and
    // deletion
    int lcs = lcsTopDown(s1, s2, n, m);
    int deletion = n - lcs;
    int insertion = m - lcs;

    cout << "Insertion : " << insertion << endl;
    cout << "Deletion : " << deletion << endl;

    return 0;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
