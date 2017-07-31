// Question
	// 599. Minimum Index Sum of Two Lists
	// Suppose Andy and Doris want to choose a restaurant for dinner,
	// and they both have a list of favorite restaurants represented by strings.	
	// You need to help them find out their common interest with the least list index sum. 
	// If there is a choice tie between answers, output all of them with no order requirement. 
	// You could assume there always exists an answer.

	// Note:
	// The length of both lists will be in the range of [1, 1000].
	// The length of strings in both lists will be in the range of [1, 30].
	// The index is starting from 0 to the list length minus 1.
	// No duplicates in both lists.

// Test Cases
	// [], [] --> []
	// [], ["Sogo"] --> []
	// ["Sogo"], ["Heju"] --> []
	// ["Sogo", "Jane"],["Jane", "Sogo"] -> ["Sogo", "Jane"]

// Solution
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int>map_l;
        // Store matched element in hash map with it name and sum
        for (int i = 0; i < list1.size(); i++){
            for (int j = 0; j < list2.size(); j++){
                if (list1[i] == list2[j]){
                    map_l[list1[i]] = i + j;
                }
            }
        }
        // Find out the min of their sum in hash map list
        map<string, int>::iterator it = map_l.begin();
        int min = it->second;
        for (; it != map_l.end(); it++){
            if (min > it->second){
                min = it->second;
            }
        }
        // Push all element with min sum to vector list
        vector<string>l;
        for (map<string, int>::iterator i = map_l.begin(); i != map_l.end(); i++){
            if (i->second == min){
                l.push_back(i->first);
            }
        }
        return l;
    }
};
