#include <iostream>
using namespace std;


//class stack {
//	enum { EMPTY = -1 };
//	char *s;
//	int max_len;
//	int top;
//public:
//	stack() {
//		s = new char[100];
//		max_len = 100;
//		top = EMPTY; // Стек пуст. 
//	}
//	stack(int size) {
//		s = new char[size]; max_len = size;
//		top = EMPTY;
//	}
//	stack(const char a[], int len) { // Инициализация массивом. 
//		max_len = len;
//		s = new char[max_len];
//		for (int i = 0; i < max_len; i++) s[i] = a[i];
//		top = max_len - 1;
//	}
//	stack(const stack & a) {	// Инициализация стеком. 
//		s = new char[a.max_len];
//		max_len = a.max_len; top = a.top;
//		for (int i = 0; i < max_len; i++) s[i] = a.s[i];
//	}
//	~stack() { delete s; }
//	void reset() { top = EMPTY; }	// Сброс стека в состояние ПУСТ. 
//	void push(char c) { s[++top] = c; }	// Занесение в стек. 
//	char pop() { return (s[top--]); } // Извлечение из стека. 
//	char top_show() const { return (s[top]); }
//	/* Возвращает элемент из стека, фактически не извлекая его. Модификатор const гарантирует, что эта функция не будет менять данные-члены объектов типа stack */
//	int empty() const { return (top == EMPTY); }
//	// Проверяет, пуст ли стек. Возвращает 
//	// 1, если стек пуст, 0 - если не пуст. 
//	int full() const { return (top == max_len - 1); }
//	// Проверяет, есть ли в стеке еще место. 
//};

template <typename T>
class Array
{
	T* arr = nullptr;
	unsigned size = 0;
	unsigned curr = 0;
public:
	Array()
	{
		if (curr <= size)
		{
			arr = new T[2];
			size += 2;
		}
	}
	
	void operator= (const T& d)
	{
		if (curr < size)
		{
			arr[curr] = d;
			++curr;
		}
		else
		{
			T* tempArr = new T[size];
			for (unsigned i = 0; i < size; i++)
				tempArr[i] = arr[i];
			delete[] arr;
			arr = new T[size + 2];
			for (unsigned i = 0; i < size; i++)
				arr[i] = tempArr[i];
			delete[] tempArr;
			size += 2;
			arr[curr] = d;
			++curr;
		}
	}

	void PrintArr()
	{
		for (int i = 0; i < curr; i++)
			cout << " " << arr[i] << " ";
		cout << endl;
	}
};

int main()
{
	Array<int>test;
	test = 2;
	test.PrintArr();
	test = 3;
	test.PrintArr();
	test = 4;
	test.PrintArr();
	test = 5;
	test.PrintArr();
	test = 6;
		test.PrintArr();

	return 0;
}