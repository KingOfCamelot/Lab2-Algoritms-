#ifndef ADD_H
#define ADD_H
#include <iostream>
class Algoritms
{
public:
	void BinarySearch(int ClassArray[], int& FindNum, int LeftBorder, int RightBorder);
	void BogoSort(int ClassArray[], int SizeArray);
	void CountingSort(char ClassArray[], int ArraySize);
	void QuickSort(int ClassArray[], int ArraySize);
	void BubbleSort(int SizeArray, int ClassArray[]);
};
#endif