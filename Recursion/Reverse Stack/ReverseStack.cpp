

/**
 * @file ReverseStack.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    You just have to reverse the stack using recursion without using 
    another stack or any kind of extra space
    just use call stack
*/


/*
    Approach:
    You just need pop out last value and store in some variable
    and call the reverse funtion for the remaining stack
    after that push that element again in stack 

    base condition -> if somehow your stack will get empty just return.

*/


#include<bits/stdc++.h>
using namespace std;

void Reverse(stack<int> &s){
    if(s.empty()) return;

    int val=s.top();
    s.pop();
    Reverse(s);

    s.push(val);
}

// Main function goes here
int main(){
    stack<int> s;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.push(x);
    }

    Reverse(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;


}


// Test cases

/*
    input :
    5
    1 2 3 4 5

    Output:
    5 4 3 2 1

*/
