// Reference: 
// https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
// Simple Version of Linked List Implementation

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int value;
	Node *next;
};

class LinkedList {
private:
 Node *head;
 Node *tail;
 
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
	}

	void Insert(int value){
		Node *temp = new Node;
		temp->value = value;
		temp->next = head;
		head = temp;
	}

	void Insert_At(int value, int pos){
		Node *temp = new Node;
		temp->value = value;
		Node *curr = head;

		for (int i = 0; i < pos - 1; i++){
			curr = curr->next;
		}

		Node *next = curr->next;
		curr->next = temp;
		temp->next = next;
	}

	void Delete(){
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void Delete_At(int pos){
		Node *curr = head;
		for (int i = 0; i < pos - 1; i++){
			curr = curr->next;
		}
		Node *next = curr->next;
		curr->next = next->next;
		delete next;
	}

	void Print(){
		Node *temp = head;
		while (temp){
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	void Reverse(){
		Node *curr = head;
		Node *next = NULL;
		Node *prev = NULL;
		while (curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

};

int main(){
	LinkedList l;
	l.Insert(4);
	l.Insert(3);
	l.Insert(2);
	l.Insert_At(5,2);
	l.Delete_At(2);
	l.Print();
	return 0;
}