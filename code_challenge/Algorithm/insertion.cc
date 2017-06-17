#include <iostream>
#include <string>
#include "insertion.h"
using namespace std;

Insertion::Insertion(int d[], int l): Algorithm(){
	name = "Insertion Sort";
	description = "Go through list with updating larget value within each inner loop";
	length = l;
	data = d;
}

void Insertion::processAlgorithm(){
	for (int i = 1; i < length; i++){
		int key = data[i];
		int j = i - 1;
		while (j >= 0 && data[j] > key){
			data[j+1] = data[j];
			j = j - 1;
		}
		data[j+1] = key;
	}
}
