// Question:  
    // 167. Two Sum II - Input array is sorted
	// Given an array of integers that is already sorted in ascending order, 
	// find two numbers such that they add up to a specific target number.

// Constraint: 
	// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. 
	// Please note that your returned answers (both index1 and index2) are not zero-based.
	//	You may assume that each input would have exactly one solution and you may not use the same element twice.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

// General Strategy 
	// Create two loops that that once it matches with the other return index 
	// Time Complexity: O(n^2)

	// Create hash table and loop through array 
	// Time Complexity: O(n);

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>answer;
        map<int, int>list;
        for (int i = 0; i < numbers.size(); i++){
            int numToTarget = target - numbers[i];
            if (list.find(numToTarget) != list.end()){
                answer.push_back(list[numToTarget] + 1);
                answer.push_back(i + 1);
                break;
            }
            list[numbers[i]] = i;
        }
        return answer;
    }
};

