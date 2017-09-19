// Question
	// 	537. Complex Number Multiplication
	//  Given two strings representing two complex numbers.
	// 	You need to return a string representing their multiplication. 
	//  Note i2 = -1 according to the definition.

// Constraints
	// The input strings will not have extra blank.
	// The input strings will be given in the form of a+bi, 
	// where the integer a and b will both belong to the range of [-100, 100].
	//  And the output should be also in this form.

class Solution {
public: 
    vector<int> parse_complex_num(string str){
        std::size_t it = str.find("+");
        string first_part = str.substr(0, it);
        string second_part = str.substr(++it, str.size() - it);
        if (second_part.size() != 1){
            second_part = second_part.substr(0, str.size() - 1);
        }
        vector<int> arr;
        arr.push_back(atoi(first_part.c_str()));
        arr.push_back(atoi(second_part.c_str()));
        return arr;
    }    
    
    string complexNumberMultiply(string a, string b) {
        vector<int> arr_first = parse_complex_num(a);
        vector<int> arr_second = parse_complex_num(b);
        
        // Defind number of a,b,c,d
        int a_val = arr_first[0];
        int b_val = arr_first[1];
        int c = arr_second[0];
        int d = arr_second[1];
        
        // Computation
        int real_arg = a_val * c - b_val * d;
        int complex_arg = (a_val * d + b_val * c);
        stringstream real, complex;
        real << real_arg;
        complex << complex_arg;
        return real.str() + "+" + complex.str() + "i"; 
    }
};