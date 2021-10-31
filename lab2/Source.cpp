#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include "Header.h"
#include <typeinfo>
using namespace std;

	void Algoritms::BinarySearch(int ClassArray[], int &FindNum, int LeftBorder, int RightBorder)
	{
		int middle = 0;
		bool flag = 0;
		clock_t begin = clock();
		while ((LeftBorder <= RightBorder) && (flag != 1)) {
			middle = (LeftBorder + RightBorder) / 2;	
			if (ClassArray[middle] == FindNum) flag = 1;
			if (ClassArray[middle] > FindNum) RightBorder = middle - 1;
			else LeftBorder = middle + 1;
		}
		clock_t end = clock();
		float secs = float(end-begin) / CLOCKS_PER_SEC;
		cout << "BinarySearch: " << setprecision(10) << secs << endl;
		FindNum = middle;
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
		clock_t end = clock();
		float secs = float(end-begin) / CLOCKS_PER_SEC;
		cout << "BubbleSort: " << setprecision(10) << secs << endl;
	}
	void Algoritms::BogoSort(int ClassArray[], int SizeArray)
	{
		int MovableValue;
		int i = 0;
		clock_t begin = clock();
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
		clock_t end = clock();
		float secs = float(end - begin) / CLOCKS_PER_SEC;
		cout << "BogoSort: " << setprecision(10) << secs << endl;
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
		clock_t begin = clock();
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
		//for (int i = 0; i <= max; ++i) cout << i << "." << SupportingArray[i] << endl;
		int temp = 0;
		for (int i = 0; i <= max; ++i)
		{
			if (SupportingArray[i] != 0)
			{
				ClassArray[temp] = (char)i;
				temp++;
			}
		}
		clock_t end = clock();
		float secs = float(end - begin) / CLOCKS_PER_SEC;
		cout << "CountingSort: " << setprecision(10) << secs;
	}
int main()
{
	setlocale(LC_ALL, "Rus");
	int const size = 10;
	int RandArray[size];
	srand(time(0));
	for (int i = 0; i < size; ++i) RandArray[i] = rand() % 100;
	Algoritms code;
	int Num = rand() % 100;
	code.BinarySearch(RandArray, Num, 0, size);
	code.BubbleSort(size, RandArray);
	code.BogoSort(RandArray, size);
	clock_t begin = clock();
	code.QuickSort(RandArray, size);
	clock_t end = clock();
	float secs = float(end - begin) / CLOCKS_PER_SEC;
	cout << "Quick sort: " << setprecision(10) << secs << endl;
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char ArrayOfAlphabet[size];
	int index;
	for (int i = 0; i < size; ++i)
	{
		index = rand() % 26;
		ArrayOfAlphabet[i] = alphabet[index];
	}
	code.CountingSort(ArrayOfAlphabet, size);
	return 0;
}
/*{ '3','5','9','2','7' }
int const size = 13;
int array[size] = { 1,2,3,8,5,4,7,8,9,10,11,12,13 };
int array_2[size];
srand(time(0));
for (int i = 0; i < size; ++i) array_2[i] = rand() % 10;
int Num = 5;
char array_3[size] = { 'a','g','m','b','h','n','c','i','o','d','j','p','e','k','q','f','l','r','s','x','t','y','u','z','w','v' };
code.CountingSort(array_3, size);
code.BinarySearch(array, Num, 0, size);
code.BubbleSort(size, array_2);
code.BogoSort(array_2, size);
for (int i = 0; i < size; ++i) cout << array_2[i];*/