#include <iostream>
#include <string>
#include "algorithm.h"
using namespace std;

string Algorithm::getName(){
	return name;
}

string Algorithm::getDescription(){
	return description;
}

int Algorithm::getLength(){
	return length;
}

void Algorithm::printData(){
	for (int i = 0; i < length; i++){
		cout << data[i] << " ";
	}
	cout << endl;
}

