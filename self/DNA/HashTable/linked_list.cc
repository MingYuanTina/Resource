/* A linked list is a data structure that represents a sequence of nodes 
	*	In a singly linked list, each node points to the next node in the linked list
	* A doublyly linked list gives each node pointers to both the next node and previous node
	* Linked list does not provide constant time access to a particular "index"
	* But it allows to add and remove times from the beginning of the list in a constant time
	* Application: Stack, Graph, Hash Table with Chaining etc. 
	* The implementation of linked_list is referred to : 
	* https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
	*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class Linked_List {
private:
	Node *head;
	Node *tail;
public:
	/*
		* linked list constructor
		*/
	Linked_List(){
		head = NULL;
		tail = NULL;
	}

	/*
		* linked list deconstructor
		*/
	~Linked_List(){
		while (head != NULL){
			Node *temp = head;
			head = temp->next;
			delete temp;
		}
	}

	/*
		* Travers the entire linked list
		*/
	void print_list(){
		Node *temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
		delete temp;
	}

	/*
		* Insert the value to the start
		*/
	void insert_start(int val){
		Node *temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	/*
		* Insert the value at certain position
		*/
	void insert_val_at_pos(int val, int pos){
		Node *pre = new Node;
		Node *cur = new Node;
		cur = head;
		for (int i = 0; i < pos; i++){
			pre = cur;
			cur = cur->next;
		}
		Node *temp = new Node;
		temp->data = val;
		pre->next = temp;
		temp->next = cur;
	}

	/* 
		* Delete the value of the start
		*/
	void delete_start(){
		Node *temp = head;
		head = temp->next;
		delete temp;
	}

	/*
		* Delete the value at the given position
		*/
	void delete_val_at_pos(int val, int pos){
		Node *pre = new Node;
		Node *cur = new Node;
		cur = head;
		for (int i = 0; i < pos; i++){
			pre = cur;
			cur = cur->next;
		}
		Node *temp = pre;
		pre = pre->next;
		delete temp;
	}

};

int main() {
	cout << "This is implementation for linked list" << endl;
	Linked_List *list = new Linked_List();
	for (int i = 0; i < 10; i++){
		list->insert_start(i);
	}
	list->print_list();
	return 0;
}