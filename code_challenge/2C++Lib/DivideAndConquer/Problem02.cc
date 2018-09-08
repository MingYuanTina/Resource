// Problem 02
	// Assignment 3
	// Divide-and-conquer. 
	// The input for this problem consists of n radar stations where station i is given by its integer coordinates xi and yi in the plane. 
	// We say that station i can transmit to station j if station j is south-west of station i, i.e., xi ≥ xj and yi ≥ yj. The “load factor” of 
	// station i is defined to be the number of stations it can transmit to (not counting itself). 
	// The goal is to compute the load factor of each station. You will develop and implement two algorithms for this problem

// Test Cases
	// Empty
	// Small sample
	// Large sample

// First Approach: Brute Force --> Runtime: O(n^2)
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int calculate_load_factor(int number, vector<int>station, vector<int>x_coord, vector<int>y_coord){
	int count = 0;
	map<int, int>list;
	for (int i = 0; i < number; i++){
		for (int j = 0; j < number; j++){
			if (x_coord[j] <= x_coord[i] && y_coord[j] <= y_coord[i] && i != j){
				count += 1;
			}
		}
		list[station[i]] = count;
		count = 0;
	}
	for (map<int, int>::iterator it = list.begin(); it != list.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	return count;
}


int main(){
	int number;
	vector<int>x_coord;
	vector<int>y_coord;
	vector<int>station;
	cin >> number;
	for (int i = 0; i < number; i++){
		int station_id, x, y;
		cin >> station_id >> x >> y;
		station.push_back(station_id);
		x_coord.push_back(x);
		y_coord.push_back(y);
	}
	int load_factor = calculate_load_factor(number, station, x_coord, y_coord);
	return load_factor;
}