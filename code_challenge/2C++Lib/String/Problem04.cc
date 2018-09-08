// Question
    // 520  Detect Capital
    // Given a word, you need to judge whether the usage of 
    // capitals in it is right or not.
    // We define the usage of capitals in a word 
    // to be right when one of the following cases holds:
    
    // Definition
    // All letters in this word are capitals, like "USA".
    // All letters in this word are not capitals, like "leetcode".
    // Only the first letter in this word is capital if it has more than one letter, like "Google".
    // Otherwise, we define that this word doesn't use capitals in a right way.

// Test cases
    // All capitals letters, "USA"
    // All lower case letters, "leetcode"
    // Only first ltter capital, "Tina"
    // Otherwsie, "flaG"

// Constraint
    // Note: The input will be a non-empty word consisting of 
    // uppercase and lowercase latin letters.
    // Time Complexity: O(n)
    // Space Complexity: O(1)

// Solution
class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0, lower_c = 0; 
        bool  is_cap = false;
        // If all letters in this word are capitals, like "USA"
        for (string::iterator it = word.begin(); it != word.end(); it++){
            if (lower_c == 0 && c == 0 && *it >= 'A' && *it <= 'Z')
                is_cap = true;
            if (*it >= 'A' && *it <= 'Z')
                c++;
            if (*it >= 'a' && *it <= 'z')
                lower_c++;
        }
        // List all three cases
        if (c == word.size() || 
            lower_c == word.size() || 
            (lower_c == word.size() - 1 && is_cap))
            return true;
        return false;
    }
};