
/**
 * @file DeleteMiddleEleofStack.cpp
 * @date 2022-05-02
 * @copyright Copyright (c) 2022
**/

/*
    Problem statement:
    You just have to delete the middle element of the stack using recursion without using 
    another stack or any kind of extra space
    just use call stack
*/

/*
    Approach:
    Calculate the position of middle element before calling the func
    call that func with passing stack and pos of middle ele
    every time you pop out element store somewhere and decrease pos of ele by 1

    when pos of ele reaches to 1 
    pop out the element and do not store any where
    and push rest of the elements

*/

#include<bits/stdc++.h>
using namespace std;

void DeleteMiddle(stack<int> &s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int val=s.top();
    s.pop();
    DeleteMiddle(s,k-1);

    s.push(val);

}

// Main func goes here
int main(){
    stack<int> s;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.push(x);
    }

    int k=(n/2)+1;
    
    DeleteMiddle(s,k);


    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}


// Test cases

/*
    First test case:
    Input:
    5
    1 2 3 4 5
    Output:
    5 4 2 1

*/

/*
    Second test case:
    Input:
    8
    1 2 3 4 5 6 7 8
    Output:
    8 7 6 5 3 2 1

*/



