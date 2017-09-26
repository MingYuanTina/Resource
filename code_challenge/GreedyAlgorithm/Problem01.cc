// Sep 25th, 2017
// Interval Scheduling
	// Given array of start, end time
	// Find the maximum subset of mutually non-overlap interval 

// Idea:
	// Sort by end time
	// For each interval if ai does not overlap anything added to array
	// Time Complexity:
		// O(nlogn) + O(n) = O(nlogn)

// Test Case:
	// All mutually exclusive (Overlapping)
	// Non-overlapping
		// One big interval cover all
		// No mutually exclusive
		// Several subset of intervals --> optimize the maximum

// Claim: greedy gives max # activities
	// 

// Implementation
class Solution {
public:
    vector<int> interval_scheduling(map<int, int>&list){
    	// Implementation
    }
};