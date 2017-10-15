// Question 21
// 219. Contains Duplicate II
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
// in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
protected:
	vector<int>nums;
	int k; 
public:
	virtual bool containsNearbyDuplicate() = 0;
};

class Naive_Sol : public Solution {
public:
	Naive_Sol(vector<int>nums, int k){
		this->nums = nums;
		this->k = k;
	}
	bool containsNearbyDuplicate(){
		for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[i] == nums[j] && abs(i - j) <= k){
                return true;
            }
        }
    }
    return false;
	}
};

class Better_Sol: public Solution {
public:
	Better_Sol(vector<int>nums, int k){
		this->nums = nums;
		this->k = k;
	}
	bool containsNearbyDuplicate(){
		map<int, int>list;        
    for (int i = 0; i < nums.size(); i++){
      map<int, int>::iterator it = list.find(nums[i]);
      if (it != list.end()){
        if (i - it->second <= k){
        	return true;
        }
      } else {
        list[nums[i]] = i;   
      }
    }
    return false;
	}
};

int main(){
	int arr[] = {1,2,1};
	int k = 0;
	vector<int>l(arr, arr + sizeof(arr) / sizeof(int));
	Solution *s = new Naive_Sol(l, k);
	cout << s->containsNearbyDuplicate() << endl;
	Solution *bs = new Better_Sol(l, k);
	cout << bs->containsNearbyDuplicate() << endl;
}