#pragma once
#include <iostream>
using namespace std;


#define NUM 5

int GetProductOfMedianValues(void);

class MyArray
{
public:
	int* array;
	unsigned int size;

	MyArray(unsigned int _size, int * _address)
	{
		array = new int[_size];
		size = _size;
		if (array)
			memcpy(array, _address, size *(sizeof(int)));
	}


	~MyArray() {
		delete[] array;
	}

	void sort_by_shift(const MyArray& dt);


	friend ostream& operator<<(ostream& os, const MyArray& dt);

	int GetMedianValueUnderMainDiag(int RowNumber)
	{
		int result = 0;

		if (RowNumber == 0)
			return result;

		for (int i = 0; i < RowNumber; i++)
		{
			result += array[i];
		}
		result = result / RowNumber;
		return result;
	}


	void MergeSort(int A[], int p, int r);
	void Merge(int A[], int p, int q, int r);

	void Sort()
	{
		MergeSort(array, 0, NUM - 1);
	}
};


