// 15. 3Sum
// Given an array S of n integers, are there elements a, b, c in S 
// such that a + b + c = 0? Find all unique triplets in the array 
// which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> >twoSum(vector<int>&nums, int target){
    	vector<vector<int> >list;
    	int i = 0;
    	int j = nums.size() - 1;
    	while (i < j){
    		if (nums[i] + nums[j] == target){
    			vector<int>temp;
    			temp.push_back(nums[i]);
    			temp.push_back(nums[j]);
    			list.push_back(temp);
    			i++;
    			j--;
    		} else if (nums[i] + nums[j] < target){
    			i++;
    		} else {
    			j--;
    		}
    	}
    	return list;
    }

    vector<vector<int> >threeSum(vector<int>&num, int target){
    	vector<vector<int> >res;
    	sort(num.begin(), num.end());
    	for (int i = 0; i < num.size() - 2; i++){
    		vector<int>res_list(num.begin() + i + 1, num.end());
    		vector<vector<int> >l = twoSum(res_list, target - num[i]);
    		for (int m = 0; m < l.size(); m++){
    			l[m].push_back(num[i]);
    			res.push_back(l[m]);
    		}
    	}
    	return res;
    }

    void print(vector<vector<int> >&nums){
    	for (int i = 0; i < nums.size(); i++){
    		for (int j = 0; j < nums[i].size(); j++){
    			cout << nums[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
};

int main(){
	int arr[] = {-1,0,1,2,-1,-4};
	int target = 0;
	vector<int>l(arr, arr + sizeof(arr) / sizeof(int));
	Solution s;
	vector<vector<int> >res = s.threeSum(l, 0);
	s.print(res);
	return 0;
}
