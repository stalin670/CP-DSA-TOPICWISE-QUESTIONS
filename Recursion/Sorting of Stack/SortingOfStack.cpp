
/**
 * @file SortingOfStack.cpp
 * @date 2022-05-01
 * @copyright Copyright (c) 2022
**/

/*
    I've sort the Stack using recursion only without using any extra space-
    This works just same as we'd sort the array using recursion
    Check it right now, go through the code!
*/

#include<bits/stdc++.h>
using namespace std;

// This func is insertin those element to back to stack which we
// pop out during sorting
void insert(stack<int> &s, int val){
    if(s.empty() || s.top()>=val){
        // If you want to sort in decreasing order
        // Just replace 
        // Use s.top()<=val in place of s.top()>=val at line 20
        s.push(val);
        return;
    }

    int temp=s.top();
    s.pop();
    insert(s,val);

    s.push(temp);

}

// This function helps in reducing the size of the stack so the
// we can deal easily with small stack.
void sort(stack<int> &s){
    if(s.empty()) return;

    int val=s.top();
    s.pop();
    sort(s);

    insert(s,val);
}

// Main funtion starts from here
int main(){
    stack<int> s;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.push(x);
    }

    sort(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


}

// You can check by running the test cases
// It works fine
// Don't think about time complexity
// Here we'r only working on recursion solution not the best solution.
