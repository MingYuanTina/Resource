// Question
	//  41. First Missing Positive
	// Given an unsorted integer array, 
	// find the first missing positive integer.

// Test Cases:
	// [] --> 1 (nothing)
	// [1,2,0] --> 3 (missing next)
	// [1] --> 2 (missing next)
	// [3,4,1,0] --> 2 (missing middle)
	// [0,2,3,4] --> 1 (missing initial)
	// [1,1] --> 2 (duplicate cases)

// Constraints 
	// Time Complexity: O(n)
	// Space Complexity: O(1)

// General Strategy:
	// Normal, (n+1)*n/2 - sum, return leftover
	// Special
		// Null: (1)*0/2 - 0 = 0, if 0 return 1? 
		// Nothing Missing: (n+1)*n/2 - sum == 0, if 0 return?

