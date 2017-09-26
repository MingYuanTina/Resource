// Question 
	//  455. Assign Cookies
	// Assume you are an awesome parent and want to give your children 
	// some cookies. But, you should give each child at most one cookie. 
	// Each child i has a greed factor gi, which is the minimum size of a cookie 
	// that the child will be content with; and each cookie j has a size sj. 
	// If sj >= gi, we can assign the cookie j to the child i, 
	// and the child i will be content. Your goal is to maximize 
	// the number of your content children and output the maximum number.


// Test Cases
	// [1,2,3], [1,1] -> 1
	// [1,2], [1,2,3] --> 1
	// [1,2], [] --> 0
	// [], [1,2] --> 0
	// [1,2,3], [1,2,3] --> 3
	// [4,5,6], [1,2,3] --> 0

// Idea:
	// Greedy ALgorithm
	// Time Complexity: O(n^2)

// Implementation
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0, i = 0;
        while (i < s.size()){
            int j = 0; 
            while (j < g.size()){
                if (s[i] >= g[j]){
                    g.erase(g.begin());
                    j = g.size();
                    c++;
                }
                j++;
            }
            i++;
        }
        return c;
    }
};

