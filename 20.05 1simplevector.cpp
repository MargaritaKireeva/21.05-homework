#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
//#include <functional>
using namespace std;
double eps = 1e-6;
template <typename T>
class SimpleVector {
private:
	int size;
	T *array;
	int maxSize;
	void allocate_memory()
	{
		if (size >= maxSize)
		{
			T *NewArray = new T[maxSize * 2];
			for (int i = 0; i < size; i++)
			{
				NewArray[i] = array[i];
			}
			array = NewArray;
		}
	}
public:
	SimpleVector(int maxSize) : maxSize(maxSize) {
		size = 0;
		array = new T[maxSize];
	}

	~SimpleVector() {
		delete[] array;
	}

	void push_back(const T newElement)
	{
		allocate_memory();
		array[size] = newElement;
		size++;
	}
	T find(T x)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i] == x)
				return i;
		}
		return -1;
	}

	int remove(T x)
	{
		if (find(x) != -1)
		{
			for (int i = find(x); i < size - 1; i++)
				array[i] = array[i + 1];
			return --size;
		}
		return size;
	}

	bool insert_after(T x, T y)
	{
		allocate_memory();
		if (find(y) != -1)
		{
			for (int i = size - 1; i >= find(y); i--)
				array[i + 1] = array[i];
			array[find(y) + 1] = x;
			size++;
			return true;
		}
		return false;
	}
	void insert_zeromin()
	{
		T min = array[0];
		int imin;
		for (int i = 0; i < size; i++)
			if (array[i] < min)
			{
				min = array[i];
				imin = i;
			}
		allocate_memory();
		for (int i = size - 1; i >= imin; i--)
			array[i + 1] = array[i];
		array[imin] = 0;
		size++;
		imin++;
		allocate_memory();
		for (int i = size - 1; i > imin; i--)
			array[i + 1] = array[i];
		array[imin + 1] = 0;
		size++;
	}
	void change()
	{
		T max = 0;
		int imax;
		for (int i = 0; i < size; i++)
			if (array[i] < 0 && abs(array[i]) > abs(max))
			{
				max = array[i];
				imax = i;
			}
		if (size % 2 == 0 || max == 0)
			cout << "Error" << endl;
		else array[size / 2] = max;
	}
	T top() { 
		return array[size - 1];

	}

	unsigned int sizeOF() { 
		return size;
	}
	bool empty() { 
		if (size == 0)
			return true;
		return false;
	}
	static bool isLower(T x, T y)  //№1 - статическая функция сравнения со сложным ключом
	{
		if (round(x) != round(y))
			return round(x) < round(y);
		return x + eps < y;
	}
	T& operator[] (const int index)
	{
		return array[index];
	}
};


int main() {
	SimpleVector <double> A(5);
	double a;
	for (int i = 0; i < 5; i++)

	{
		cin >> a;
		A.push_back(a);
	}
	vector<double> v1; //№2(а) sort
	int n = A.sizeOF();
	for (int i = 0; i < n; i++)
	{
		v1.push_back(A[i]);	
	}
	for (int i = 0; i < n; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < n; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;
	vector<double> v2; // №2(б) sort
	for (int i = 0; i < n; i++)
	{
		v2.push_back(A[i]);
	}
	sort(v2.begin(), v2.end(),&SimpleVector<double>::isLower);
	for (int i = 0; i < n; i++)
	{
		cout << v2[i] << ' ';
	}
	cout << endl;
	v1.clear();
	v2.clear();
	for (int i = 0; i < n; i++) //№2(а) stable_sort
	{
		v1.push_back(A[i]);
	}
	stable_sort(v1.begin(), v1.end());
	for (int i = 0; i < n; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; i++)//№2(б) stable_sort
	{
		v2.push_back(A[i]);
	}
	stable_sort(v2.begin(), v2.end(), &SimpleVector<double>::isLower);
	for (int i = 0; i < n; i++)
	{
		cout << v2[i] << ' ';
	}
	return 0;
}