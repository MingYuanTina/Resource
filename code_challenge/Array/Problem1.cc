// Problem: Find the peak element in the array
//	A peak element in an integer array is defined as an element
//	that is greater than its neighbours 
// 	Input: Given an input array
// 	Output: find a peak element and returns its index
// 	Time/Space Complexity: O(logn)

// Test Cases
// 	Case 1: No peak element (empty array, increasing/decreasing order)
// 	Case 2: only one peak element --> [1,3,2]
// 	Case 3: multiple peak element (any one of them) --> [2,4,3,1]

// Appproach
// 	Since we are only required to find any peak element in the array
// 	This is equvailent to searching an element where its acceptance criterias is that
//	the value of the element is greater than its neightbour elements
// 	Thus the most intuitive approach is using binary search with searching peak

// Code
#include <iostream>
#include <string>
using namespace std;

// Solution 1: O(n)
int naive_find_peak(int arr[], int length){
	for (int i = 1; i <= length - 2; i++){
		if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
			return i;
		}
	}
	return -1;
}

int main(){
	int length = 4;
	int arr[] = {1,2,3,1};
	int element = naive_find_peak(arr, sizeof(arr)/sizeof(int));
	cout << element << endl;
	return 0;
}

