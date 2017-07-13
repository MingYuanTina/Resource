// Remove duplicates
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>dup;
        for (int n : nums){
            dup[n] += 1;
            if (dup[n] == 2)
                return true;
        }
        return false;
    }
};

// Other Interesting Solution
//  std::set is typically implemented as a binary search tree(RB tree in GCC 4.8). 
    // It costs O(nlogn) to construct. 
    // While std::unordered_set uses hash table
    // O(n) is expected. 
class Solution_Alternative {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();        
    }
};