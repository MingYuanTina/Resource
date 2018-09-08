// Question:  
    // 169. Majority Element
	// Given an array of size n, find the majority element. 
	// The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// Constraint: 
	// You may assume that the array is non-empty 
	// and the majority element always exist in the array.

// General Strategy:
	// Map value with number of apparence
	// which one is the most one will be the major element
	
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>list;
        for (int n : nums)
            list[n] += 1;
        int max = 0, element = 0; 
        for (map<int, int>::iterator it = list.begin(); it != list.end(); it++){
            if (it->second > max)
                element = it->first;
                max = it->second;
        }
        return element;
    }
};
