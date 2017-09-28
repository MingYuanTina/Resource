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
	// Suppose there are two subset
	// A = {a1, a2, ..., ak} and B = {b1, b2, ... , bl}
		// Case 1: a1, ... , ai, bi+2, ..., bl is a solution if non-overlapping
		// Case 2: overlapping problems
			// Prove by induction
				// BC: a1, b2, ... ,bl since a1 ends before b1
				// IH: a1, a2, ..., ai-1, bi, ..., bl
				// IC: a1, a2, ... ai-1, ai, bi+1, ..., bl

// Implementation
class Solution {
public:
    vector<int> interval_scheduling(map<int, int>&list){
    	// Implementation
    }
};