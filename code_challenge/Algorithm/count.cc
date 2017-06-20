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
	// Find the max of the array
	int max = data[0];
	for (int i = 1; i < length; i++)
		max = data[i] > max ? data[i] : max;

	// Create array of index
	// int copy[max];
	// for (int i = 0; i < length; i++)
	// 	copy[data[i]]++;

	// Resort array



}
