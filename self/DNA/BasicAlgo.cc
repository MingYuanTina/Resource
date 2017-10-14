#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Parent Class: Search
class Search {
protected:
	vector<int>list;
	int iteration;

public:
	int get_iteration(){
		return this->iteration;
	}

	virtual int search(int val) = 0;
};


// Derived Class: Binary Search
class BinarySearch : public Search {
public:
	BinarySearch(vector<int>l){
		this->list = l;
		this->iteration = 0;
	}

	int search(int val){
		int l = 0;
		int r = list.size();
		while (l <= r){
			int m = (l + r) / 2;
			if (list[m] == val){
				return m;
			} else if (list[m] < val){
				l = m + 1;
			} else {
				r = m - 1;
			}
			this->iteration += 1;
		}
		return -1;
	}
};


// Derived Class: Linear Search
class LinearSearch : public Search {
public:
	LinearSearch(vector<int>l){
		this->list = l;
		this->iteration = 0;
	}

	int search(int val){
		for (int i = 0; i < list.size(); i++){
			if (list[i] == val){
				return i;
			}
			this->iteration += 1;
		}
		return -1;
	}
};

int main(){
	int arr[] = {1,3,5,7,9};
	vector<int>l (arr, arr + sizeof(arr) / sizeof(int));
	Search *bs = new BinarySearch(l);
	Search *ls = new LinearSearch(l);
	cout << bs->search(9) << " " << bs->get_iteration() << endl;
	cout << ls->search(9) << " " << ls->get_iteration() << endl;
	return 0;
}