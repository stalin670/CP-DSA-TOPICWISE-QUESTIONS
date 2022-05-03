
/**
 * @file MergeIntervals.cpp
 * @date 2022-05-03
 * @copyright Copyright (c) 2022
 **/

/*
    Problem statement:
    Given an array of intervals where intervals[i] = [starti, endi], merge all
    overlapping intervals, and return an array of the non-overlapping
    intervals that cover all the intervals in the input.

*/

/*
    Example 1:
    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    Example 2:
    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

// Question link -> https://leetcode.com/problems/merge-intervals/
// You can check it out, go through the code.
// Problem level -> Medium

#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
    return a[0] < b[0];
}

// Merge funtion starts here
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> final;
    sort(intervals.begin(), intervals.end(), cmp);

    final.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= final.back()[1])
        {
            final.back()[1] = max(intervals[i][1], final.back()[1]);
        }
        else
        {
            final.push_back(intervals[i]);
        }
    }

    return final;
}

// Main funtion
int main()
{   
    int n; cin>>n;
    vector<vector<int>> intervals(n),answer;

    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        intervals[i].push_back(x);
        intervals[i].push_back(y);
    }

    answer=merge(intervals);

    cout<<"[";
    for(int i=0;i<answer.size();i++){
        cout<<"["<<answer[i][0]<<","<<answer[i][1]<<"],";
    }
    cout<<"]";


    return 0;
}

// Test cases to run
// I've given test cases above 
// You can check it out.
