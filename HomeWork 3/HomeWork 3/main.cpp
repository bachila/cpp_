#include <iostream>
#include <string>
using namespace std;

/*
Написать класс для эффективной работы со строками, позволяющий форматировать и сравнивать строки, хранить в строках числовые значения и извлекать их. Для этого необходимо реализовать:
• перегруженные операции присваивания и конкатенации; -
• ввод/вывод строки;
• операции сравнения и приведения типов;
• преобразование в число любого типа;
• поиска символов и подстрок.
• обращение к элементам строки по индексу.
Весь функционал должен быть реализован в соответствии с хорошими практиками и необходимыми проверками.
Написать программу, демонстрирующую работу с этим классом. Программа должна содержать меню, позволяющее осуществить проверку всех методов класса.
*/

class String
{
	unsigned size = 0;
	char* str = nullptr;
public:
	String()
	{ };

	String(const char* str_) : size(strlen(str_) + 1), str(new char[size])
	{

		strcpy_s(str, size, str_);
	}

	String(const String& oldString) : size(oldString.size)
	{
		str = new char[size];
		strcpy_s(str, size, oldString.str);
	}

	void operator= (const String& oldString)
	{
		if (&oldString != this)
		{
			size = oldString.size;
			str = new char[size];
			strcpy_s(str, size, oldString.str);
		}
		cout << "line has been created" << endl;
	}


	String operator+ (const String& oldString)
	{
		String tempString;
		tempString.size = size + oldString.size - 1;
		tempString.str = new char[tempString.size];
		strcpy_s(tempString.str, size, str);
		strcat_s(tempString.str, tempString.size, oldString.str);
		return tempString;
	}

	~String()
	{
		if (str)
			delete[] str;
		str = nullptr;
	}

	char* get_str() const
	{
		return str;
	}

	friend istream& operator>> (istream& is, String& str);
	unsigned get_size() const
	{
		return size;
	}

	char* get_str()
	{
		return str;
	}

	void operator+= (String& string)
	{
		if (str || string.str)
		{

			if (!str)
			{
				size = size + string.size;
				str = new char[size];
				strcpy_s(str, size, string.str);
				return;
			}


			if (!string.str)
				return;

			String temp;
			temp.size = size + string.size - 1;
			temp.str = new char[temp.size];
			strcpy_s(temp.str, size, str);
			strcat_s(temp.str, temp.size, string.str);
			delete[] str;
			size = temp.size;
			str = new char[size];
			strcpy_s(str, size, temp.str);
		}
	}

	char& operator[](const unsigned index) const
	{
		if (index >= 0 && index < size - 1)
		{
			return str[index];
		}
	}

	int StrToInt()
	{
		int temp = atoi(str);
		return temp;
	}

	double StrToDouble()
	{
		double temp = atof(str);
		return temp;
	}

	void SearchSymbol(const char symbol) const
	{
		int forcount = 0;
		cout << "Symbol \"" << symbol << "\" position: ";
		for (unsigned i = 0; i < size - 1; i++)
		{
			if (str[i] == symbol)
			{
				cout << i << " ";
				++forcount;
			}
		}
		if (forcount == 0)
			cout << "this character is not in line";
		cout << endl;
	}

	void SearchSubstring(char* substring) const
	{
		int startIndex;
		char* p = strstr(str, substring);
		if (p)
		{
			startIndex = p - str;
			cout << "substring " << substring << " are in line" << endl;
			cout << "substring " << substring << " start index = " << startIndex << endl;
		}
		else
			cout << "substring " << substring << " is not in line" << endl;
	}

};

ostream& operator<< (ostream& os, const String& str)
{
	os << str.get_str();
	return os;
}

istream& operator>> (istream& is, String& str)
{
	char tempStr[256];
	is >> tempStr;
	str.size = strlen(tempStr) + 1;
	if (str.str)
		delete[] str.str;
	str.str = new char[str.size];
	strcpy_s(str.str, str.size, tempStr);
	return is;
}

bool operator== (const String& str1, const String& str2)
{
	if (str1.get_size() != str2.get_size())
		return false;
	return !strcmp(str1.get_str(), str2.get_str());;
}


int main()
{
	setlocale(LC_ALL, "");

	unsigned userNum;
	unsigned sizeString = 3;
	String* str = new String[sizeString];
	cout << "Введите значения для строк" << endl;
	for (unsigned i = 0; i < sizeString; i++)
	{
		cout << "Введите значение для " << i << " строки ";
		cin >> str[i];
	}
	do
	{
		cout << "\n\nВыберите действиет\n1)Ввести новое значение для строк\n2)Вывести строки" << endl;
		cout << "3)Сравнить строки\n4)Преобразовать строку в double\n5)Преобразовать строку в Int" << endl;
		cout << "6)Поиск символа в строке\n7)Поиск подстроки в строке\n8)Вывести символ из строки" << endl;
		cout << "9)Конкатенация строк" << endl;
		cout << "0)Выход\nВаш выбор: ";
		cin >> userNum;
		cout << endl;
		switch (userNum)
		{
		case 1:
		{
			unsigned numString;
			cout << "Для какой строки нужно поменять значение: ";
			cin >> numString;
				if (numString < sizeString)
				{
					cout << "Введите значение" << endl;
					cin >> str[numString];
				}
			break;
		}
		case 2:
		{
			for (unsigned i = 0; i < sizeString; i++)
				cout << i << " строка: " << str[i] << endl;
			break;
		}	
		case 3:
		{
			unsigned lStringComparison, rStringComparison;
			cout << "Какие строки нужно сравнить?\n";
			cout << "Первоя строка №: ";
			cin >> lStringComparison;
			cout << "Вторая строка №: ";
			cin >> rStringComparison;
			if (lStringComparison < sizeString && rStringComparison << sizeString)
			{
				if (str[lStringComparison] == str[rStringComparison])
					cout << "Равны" << endl;
				else
					cout << "Не равны" << endl;
			}
			else
				cout << "Введите корректный индекс" << endl;
			break;
		}		
		case 4:
		{
			unsigned num;
			cout << "Какую строку нужно преобразовать в double: ";
			cin >> num;
			if (num < sizeString)
			{
				double numOfLine = str[num].StrToDouble();
				if (numOfLine != NULL)
					cout << numOfLine << endl;
				else
					cout << "В строке нет числа для преобразования" << endl;

			}
			else
				cout << "Введите корректный индекс" << endl;
			break;
		}	
		case 5:
		{
			unsigned num;
			cout << "Какую строку нужно преобразовать в int: ";
			cin >> num;
			if (num < sizeString)
			{
				int numOfLine = str[num].StrToInt();
				if (numOfLine != NULL)
					cout << numOfLine << endl;
				else
					cout << "В строке нет числа для преобразования" << endl;
			}
			else
				cout << "Введите корректный индекс" << endl;
			break;
		}
		case 6:
		{
			unsigned num;
			char searchChar;
			cout << "В какой строке нужно искать символ: ";
			cin >> num;
			cout << "Какой символ нужно искать: ";
			cin >> searchChar;
			if (num < sizeString)
				str[num].SearchSymbol(searchChar);
			break;
		}
		case 7:
		{
			unsigned num;
			char searchChar[256];
			cout << "В какой строке нужно искать символ: ";
			cin >> num;
			cout << "Какой символ нужно искать: ";
			cin >> searchChar;
			if (num < sizeString)
				str[num].SearchSubstring(searchChar);
			break;
		}
		case 8:
		{
			unsigned numString;
			unsigned numLetter;
			cout << "Введите номер строки: ";
			cin >> numString;
			cout << "Введите номер символа";
			cin >> numLetter;
			if (numString < sizeString && numLetter < str[numString].get_size())
				cout << "Символ = " << str[numString][numLetter] << endl;
			break;
		}
		case 9:
		{
			unsigned numStr;
			unsigned numSecStr;
			cout << "К какой строке нужно добавить строку: ";
			cin >> numStr;
			cout << "Какую строку нужно добавить";
			cin >> numSecStr;
			if (numStr < sizeString && numSecStr < sizeString)
			{
				str[numStr] += str[numSecStr];
				cout << "Новая строка: " << str[numStr];
			}
			else
				cout << "Вы ввели не корректные данные" << endl;
			break;
		}
		default:
			break;
		}


	} while (userNum);
	return 0;
}