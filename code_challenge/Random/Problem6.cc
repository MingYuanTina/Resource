#include <iostream>
using namespace std;
class Shape {
protected: 
	int width, height;
public:
	Shape (int a = 0, int b = 0){
		width = a;
		height = b;
	}
	//virtual void print(){}
	virtual int area(){ 
		return 0; 
	}
};

class Rectangle: public Shape {
public:
	Rectangle(int a = 0, int b = 0): Shape(a,b){ }
	int area(){
		return width * height;
	}
	// void print(){
	// 	cout << "Rectangle area is: " << area() << endl;
	// }
};

class Triangle: public Shape {
public:
	Triangle (int a = 0, int b = 0): Shape(a,b) { }
	int area(){
		return width * height / 2;
	}
	// void print(){
	// 	cout << "Triangle area is: " << area() << endl;
	// }
};

int main (){
	Shape *shape_one;
	Rectangle rect(10, 7);
	shape_one = &rect;
	cout << shape_one->area() << endl;
	//shape->print();

	//shape.area();

	// Shape *shape;
	// Rectangle rec(10, 7);
	// Triangle tri(10, 5);
	// shape = &rec;
	// shape->area();
	// shape = &tri;
	// shape->area();
	return 0;
}
