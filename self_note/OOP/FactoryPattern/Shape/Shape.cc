#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Shape {
private:
public:
	virtual void draw();
};

class Circle: public Shape {
private:
	//nothing currently
public:
	// This class is override of draw method in Shape class
	void draw(){
		cout << "Inside Circle::draw() method" << endl;
	}
};