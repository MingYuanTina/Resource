#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	// Different Ways to Loop through string
	// First string can converted into array of char
	string str = "test";
	for (char& c : str){
		cout << c;
	}
	cout << endl;

	// Loop through the characters of a string with iterators
	for (string::iterator it = str.begin(); it != str.end(); it++){
		cout << *it;
	}
	cout << endl;

	// Loop through characters of string with old fashin as array
	for (int i = 0; i < str.size(); i++){
		cout << str[i];
	}
	cout << endl;

	// Link: http://www.cplusplus.com/reference/string/string/c_str/
	// Loop through characters of a null-terminated character array
	const char* c  = str.c_str();
	int i = 0; 
	while (c[i] != '\0'){
		cout << c[i];
		i++;
	}
	cout << endl;
	
	return 0;
}