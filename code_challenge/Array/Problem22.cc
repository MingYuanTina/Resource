// Question 22
	//  697. Degree of an Array
	// 	Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum 
	//  frequency of any one of its elements.
	//  Your task is to find the smallest possible length of a (contiguous) subarray of nums, 
	// that has the same degree as nums.


// Break into two parts
// Find the degree of nums (S1)
// Find smallest subarray that contains degree (S2)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // S1
        map<int, int>list;
        for (int i = 0; i < nums.size(); i++){
            list[nums[i]] += 1;
        }
        vector<int>deg;
        int max = 0;
        for (map<int, int>::iterator it = list.begin(); it != list.end(); it++){
            if (it->second > max)
                max = it->second;   
        }
        for (map<int, int>::iterator it = list.begin(); it != list.end(); it++){
            if (it->second == max)
                deg.push_back(it->first);
        }
        // S2
        int min = nums.size();
        map<int, int>d;
        for (int i = 0; i < deg.size(); i++){
            int fre = deg[i], c = 0, j = 0, k = 0;
            while (j < nums.size()){
                if (fre == nums[j]){
                    if (c == 0)
                        k = j;
                    c++;
                }
                if (c == max)
                    break;
                j++;
            }
            d[fre] = j - k + 1;
            if (d[fre] < min)
                min = d[fre];
        }
        return min;
        
    }
};