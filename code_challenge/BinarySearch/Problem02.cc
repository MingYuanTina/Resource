// Question
	//  69. Sqrt(x)
	// Implement int sqrt(int x).
	// Compute and return the square root of x.

// Test Cases
	// 0 --> 0
	// 1 --> 1
	// 2 --> 1
	// 4 --> 2
	// big number --> big number

// General Strategy
	// Binary Search
	// Check if x / mid == mid in a loop given there might be a overflow

// Solution
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) 
            return x; 
         int l = 0,  h = x, mid;
        while(l < h){
            mid = (l+ h) / 2;
            if (x / mid == mid){
                return mid;
            } else if (x / mid > mid){
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return h-1;
    }
};
