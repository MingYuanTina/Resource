// Two Sum, Three Sum, Four Sum Question 
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

class Sum_To_Target {
private:
	vector<vector<int> >res;
	vector<int>list;
	int target;
public:
	Sum_To_Target(vector<int>l, int t){
		for (int i = 0; i < l.size(); i++){
			this->list.push_back(l[i]);
		}
		this->target = t;
	}

	// Two Sum function to returl all list that sum to target value
	// Runtime: O(nlogn)
	void two_sum() {
		sort(this->list.begin(), this->list.begin() + this->list.size());
		int i = 0, j = this->list.size() - 1;
		while (i < j){
			int sum = this->list[i] + this->list[j];
			if (sum > this->target){
				j--;
			} else if (sum < this->target){
				i++;
			} else {
				vector<int>temp;
				temp.push_back(this->list[i]);
				temp.push_back(this->list[j]);
				res.push_back(temp);
				i++;
				j--;
			}
		}
	}

	// Print function to print out list of numbers 
	void print_list(){
		cout << "list # sum up to target value: " << endl;
		for (int i = 0; i < res.size(); i++){
			cout << res[i][0] << " " << res[i][1] << endl;
		}
	}
};

int main() {
  int mylist[] = {6,5,4,3,2,1};
  vector<int>list(mylist, mylist + sizeof(mylist) / sizeof(int));	
  Sum_To_Target l(list, 10);
  l.two_sum();
  l.print_list();
	return 0;
}