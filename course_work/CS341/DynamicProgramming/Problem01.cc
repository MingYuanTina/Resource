// 2017.10.08
// Assignment 4 Question 2
// Dynamic Programming to break a sequence into harmonious parts. 
	// Suppose you have a sequence of musical notes s1s2 . . . sn. 
	// Some subsequences are said to be harmonious. You can test if a sequence is harmonious
	// via a unit-time test H(i, j) that returns 1 if the subsequence sisi+1 . . . sj is harmonious, 
	// and 0 otherwise. Your goal is to break the input sequence into harmonious subsequences if possible.

	// For example, if AB, B, and BAB are the only harmonious sequences, 
	// then the sequence ABBAB can be broken into harmonious sequences as AB | B | AB or as AB | BAB, 
	// ut the sequence ABABA cannot be broken into harmonious sequences.
	// Give a dynamic programming algorithm to test if a sequence can be broken into harmonious subsequences. 
	// The run-time should be O(n3). Clearly indicate what your subproblems are, 
	// and the order in which you solve them. Justify correctness of your algorithm, 
	// and analyze its running time.

// Input:
	// A list of harmonious sequence and a given sequence s
// Output:
	// Return true if the given s can be partition into combination of harmonious sequence


// General Idea
	