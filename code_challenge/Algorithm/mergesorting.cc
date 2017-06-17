#include <iostream>
#include <string>
#include <vector>
#include "mergesorting.h"
using namespace std;

// Helper function
vector<int> copy(int data[], int start, int end){
	vector<int> temp;
	int len = end - start + 1;
	for (int i = start; i < len; i++){
		temp.push_back(data[i]);
	}
	return temp;
}

MergeSorting::MergeSorting(int d[], int l): Algorithm(){
	name = "Merge Sort";
	description = "Divide and merge";
	length = l;
	data = d;
}

void sort_array(vector<int> data){
	vector<int>::iterator mid_pos = data.begin() + data.size() / 2;
 //	vector<int> right = copy(temp, mid, data.size() - 1);
	

}


// Merge function that first divde and conquer recursively
void MergeSorting::processAlgorithm(){
	// TEMP SOLUTION: copy data to vector structure
	vector<int> temp = copy(data, 0, length - 1);
	sort_array(temp);
	//sort_array(data, length);
}


