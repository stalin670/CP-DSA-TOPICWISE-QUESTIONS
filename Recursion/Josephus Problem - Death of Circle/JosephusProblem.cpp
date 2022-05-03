/**
 * @file JosephusProblem.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    There are n people standing in a circle waiting to be executed. The counting 
    out begins at some point in the circle and proceeds around the circle in a 
    fixed direction. In each step, a certain number of people are skipped and the   
    next person is executed. The elimination proceeds around the circle (which is 
    becoming smaller and smaller as the executed people are removed), until only the 
    last person remains, who is given freedom. Given the total number of persons n and 
    a number k which indicates that k-1 persons are skipped and kth person is 
    killed in circle. The task is to choose the place in the initial circle so 
    that you are the last one remaining and so survive.

    For example: 
    (1) if n = 5 and k = 2, then the safe position is 3. Firstly, the person 
    at position 2 is killed, then person at position 4 is killed, then person 
    at position 1 is killed. Finally, the person at position 5 is killed. 
    So the person at position 3 survives. 
    
    (2) If n = 7 and k = 3, then the safe position is 4. The persons at positions 
    3, 6, 2, 7, 5, 1 are killed in order, and person at 
    position 4 survives.

*/

/*
    pseudo-code :

    Josephus( list , start , k){
    if list.size = 1
        return list[0]
    start = (start + k) % list.size
    list.remove( start )
    return Josephus( list, start, k)
    }

*/

// Question link for practice -> https://practice.geeksforgeeks.org/problems/josephus-problem/1#
// You can check it now, go through the code.
// Keep practicing.


#include <bits/stdc++.h>
using namespace std;

// Josephus func starts here
void Josephus(vector<int> &v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }

    index = (index + k) % v.size();
    v.erase(v.begin() + index);

    Josephus(v, k, index, ans);

    return;
}

// Main funtion
int main()
{
    int n, k;
    cin >> n >> k;
    k--;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }

    int index = 0;
    int ans = -1;

    Josephus(v, k, index, ans);

    cout << ans << endl;

    return 0;
}


/*  
    You can input any string that you want to output.
    so check it out , go through the code.
    Think Recursively.
*/
