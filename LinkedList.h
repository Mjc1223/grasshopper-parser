/*Student Name: Makael Calhoun
Student NetID: mjc683
Compiler Used: Visual Studios
Program Description:This is the methods for the DoublyLinked List*/
#pragma once
#include<string>
#include "node.h"
#include "Tokenizer.h"
using namespace std;

class Deque
{
private:
	Node* first;
	Node* last;
	int capacity;

public:
	Deque(): first(nullptr), last(nullptr), capacity(0) {}
	~Deque();

	bool push_front(int val); // do this first
	void push_back(int val);
	void display(ostream& os); // do this second
	bool peek_front(int& val);
	bool peek_back(int& val);
	bool pop_front(int& val);
	bool pop_back(int& val);
	void clear();
	void status();
	//bool pop_front(int& val);; 
	// or bool pop_front();
	// when coding .. it's the difference between val = front->data;
	
	
};

