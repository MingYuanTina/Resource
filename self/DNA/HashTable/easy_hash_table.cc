// The following implementation is a fixed sized hash table
// Input constraint: key < table_size
#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 128;

class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}
	int getKey(){
		return key;
	}
	int getValue(){
		return value;
	}
};

class HashMap {
private:
	HashEntry **table;
public:
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++){
			table[i] = NULL;
		}
	}
	int get (int key) {
		int hash = key % TABLE_SIZE; // Value here is interchageable
		while (table[hash] != NULL && table[hash]->getKey() != key)
			// Hashing formula depends on the types of hashing implemented
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] == NULL)
			return -1;
		else
			return table[hash]->getValue();
	}
	void push (int key, int value){
		int hash = key % TABLE_SIZE;
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		// This impelementation didn't take the full size into consideration
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	~HashMap(){
		for (int i = 0; i < TABLE_SIZE; i++){
			if (table[i] != NULL)
				delete table[i];
		}
		delete table;
	}
};

int main(){
	cout << "This is hash-table implementation" << endl;
	HashMap* map = new HashMap();
	map->push(1,333);
	map->push(2,444);
	cout << "First value is " << map->get(1) << endl;
	cout << "Second value is " << map->get(2) << endl;
	return 0;
}