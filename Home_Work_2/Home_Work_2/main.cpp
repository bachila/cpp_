#include <iostream>
#include <string>
using namespace std;
#define Noresurse "No resource"

class Student  //Unique resource
{
	unsigned average;
	unsigned group;
	char* name;
	int sizename;
public:
	Student(Student&) = delete;
	void operator= (const Student&) = delete;

	Student(unsigned average_, unsigned group_, char* name_)
	{
		if (name_ && *name_)
		{
			average = average_;
			group = group_;
			sizename = strlen(name_) + 1;
			name = new char[sizename];
			strcpy_s(name, sizename, name_);
		}
		else
		{
			average = 0;
			group = 0;
			sizename = strlen("Unknown") + 1;
			name = "Unknown";
		}
	};

	~Student()
	{
		if (name)
			delete[] name;
		name = nullptr;
	};

	const char* get_name() const
	{
		if (name && *name)
		{
			return name;
		}
		return Noresurse;
	};
}; // End unique resource


class Car // Transfer
{
	unsigned age;
	unsigned price;
	unsigned size;
	char* name;
public:
	Car() {};
	Car(unsigned age_, unsigned price_, char* name_) : age(0), price(0), name(nullptr)
	{
		if (name_ && *name_)
		{
		age = age_;
		price = price_;
		size = strlen(name_) + 1;
		name = new char(size);
		strcpy_s(name, size, name_);
		}	

	};

	const void operator= (Car oldcar)
	{
			if (oldcar.name)
			{
				age = oldcar.age;
				price = oldcar.price;
				size = oldcar.size;
				name = new char[size];
				strcpy_s(name, size, oldcar.name);
				oldcar.age = oldcar.size = oldcar.price = NULL;
				oldcar.name = nullptr;
			}
	};


	const char* get_name() const
	{
		if (name && *name)
		{
			return name;
		}
		return Noresurse;
	};

	Car(Car& oldcar)
	{
			if (oldcar.name)
			{
				age = oldcar.age;
				price = oldcar.price;
				size = oldcar.size;
				name = new char[size];
				strcpy_s(name, size, oldcar.name);
				oldcar.age = oldcar.size = oldcar.price = NULL;
				oldcar.name = nullptr;
			}
	};

	~Car() 
	{
		if (name && *name)
			delete[] name;
		name = nullptr;
	};
}; // End transfer

class Phone //co-ownership
{
	char* name = nullptr;
	unsigned price;
	unsigned size;
	unsigned* count = nullptr;

public:
	Phone() 
	{ };
	Phone(char* name_, unsigned price_) : size(strlen(name_) + 1), price(price_)
	{
		if (name_ && *name_)
		{
			name = new char[size];
			strcpy_s(name, size, name_);
			count = new unsigned(1);
		}
	};

	~Phone()
	{
		--(*count);
		if (*count == 0 && name)
			delete[] name;
		name = nullptr;
	};

	Phone(Phone& oldphone) : price(oldphone.price), size(oldphone.size)
	{
		if (&oldphone != this)
		{
			count = oldphone.count;
			++(*count);
			name = oldphone.name;
		}
	};
	
	void operator= (Phone oldphone)
	{
			count = oldphone.count;
			++(*count);
			price = oldphone.price;
			size = oldphone.size;
			if (oldphone.name)
			{
				name = new char[size];
				strcpy_s(name, size, oldphone.name);
			}
			else
				name = "";
	};
	
	const char* get_name() const
	{
		if (name && *name)
			return name;
		else
			return Noresurse;

	};

}; //End co-ownership
template <typename T>
void WorkClass(T* workclass, T* workclass2);
int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned userNum;
	unsigned option;
	do
	{
		cout << "1)Create Unique resource\n2)Create Transfer resource\n3)Create co-ownership\n0)Exit\nYour choice: ";
		cin >> userNum;
		if (userNum == 0)
			break;
		switch (userNum)
		{
		case 1:
		{
			Student Nick(5, 3, "Nick");
			while (true)
			{
				cout << "1)Output value\n2)Create copy class\n3)Output copy value\n0)Exit\nYour choice: ";
				cin >> option;
				if (option == 0)
					break;
				switch (option)
				{
				case 1:
					cout << Nick.get_name() << endl;
					break;
				case 2:
					cout << "You can not create a copy\n";
					break;
				case 3:
					cout << "You can not output a copy\n";
					break;
				default:
					cout << "incorrect value" << endl;
					break;
				}
			}
		}
			break;
		case 2:
		{
			Car Bmw(2015, 20000, "725");
			Car Bmw2;
			WorkClass(&Bmw, &Bmw2);
		}
			break;
		case 3:
		{
			Phone Samsung("Galaxy", 500);
			Phone Samsung2;
			WorkClass(&Samsung, &Samsung2);
		}

		default:
			cout << "incorrect value" << endl;
			break;
		}
	} while (true);
	system("pause");
	return 0;
}

template <typename T>
void WorkClass(T* workclass, T* workclass2)
{
	unsigned option;
	while (true)
	{
		cout << "1)Output value\n2)Create copy class\n3)Output copy value\n0)Exit\nYour choice: ";
		cin >> option;
		if (option == 0)
			break;
		switch (option)
		{
		case 1:
			cout << workclass->get_name() << endl;
			break;
		case 2:
			if (workclass->get_name() != Noresurse)
			{
				*workclass2 = *workclass;
				cout << "copy is created" << endl;
			}
			else 
				cout << "copy was created" << endl;
			break;
		case 3:
			cout << workclass2->get_name() << endl;
		default:
			cout << "incorrect value" << endl;
			break;
		}
	}
}