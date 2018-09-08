// Question
	// 374. Guess Number Higher or Lower
	// We are playing the Guess Game. The game is as follows:
	// I pick a number from 1 to n. You have to guess which number I picked.
	// Every time you guess wrong, I'll tell you whether the number is higher or lower.
	// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0){
            return n;
        }
        int l = 1, h = n;
        int mid;
        while (l <= h){
            mid = (h - l) / 2 + l;
            if (guess(mid) == 0){
                break;
            } else if (guess(mid) == -1){
                h = mid;
            } else {
                l = mid;
            }
        }
        return mid;
    }
};