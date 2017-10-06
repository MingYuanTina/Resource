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
#include <algorithm>
using namespace std;

map<int, vector<int> > merge(map<int, vector<int> >list_left, map<int, vector<int> >list_right){
	map<int, vector<int> >::iterator l = list_left.begin();
	for (map<int, vector<int> >::iterator r = list_right.begin(); r != list_right.end(); r++){
		//cout << "test-------- " << r->second[0] << " " << r->second[1] << endl;
		map<int, vector<int> >::iterator l = list_left.end();
		l--;
		for (int i = 0; i < list_left.size(); i++){
			if (r->first > l->first){
				r->second[1] = r->second[1] + l->second[1] + 1;
				break;
			}
			l--;
		}
	}
	for (map<int, vector<int> >::iterator it = list_right.begin(); it != list_right.end(); it++){
		list_left[it->first] = it->second;
		//cout << "test:::::: " << it->second[0] << " " << it->second[1] << endl;
	}
	return list_left;
}

map<int, vector<int> > calculate(map<int, int>x_coord, map<int, int>y_coord, int l, int r){
	map<int, vector<int> >list;
	//cout << "test: " << y_coord.size() << " " << l << " " << r << endl;
	if (y_coord.size() == 1){
		map<int, int>::iterator it = y_coord.begin();
		vector<int>temp;
		temp.push_back(it->first);
		temp.push_back(0);
		list[it->second] = temp;
		return list;
	}

	if (l < r){
    int m = (l + r) / 2;
    map<int, int>x_left, x_right, y_left, y_right;
    map<int, int>::iterator it = x_coord.begin();
    for (int i = l ; i < m; i++){
    	map<int, int>::iterator s = y_coord.find(it->second);
    	//cout << "left: " << it->second << endl;
    	if (s != y_coord.end()){
    		y_left[s->first] = s->second;
    	}
    	x_left[it->first] = it->second;
    	it++;
    }
    for (int i = m; i < r; i++){
    	//cout << "right: " << it->second << endl;
    	map<int, int>::iterator s = y_coord.find(it->second);
    	if (s != y_coord.end()){
    		y_right[s->first] = s->second;
    	}
    	x_right[it->first] = it->second;
    	it++;
    }
    //cout << "size: " << x_left.size() << " " << x_right.size() << endl;
    //cout << endl;
		map<int, vector<int> >list_left = calculate(x_left, y_left, l, m);
		map<int, vector<int> >list_right = calculate(x_right, y_right, m, r);
		//cout << "test========" << list_left.size() << " " << list_right.size() << endl;
		// for (map<int, vector<int> >::iterator it = list_left.begin(); it != list_left.end(); it++){
	 //  	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
	 //  }
	 //  for (map<int, vector<int> >::iterator it = list_right.begin(); it != list_right.end(); it++){
	 //  	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
	 //  }
		return merge(list_left, list_right);
   //  for (map<int, vector<int> >::iterator it = list.begin(); it != list.end(); it++){
	  // 	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
	  // }
  }
	return list;
}

int main() {
	int number;
	map<int, vector<int> >list;
	map<int, int>x_coord;
	map<int, int>y_coord;
	cin >> number;
	for (int i = 0; i < number; i++){
		int station_id, x, y;
		cin >> station_id >> x >> y;
		x_coord[x] = station_id;
		y_coord[station_id] = y;
 	}
 	map<int, vector<int> >results = calculate(x_coord, y_coord, 0, number);
 	map<int, int>final;
 	for (map<int, vector<int> >::iterator it = results.begin(); it != results.end(); it++){
  	final[it->second[0]] = it->second[1];
  }
  for (map<int, int>::iterator it = final.begin(); it != final.end(); it++){
  	cout << it->first << " " << it->second << endl;
  }
	return 0;
 // 	cout << " " << endl;
 // 	// for (map<int, vector<int> >::iterator it = list.begin(); it != list.end(); it++){
 // 	// 	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
 // 	// }
}

// Aditional Test Code
  // for (map<int, vector<int> >::iterator it = y_left.begin(); it != y_left.end(); it++){
  // 	// Print y, x, station_id in order
  // 	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
  // }
  // cout << " " << endl;
  // for (map<int, vector<int> >::iterator it = y_right.begin(); it != y_right.end(); it++){
  // 	// Print y, x, station_id in order
  // 	cout << it->first << " " << it->second[0] << " " << it->second[1] << endl;
  // }

