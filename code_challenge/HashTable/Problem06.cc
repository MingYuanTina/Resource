// 645. Set Mismatch
	// The set S originally contains numbers from 1 to n. 
	// But unfortunately, due to the data error, one of the numbers 
	// in the set got duplicated to another number in the set, 
	// which results in repetition of one number and loss of another number.
	// Given an array nums representing the data status of this set after the error. 
	// Your task is to firstly find the number occurs twice and then find the number 
	// that is missing. Return them in the form of an array.
	// The given array size will in the range [2, 10000].
	// The given array's numbers won't have any order.

// Testing Cases
	// [] -> []
	// [1,3,3] -> [2,3]
	// [1,2,2] --> [2,3]
	// [2,2] --> [1,2]
	// [1,2,2,4,5] --> [2,3]

// Implementation
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>list;
        // Find number occur twice
        map<int, int>hash_map;
        int i = 0;
        for (int n : nums){
            hash_map[n]++;
            if (hash_map[n] == 2)
                list.push_back(n);
        }
        // Find number occur missing
        int sum = 0, max = 0;
        for (map<int, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
            sum += it->first;
            if (it->first > max)
                max = it->first;
        }
        int total = max * (max + 1) / 2;
        if (total == sum)
            list.push_back(max + 1);
        else
            list.push_back(total - sum);
        // Return list
        return list;
    }
};
