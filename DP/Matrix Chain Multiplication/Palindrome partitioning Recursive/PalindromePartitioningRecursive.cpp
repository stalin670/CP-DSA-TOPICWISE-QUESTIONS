
/**
 * @file PalindromePartitioningRecursive.cpp
 * @date 2022-05-08
 * @copyright Copyright (c) 2022 
**/

/*
    Problem statement:
    Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 

    For example, 
    “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed. 

    Input : str = “geek” 
    Output : 2 
    We need to make minimum 2 cuts, i.e., “g ee k”
    Input : str = “aaaa” 
    Output : 0 
    The string is already a palindrome.
    Input : str = “abcde” 
    Output : 4
    Input : str = “abbac” 
    Output : 1 

*/

#include<bits/stdc++.h>
using namespace std;

bool CheckPalindrome(string s,int i,int j){
    bool check=true;
    while(i<j){
        if(s[i]!=s[j]){
            check=false;
            break;
        }
        i++;
        j--;
    }

    if(check) return 1;
    return 0;

}

// Palindrome partitioning (Recursive) function
int PalindromePartitioning(string s,int i,int j){
    if(i>=j){
        return 0;
    }

    if(CheckPalindrome(s,i,j)){
        return 0;
    }

    int ans=INT_MAX;

    for(int k=i;k<=j-1;k++){
        int temp=PalindromePartitioning(s,i,k)+PalindromePartitioning(s,k+1,j)+1;

        ans=min(ans,temp);
    }

    return ans;

}

// Main function starts here
int main(){
    string s; cin>>s;
    int i=0,j=s.length()-1;

    cout<<PalindromePartitioning(s,i,j);

}

// I've provided test case above
// You can dry run with other cases
// link -> https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
