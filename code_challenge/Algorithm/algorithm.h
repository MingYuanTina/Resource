// in algorithm.h
#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>

class Algorithm {
	protected:
		std::string name;
		std::string description;
		int length;
		int *data;
	public:
		virtual ~Algorithm(){};
		std::string getName();
		std::string getDescription();
		int getLength();
		void printData();
		// Error: when make processAlgorithm(), error occurs at compilation
		// Error Message: libc++abi.dylib: Pure virtual function called!
		// Reference: http://www.artima.com/cppsource/pure_virtual.html
		virtual void processAlgorithm()=0;
};
#endif