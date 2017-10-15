#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
};

class BinaryTree {
private:
    Node *root;

public:
    BinaryTree(){
        root = NULL;
    }

    
};



int main() {
    BinaryTree b;
    b.Insert(5);
	return 0;
}