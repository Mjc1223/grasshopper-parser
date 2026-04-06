#include "Tokenizer.h"
#include "LinkedList.h"
#include <fstream>
#include <vector>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


bool processText(istream& is, Deque& v, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	//double darg1, darg2;
	int iarg1;
	int val;
	Tokenizer tkn;
	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);

		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processText(fin, v, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}

		if (command == "eat")
		{
			if (!tkn.readWord(arg1)) {
				cout << "Missing item (seed , leaf, or grass)" << endl; continue;
			}
			if (arg1 == "seed") {
				cout << "Attempting to eat a seed of size 1" << endl; v.push_front(1);  continue;
			}
			if (arg1 == "leaf") {
				cout << "Attempting to eat a leaf of size 2" << endl; v.push_front(2);  continue;
			}
			if (arg1 == "grass") {
				cout << "Attempting to eat grass of size 5" << endl; v.push_front(5); continue;
			}
			cout << "Attempting to eat an unkown item. Expected seed, leaf, or grass" << endl; continue;
		}

		if (command == "excrete")
		{
			cout << "Removing first item consumed by grasshopper" << endl;
			if (v.pop_back(val))
			{
				if (val == 1) { cout << "Removed a seed" << endl; }
			}
			{
				if (val == 2) { cout << "Removed a leaf" << endl; }
			}
			{
				if (val == 5) { cout << "Removed grass" << endl; }
			}
						

			continue;
		}

		if (command == "vomit")
		{
			cout << "Removing last item consumed by grasshopper" << endl;
			if (v.pop_front(val))
			{
				if (val == 1) { cout << "Removed a seed" << endl; }
			}
			{
				if (val == 2) { cout << "Removed a leaf" << endl; }
			}
			{
				if (val == 5) { cout << "Removed grass" << endl; }
			}
			continue;
		}

		if (command == "clear")
		{
			cout << "clearing data" << endl;
			v.clear();

			continue;
		}

		if (command == "status")
		{
			cout << "Displaying status" << endl;

			continue;
		}

		if (command == "display")
		{
			cout << "Displaying data" << endl;
			v.display(cout);

			continue;
		}

		cout << "Unexpected input" << endl;
	}
}

/*
int main()
{
	Deque d;
	int val;

	d.push_front(2); // eat
	d.push_front(4);
	d.display(cout);
	// d.pop_front(val); // vomit
	// cout << val << endl;
	// d.display(cout);
	// d.push_front(5);
	// d.display(cout);
	// d.pop_back(val); // excrete
	// cout << val << endl;

	// or vomit has to become
	// d.peek_front(val);
	// d.pop_front();
	// cout << val << endl;

	// and excrete becomes
	// d.peek_back(val);
	// d.pop_back();
	// cout << val << endl;

	return 0;
}
*/
int main()
{
	Deque ll;
	processText(cin, ll);




}