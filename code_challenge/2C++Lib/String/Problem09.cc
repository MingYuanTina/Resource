// Question
	// 38. Count and Say
	// The count-and-say sequence is the sequence of integers with the first five terms as following:
	// 1.     1
	// 2.     11
	// 3.     21
	// 4.     1211
	// 5.     111221

	// Explanation
	// 1 is read off as "one 1" or 11.
	// 11 is read off as "two 1s" or 21.
	// 21 is read off as "one 2, then one 1" or 1211.

// General Strategy
	// Base Case 1: If 0 return 0
	// Base Case 2: If 1 return '1'
	// Otherwise: Go through 1 - n
	// And generate string based on previous string each time

// Solution
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";  
    	if (n == 1) return "1";
        string res="1", temp;
    	for (int i = 1; i < n; i++){  
    		for (int j = 0; j < res.size(); j++){  
    		    int c = 1; 
				while (j + 1 < res.size() && res[j] == res[j + 1]){
                    j++;
					c++;    
				}
    			temp = temp + std::to_string(c) + res[j];
    		}
    		res = temp;
    		temp.clear();
    	}
    	return res;
    }
};