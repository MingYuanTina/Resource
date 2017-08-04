// Question 
	// 575. Distribute Candies

// Given an integer array with even length, where different numbers 
// in this array represent different kinds of candies. 
// Each number means one candy of the corresponding kind. 
// You need to distribute these candies equally in number to 
// brother and sister. Return the maximum number of kinds of 
// candies the sister could gain.

// Test Cases
	// [] --> 0
	// [1,2] --> 1
	// [1,1,2,2,3,3] --> 3
	// [1,1,1,2,2,3] --> 3
	// [1,1,1,1,2,1] --> 2


// General Strategy:
	// Split into two cases
	// Total number of candles / 2 can be split into different candies
	// Otherwise, return maximize count (size of hash map)
#include <vector>
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int>list;
        for (int n : candies){
            list[n]++;
        }
        if (candies.size() / 2 > list.size()){
            return list.size();
        } else {
            return candies.size() / 2;
        }
    }
};


