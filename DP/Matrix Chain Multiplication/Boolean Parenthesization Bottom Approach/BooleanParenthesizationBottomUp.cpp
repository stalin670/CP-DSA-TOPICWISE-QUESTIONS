
/**
 * @file BooleanParenthesizationBottomUp.cpp
 * @date 2022-05-11 
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement: ( Bottom up approach -> Recursive + Memoization )
    Given a boolean expression with following symbols.

    Symbols
        'T' ---> true
        'F' ---> false
    And following operators filled between symbols

    Operators
        &   ---> boolean AND
        |   ---> boolean OR
        ^   ---> boolean XOR
    Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
    Let the input be in form of two arrays one contains the symbols (T and F) in order and the other contains operators (&, | and ^}

    Problem Level -> Difficult

*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;

// Boolean Parenthesization (Recursive + Memoization) function
int BooleanParenthesization(string s, int i, int j, int isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue == 1)
        {
            return s[i] == 'T';
        }
        else
            return s[i] == 'F';
    }

    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if(m.find(temp)!=m.end()){
        return m[temp];
    }



    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int leftF, leftT, rightT, rightF;
        leftF = BooleanParenthesization(s, i, k - 1, 0);
        rightF = BooleanParenthesization(s, k + 1, j, 0);
        leftT = BooleanParenthesization(s, i, k - 1, 1);
        rightT = BooleanParenthesization(s, k + 1, j, 1);

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
    }

    return m[temp]=ans;
}

// Main function starts here
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s = "";
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    cout << BooleanParenthesization(s, 0, s.size() - 1, 1) << endl;
}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
