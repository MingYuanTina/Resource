#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

// Basic Linked Structure
struct node {
	int data;
	node *next;
}*start;

// Class Interface
class single_list {
public:
	node* create_node(int);
	void insert_begin();
	void insert_pos();
	void insert_last();
	void delete_pos();
	void sort();
	void search();
	void update();
	void reverse();
	void display();
	single_list(){
		start = NULL;
	}
};

int main(){
	return 0;
	int choice, nodes, element, position, i;
	single_list sl;
	start = NULL;
}