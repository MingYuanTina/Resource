#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	// Question Storage
	string manual[] = {
		"0. Show manual",
		"q. Quit",
		"1. What is OOPs",
		"2. What are basic concepts of OOPS",
		"3. What is class",
		"4. What is object",
		"5. What is Encapsulation",
		"6. What is Polymorphism",
		"7. What is Inheritance",
		"8. What is manipulators",
		"9. What is constructor",
		"10. What is destructor",
		"11. What is inline function",
		"12. What is virtual function",
		"13. What is friend function",
		"14. What is function overloading",
		"15. What is operator overloading",
		"16. What is abstract class"
	};
	map<int, string> list_questions;
	list_question[1] = "OOS combines the concepts of function and attribute into one as a collection of object";
	list_question[2] = "Abstraction, Encapsulation, Inheritance, Polymorphism";
	// 	{3, "Class is the epresentation of a type of object"},
	// 	{4, "Object is instance of class"},
	// 	{5, "Encapsulation is information hiding seperate function/attr in class into three levels: private, protected, public"},
	// 	{6, "Polymorphism is common interface created for concrete and abstract classes"},
	// 	{7, "Inheritance is structure-design that allows one type of class share the behavior of another"},
	// 	{8, "Manipulators are the functions used in conjunction with << and >>. Examples are endl and setw"},
	// 	{9, "Constructor is initialization of an object. It is invoked at the time of object creation"},
	// 	{10, "Destructor is automatically calle when the object is made of scope or destroyed"},
	// 	{11, "Inline function is a technique used by the compiler and instructs to insert complete body of function"}
	// };

	// Print Table
	for (int i = 0; i < sizeof(manual)/sizeof(manual[0]); i++){
		cout << manual[i] << endl;
	}
	string usr_select = "";
	while (1){
		cout << "Please select an option" << endl;
		cin >> usr_select;
		if (usr_select == "q"){
			break;
		}
	}
	return 0;
}