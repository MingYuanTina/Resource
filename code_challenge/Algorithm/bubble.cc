#include <iostream>
#include <string>
#include "bubble.h"
using namespace std;

Bubble::Bubble(int d[], int l): Algorithm(){
	name = "Bubble Sort";
	description = "Go through list with swaping with smaller element within each inner loop";
	length = l;
	data = d;
}

void Bubble::processAlgorithm(){
	for (int i = 0; i < length; i++){
		for (int j = length - 1; j > i; j--){
			if (data[j] < data[j-1]){
				int temp = data[j];
				data[j] = data[j-1];
				data[j-1] = temp;
			}
		}
	}
}
