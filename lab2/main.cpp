#include <iostream>
#include <ctime>
#include "FunctionHeaders.h"
using namespace std;
	void Algoritms::TimeMeasurement(clock_t start)
	{
		clock_t end = clock();
		float secs = float(end - start) / CLOCKS_PER_SEC;
	}
	void Algoritms::BinarySearch(int ClassArray[], int &FindNum, int LeftBorder, int RightBorder)
	{
		int middle = 0;
		bool flag = 0;
		while ((LeftBorder <= RightBorder) && (flag != 1)) {
			middle = (LeftBorder + RightBorder) / 2;	
			if (ClassArray[middle] == FindNum) flag = 1;
			if (ClassArray[middle] > FindNum) RightBorder = middle - 1;
			else LeftBorder = middle + 1;
		}
		FindNum = middle;
	}
	void Algoritms::BogoSort(int ClassArray[], int SizeArray)
	{
		int MovableValue;
		int i = 0;
		while (i < SizeArray - 1)
		{
			if (ClassArray[i + 1] < ClassArray[i])
			{
				MovableValue = ClassArray[i];
				ClassArray[i] = ClassArray[i + 1];
				ClassArray[i + 1] = MovableValue;
				i = 0;
			}
			else i++;
		}
		for (int i = 0; i < SizeArray; ++i) cout << ClassArray[i] << " ";
		cout << endl;
	}
	void Algoritms::QuickSort(int ClassArray[], int ArraySize)
	{
		int i = 0, j = ArraySize - 1;
		int middle = ClassArray[ArraySize / 2];
		clock_t begin = clock();
		do
		{
			while (ClassArray[i] < middle) i++;
			while (ClassArray[j] > middle) j--;
			if (i <= j)
			{
				int temp = ClassArray[i];
				ClassArray[i] = ClassArray[j];
				ClassArray[j] = temp;
				i++;
				j--;
			}
		} while (i <= j);
		if (j > 0) QuickSort(ClassArray, j + 1);
		if (i < ArraySize) QuickSort(&ClassArray[i], ArraySize - i);
	}
	void Algoritms::CountingSort(char ClassArray[], int const ArraySize)
	{
		int max = 0, min = (int)ClassArray[0];
		for (int i = 0; i < ArraySize; ++i)
		{
			if ((int)ClassArray[i] > max) max = (int)ClassArray[i];
			if ((int)ClassArray[i] < min) min = (int)ClassArray[i];
		}
		int size = (max - min) + 1;
		for (int i = 0; i < (max - min); ++i) if ((int)ClassArray[i] < 0) size--;
		int* SupportingArray = new int[max];
		for (int i = 0; i <= max; ++i) SupportingArray[i] = 0;
		for (int i = 0; i < size; ++i) SupportingArray[(int)ClassArray[i]]++;
		int temp = 0;
		for (int i = 0; i <= max; ++i)
		{
			if (SupportingArray[i] != 0)
			{
				ClassArray[temp] = (char)i;
				temp++;
			}
		}
		for (int i = 0; i < ArraySize; ++i) cout << ClassArray[i] << " ";
		cout << endl;
	}
	void Algoritms::BubbleSort(int SizeArray, int ClassArray[])
	{
		clock_t begin = clock();
		for (int i = 1; i < SizeArray; ++i)
		{
			for (int j = 0; j < SizeArray - i; j++)
			{
				if (ClassArray[j] > ClassArray[j + 1])
				{
					int temp = ClassArray[j];
					ClassArray[j] = ClassArray[j + 1];
					ClassArray[j + 1] = temp;
				}
			}
		}
		TimeMeasurement(begin);
		for (int i = 0; i < SizeArray; ++i) cout << ClassArray[i] << " ";
		cout << endl;
	}
int main()
{
	Algoritms code;
	int const size = 10;
	int ArrayForBinarySearch[size];
	int FindNum = rand() % size;
	for (int i = 0; i < size; ++i) ArrayForBinarySearch[i] = i;
	code.BinarySearch(ArrayForBinarySearch, FindNum, 0, size);
	int RandArray[size];
	int RandArray_2[size];
	srand(time(0));
	cout << "Start array: ";
	for (int i = 0; i < size; ++i)
	{
		RandArray[i] = rand() % 100;
		RandArray_2[i] = RandArray[i];
		cout << RandArray[i] << " ";
	}
	cout << endl;
	cout << "BBS: ";
	code.BubbleSort(size, RandArray);
	cout << "BS: ";
	code.BogoSort(RandArray, size);
	cout << "QS: ";

	clock_t begin = clock();
	code.QuickSort(RandArray_2, size);
	code.TimeMeasurement(begin);
	for (int i = 0; i < size; ++i) cout << RandArray_2[i] << " ";
	cout << endl;

	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char ArrayOfAlphabet[size];
	int index;
	cout << "Start array for char: ";
	for (int i = 0; i < size; ++i)
	{
		index = rand() % 26;
		ArrayOfAlphabet[i] = alphabet[index];
		cout << ArrayOfAlphabet[i] << " ";
	}
	cout << endl <<  "CS: ";
	code.CountingSort(ArrayOfAlphabet, size);
	return 0;
}