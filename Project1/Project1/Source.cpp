#include <iostream>
using namespace std;

template <typename T>
class Array
{
	unsigned _size = 0;
	T* _arr = nullptr;

public:

	explicit Array(const unsigned size) : _size(size), _arr(new T[_size])
	{
		for (unsigned i = 0; i < _size; i++)
			_arr[i] = 0;
	};
	Array() {};
	Array(const T* ar, const unsigned size) : _size(size), _arr(new T[_size])
	{
		for (unsigned i = 0; i < _size; i++)
			_arr[i] = ar[i];
	}

	~Array()
	{
		if (_arr)
		{
			delete[] _arr;
		}
		_arr = nullptr;
	}

	Array(const Array& ar)
	{
		_size = ar._size;
		_arr = new T[_size];
		for (unsigned i = 0; i < _size; i++)
			_arr[i] = ar._arr[i];
	};

	const void operator= (const Array& ar)
	{
		if (&ar != this)
		{
			_size = ar._size;
			_arr = new T[_size];
			for (unsigned i = 0; i < _size; i++)
				_arr[i] = ar._arr[i];
		}
	};

	Array operator+ (const Array& ar)
	{
		unsigned newsize = _size + ar._size;
		Array<int> newarray(newsize);
		for (unsigned i = 0, j = 0; i < newsize; i++)
		{
			if (i < _size)
				newarray._arr[i] = _arr[i];
			else
			{
				newarray._arr[i] = ar._arr[j];
				j++;
			}
		}
		return newarray;
	};

	void Print()
	{
		for (unsigned i = 0; i < _size; i++)
			cout << _arr[i];
		cout << endl;
	};
};

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	Array<int> arr(a, 5);
	Array<int> arr1(6);
	Array<int> arr2 = arr + arr1;
	arr.Print();
	arr1.Print();
	arr2.Print();
	system("pause");
	return 0;
}