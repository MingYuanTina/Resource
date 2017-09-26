// Question
	// 322. Coin Change
	// You are given coins of different denominations 
	// and a total amount of money amount. 
	// Write a function to compute the fewest number 
	// of coins that you need to make up that amount. 
	// If that amount of money cannot be made up by 
	// any combination of the coins, return -1.

// Implementation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        int c = 0, i = coins.size() - 1;
        while (amount > 0 && i >= 0) {
            if (amount / coins[i] != 0){
                c += (amount / coins[i]);
                amount = amount % coins[i];
            } else {
                i--;
            }
        }
        if (amount == 0)
            return c;
        else 
            return -1;
        
    }
};