#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 


using namespace std;

class MyVector
{
private:
	struct Contact
	{
		string name;
		string phone;
		Contact *next;
	};
	Contact *head;
	Contact *tail;
	int list_size;

public:

	MyVector() // default constructor
	{
		list_size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~MyVector();

	void push_back(string name, string phone)
	{
		Contact *newNode;
		newNode = new Contact;
		if (newNode == nullptr)
		{
			return;
		}
		newNode->name = name;
		newNode->phone = phone;
		newNode->next = nullptr;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode; //????
			tail = newNode; // ?????

		}
		list_size++;
	}

	void remove(string name, string phone)
	{
		Contact *nodePtr;
		Contact *preNode;
		nodePtr = nullptr;
		preNode = nullptr;

		if (head == nullptr)
		{
			return;
		}
		if (head->name == name || head->phone == phone) //if the fist node is the one
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
			if (head == nullptr)
			{
				tail = nullptr;
			}
		}
		else
		{
			nodePtr = head;
			while (nodePtr != nullptr
				&& (nodePtr->name != name && nodePtr->phone != phone))
			{
				preNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr->next != nullptr)
			{
				preNode->next = nodePtr->next;
				delete nodePtr;
				if (preNode->next == nullptr)
				{
					tail = preNode;
				}
			}
		}
	}

	string get(string name) // check later
	{
		Contact *searchPtr;
		searchPtr = head;

		while (searchPtr != nullptr && searchPtr->name != name)
		{
			searchPtr = searchPtr->next;
		}
		if (searchPtr != nullptr)
		{
			return searchPtr->phone;
		}
		else //searchPtr ==nullptr
		{
			return "NOT FOUND.";
		}
	}

	void clear()
	{
		Contact *clearPtr;
		Contact *nextPtr;
		clearPtr = head;

		while (clearPtr != nullptr)
		{
			nextPtr = clearPtr->next;
			delete clearPtr;
			clearPtr = nextPtr;

		}
		head = nullptr;
		tail = nullptr;
		list_size = 0;
	}

	int size()
	{
		return list_size;
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

