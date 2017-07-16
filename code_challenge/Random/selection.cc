#include <iostream>
#include <string>
#include "selection.h"
using namespace std;

Selection::Selection(int d[], int l): Algorithm(){
	name = "Selection Sort";
	description = "Go through the list with selection minimum at each time";
	length = l;
	data = d;

}

void Selection::processAlgorithm(){
	for (int i = 0; i < length; i++){
		int minIndex = i;
		for (int j = i + 1; j < length; j++){
			if (data[j] < data[minIndex]){
				minIndex = j;
			}
		}
		int temp = data[minIndex];
		data[minIndex] = data[i];
		data[i] = temp;
	}
}