#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Subscriber
{
public:
	Subscriber()
	{
		this->phoneNumber = "Default Number";
		this->surname = "Default Surname";
		this->name = "Default Name";
	}
	Subscriber(string phoneNumber, string surname, string name)
	{
		this->phoneNumber = phoneNumber;
		this->surname = surname;
		this->name = name;
	}
	~Subscriber()
	{
		delete this;
	}
	friend bool operator> (const Subscriber &left, const Subscriber &right)
	{
		return left.phoneNumber > right.phoneNumber;
	};
	friend bool operator> (const Subscriber &left, const Subscriber &right)
	{
		return left.surname > right.surname;
	};
	friend bool operator> (const Subscriber &left, const Subscriber &right)
	{
		return left.name > right.name;
	};
	friend bool operator< (const Subscriber &left, const Subscriber &right)
	{
		return left.phoneNumber < right.phoneNumber;
	};
	friend bool operator< (const Subscriber &left, const Subscriber &right)
	{
		return left.surname < right.surname;
	};
	friend bool operator< (const Subscriber &left, const Subscriber &right)
	{
		return left.name < right.name;
	};
	friend bool operator== (const Subscriber& left, const Subscriber& right);
	friend bool operator== (const Subscriber& left, const string& right);

private:
	string phoneNumber;
	string surname;
	string name;
};

bool operator== (const Subscriber& left, const Subscriber& right)
{
	return (left.phoneNumber == right.phoneNumber && left.surname == right.surname && left.name == right.name);
};

bool operator== (const Subscriber& left, const string& right)
{
	return (left.phoneNumber == right || left.surname == right || left.name == right);
};


int main()
{
	set <Subscriber> Subscriber_Set
	{
		Subscriber("+380956347984","Petrov","Sergey"),
		Subscriber("+380673596842","Samburov","Roman"),
		Subscriber("+380669845632","Kraynev","Igor"),
	};
	Subscriber sb;
	Subscriber sb1;
	sb == sb1;
	sb == "";
	auto it = Subscriber_Set.begin();
	string to_find = "Samburov";
	while (it != Subscriber_Set.end())
	{
		if (*it == to_find)
		{

		}
		it;
	}

	multiset <Subscriber> PhoneBookMultiSet;
	map <int, Subscriber> PhoneBookMap;
	multimap <int, Subscriber> PhoneBookMultiMap;

	string data = "";

	while (true)
	{
		cout << "For searching, please, enter the data" << endl;
		cin >> data;
		auto find_Result = find(Subscriber_Set.begin(), Subscriber_Set.end(), Subscriber_Set.rbegin());

		if (find_Result == Subscriber_Set.end())
		{
			cout << "String is NOT found" << endl;
		}
		else
		{
			cout << "String is found" << endl;
		}

	}

	return 0;
}
