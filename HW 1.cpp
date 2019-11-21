#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <ctype.h>

using namespace std;

class MyVector
{
	struct Contact
	{
		string name;
		string phone;
	};

private:
	Contact * list;
	int max_size;
	int list_size;

public:

	MyVector() // default constructor
	{
		max_size = 10;
		list_size = -1;

		//int* list = new Contact[];
		list = new Contact[max_size];
	}

	~MyVector()
	{
		if (list != nullptr)
		{
			delete list;
			list = nullptr;
		}
	}

	void push_back(string name, string phone)
	{
		if (list_size == -1)
		{
			list_size = 0;
		}
		if (list_size >= max_size)
		{
			int tmp_max_size = 2 * max_size;
			Contact *tmpList = new Contact[tmp_max_size];
			for (int idx = 0; idx < list_size; idx++)
			{
				tmpList[idx].name = list[idx].name;
				tmpList[idx].phone = list[idx].phone;
			}
			max_size = tmp_max_size;
			delete list;
			list = tmpList;
		}

		list[list_size].name = name;
		list[list_size].phone = phone;
		list_size++;

	}


	void remove(string name, string phone)
	{
		int foundIdx = -1;
		for (int idx = 0; idx < list_size; idx++)
		{
			if (name == list[idx].name || phone == list[idx].phone)
			{
				foundIdx = idx;
				break;
			}
		}
		if (foundIdx >= 0)
		{
			for (int idx = foundIdx + 1; idx < list_size; idx++)
			{
				list[idx - 1].name = list[idx].name;
				list[idx - 1].phone = list[idx].phone;
			}
			list_size--;
			list[list_size].name = "";
			list[list_size].phone = "";
		}
	}

	string get(string name)
	{
		int foundIdx = -1;
		for (int idx = 0; idx < list_size; idx++)
		{
			if (name == list[idx].name)
			{
				foundIdx = idx;
				break;
			}
		}
		if (foundIdx >= 0)
		{
			return list[foundIdx].phone;
		}
		else
		{
			return "NOT FOUND.";
		}
	}

	void clear()
	{
		for (int idx = 0; idx < list_size; idx++)
		{
			list[idx].name = "";
			list[idx].phone = "";
		}
		list_size = -1;
	}
};

int main()
{
	static const string CHOICES = "ACFQR";
	MyVector* addressListPtr = new MyVector();

	string menuChoiceStr = " ";
	char menuChoiceChr = ' ';
	string inputName, inputPhone;

	while (menuChoiceChr != 'Q') //Q1
	{
		cout << "(A)dd Contact" << endl;
		cout << "(C)lear Contacts" << endl;
		cout << "(F)ind Contact" << endl;
		cout << "(Q)uit" << endl;
		cout << "(R)emove Contact" << endl;

		menuChoiceStr = " ";
		menuChoiceChr = ' ';
		while (CHOICES.find(menuChoiceChr) == string::npos)//Q2
		{
			cout << "[ACFQR]: ";
			cin >> menuChoiceStr;
			menuChoiceChr = menuChoiceStr[0];
			menuChoiceChr = toupper(menuChoiceChr);
		}
		switch (menuChoiceChr) //Q3
		{
		case 'A':
			cout << "Enter name: ";
			cin >> inputName;
			cout << "Enter phone: ";
			cin >> inputPhone;
			addressListPtr->push_back(inputName, inputPhone);
			break;

		case 'C':
			addressListPtr->clear();
			break;

		case 'F':
			cout << "Enter name: ";
			cin >> inputName;
			inputPhone = addressListPtr->get(inputName);//Q4
			cout << inputPhone << endl;
			break;

		case 'Q':
			break;

		case 'R':
			cout << "Enter the name or number of a contact to remove: ";
			cin >> inputName;
			addressListPtr->remove(inputName, inputName);
			break;

		default:
			break;
		}
	}
}

