//Student Name : Makael Calhoun
//Student NetID : mjc683
//Compiler Used : Visual Studios
//Program Description : This is the file for my main function file* /
#include "LinkedList.h"

Deque::~Deque()
{
	Node* tmp = first;

	while (tmp != nullptr)
	{
		first = first->next;

		delete tmp;

		tmp = first;

	}
	last = nullptr;
}
// probably want push_front to be a bool ...
// returns true when it works
// returns false when the push would be over capacity
bool Deque::push_front(int val)
{// need to check capacity
// if the current capacity + val > 11, then fail
// otherwise capacity = capacity + val;
	{
		if (capacity + val > 11)
		{
			cout << "fail" << endl;
		}
		else
		{
			capacity = capacity + val;
		}
			
	}
	Node* tmp = new Node(val);

	if (first == nullptr)
	{
		last = tmp;
	}
	else
	{
		first->prev = tmp;
	}
	tmp->next = first;
	first = tmp;

	return true;
}

void Deque::push_back(int val)
{

	Node* tmp = new Node(val);

	tmp->prev = last;

	if (first == nullptr)
	{
		first = tmp;
	}
	else
	{
		last->next = tmp;
	}

	last = tmp;
}

bool Deque::peek_front(int& val)
{
	if (first == nullptr) return false;

	val = first->val;

	return true;
}

bool Deque::peek_back(int& val)
{
	if (last == nullptr) return false;

	val = last->val;

	return true;
}

bool Deque::pop_front(int& val)
{
	Node* tmp = first;

	if (first == nullptr) return false;

	val = first->val;

	first = first->next;

	if (first == nullptr) last = nullptr;
	// also make certain to subtract value from capacity
	capacity -= val;

	delete tmp;

	return true;
}

bool Deque::pop_back(int& val)
{
	Node* tmp = last;

	if (last == nullptr) return false;

	val = last->val;

	last = last->prev;

	if (last == nullptr) first = nullptr;
	
	capacity -= val;



	delete tmp;

	return true;
}

void Deque::clear()
{
	Node* tmp = first;

	while (tmp != nullptr)
	{
		first = first->next;

		delete tmp;

		tmp = first;
	}

	last = nullptr;
	capacity = 0;
}


void Deque::display(ostream& os)
{
	Node* tmp = first;// set the current tmp node to the first

	while (tmp != nullptr)
	{
		os << tmp->val << endl;

		tmp = tmp->next;
	}

}

void Deque::status()
{
	if (capacity == 0)
	{
		cout << "starving" << endl;
	}
	else if (capacity == 11)
	{
		cout << "full" << endl;
	}
	else
	{
		cout << "not full" << endl;
	}
}

