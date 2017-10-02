#include <iostream>
#include <string>
#include "Shape.cc"

class ShapeFactory{
private:
	// nothing
public:
	Shape getShape(string shapeType){
		if (shapeType == "circle"){
			return new Circle();
		} else if (shapeType == "rectangle"){
			//return new Rectangle();
		} else if (shapeType == "square"){
			//return new Square();
		} 
	}
};