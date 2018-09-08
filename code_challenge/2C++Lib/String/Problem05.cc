// Question
	// 20. Valid Parentheses
	// Given a string containing just the characters 
	// '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	// The brackets must close in the correct order,
	//  "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

// Test Cases	
	// null -> true
	// "()" -> true
	// "([{}])" -> true
	// "([})" -> false (not balanced)
	// "()[]" -> true
	// "([()]())" -> true

// Solution:
class Solution {
public:
    bool isValid(string s) {
        stack<char> l;
        if (s.size() <= 1)
            return false;
        for (string::iterator it = s.begin(); it != s.end(); it++){
            if (*it == '(' || *it == '[' || *it == '{'){
                l.push(*it);
            } else {
                if (*it == ')' &&  (l.empty() || l.top() != '(')) {
                    return false;
                } else if (*it == ']' && (l.empty() || l.top() != '[')) {
                    return false;
                } else if (*it == '}' && (l.empty() || l.top() != '{')) {
                    return false;
                } else {
                    l.pop();
                }
            }
        }
        if (l.empty())
            return true;
        else 
            return false;
    }
};