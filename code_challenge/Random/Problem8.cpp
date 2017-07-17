// Question: Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        string final, each = "";
        istringstream ss(s);
        while (ss >> each){
            reverse(each.begin(), each.end());
            final += each;
            final = ss.eof() ? final : final + " "; // detect when it is the next line
        }
        return final;
    }
};