
    // Reverse An Array

/**
 *  Question link -> https://practice.geeksforgeeks.org/problems/reverse-an-array/0#
 *  Just Basic Stuff
 *  I'll tell 3 ways to do this
 **/

#include <bits/stdc++.h>
using namespace std;

// If they asked just to print the reverse array
// Then simply print the array the from the end
void ReverseAnArray1(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// In this way you can use for loop to do swapping the elements from starting and ending
void ReverseAnArray2(int arr[],int n){
	// we only need to run the loop till < or <=n/2
	for(int i=0;i<n/2;i++){
		swap(arr[i],arr[n-i-1]);
	}

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}

// In this way you can use while loop to do swapping the elements from starting and ending
void ReverseAnArray3(int arr[],int n){
	int start=0;
	int end=n-1;
	
	while(start<=end){
		swap(arr[start],arr[end]);
		start++;
		end--;
	}

	start=0;
	while(start<n){
		cout<<arr[start]<<" ";
		start++;
	}
	cout<<endl;
}


int main() {
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	ReverseAnArray3(arr,n);
	        
	
	return 0;
}



 // Test cases to run
 /**
 *  First test case
 * 	Input:
 * 	5
 *  1 2 3 4 5
 *  Output:
 * 	5 4 3 2 1
 * 
 **/
	
/*
 * 	Second test case
 * 	Input:
 * 	6
 * 	1 2 3 4 5 6
 * 	Output:
 * 	6 5 4 3 2 1
 *  
 */
