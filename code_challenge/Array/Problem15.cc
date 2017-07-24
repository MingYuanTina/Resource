// Question 
	// 121. Best Time to Buy and Sell Stock
	// Say you have an array for which the ith element 
	// is the price of a given stock on day i.
	// If you were only permitted to complete at most one transaction 
	// (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Example
	// Input: [7, 1, 5, 3, 6, 4]	--> Output: 5
	// Input: [7, 6, 4, 3, 1] --> Output: 0

// Constraint
	// Time Complexity: NULL
	// Space Complexity: NULL

// Solution
	// Dynamic Programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0, max = 0;
        for (int i = 1; i < prices.size(); i++){
            diff += prices[i] - prices[i-1];
            if (diff < 0)
                diff = 0;
            if (diff > max)
                max = diff;
        }
        return max;
    }
};