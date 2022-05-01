

/**
 * @file SortingOfArray.cpp
 * @date 2022-05-01
 * @copyright Copyright (c) 2022
**/

/*
    Well you can sort the array in many ways but here
    I've sort the array using recursion only-
    So check it right now 
    Go through the code!
*/

#include<bits/stdc++.h>
using namespace std;

// Insert the element back to stack
void insert(vector<int> &v ,int last){
    if(v.size()==0 || v[v.size()-1]<=last){
        // If you want to sort in decreasing order
        // Just replace 
        // Use v[v.size()-1]>=last in place of v[v.size()-1]<=last at line 21
        v.push_back(last);
        return;
    }

    int temp=v[v.size()-1];
    v.pop_back();
    insert(v,last);

    v.push_back(temp);

}

// Just to decrease the size of the stack by this function
// As recursion works 
void sort(vector<int> &v){
    if(v.size()==1){
        return;
    }
    int last=v[v.size()-1];
    v.pop_back();
    sort(v);

    insert(v,last);
    
}

// Main funtion
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }


    return 0;
}

// You can check by input you own test cases.
