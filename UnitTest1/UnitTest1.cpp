#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(QuickSort)
		{
			int const size = 5;
			int array[size] = { 3,4,1,5,2 };
			int array_2[size] = { 1,2,3,4,5 };
			Algoritms test;
			test.QuickSort(array, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(array_2[i], array[i]);
		}
		TEST_METHOD(BubbleSort)
		{
			int const size = 5;
			int array_2[size] = { 1,2,3,4,5 };
			int array[size] = { 3,4,1,5,2 };
			Algoritms test;
			test.BubbleSort(size,array);
			for (int i = 0; i < size; ++i) Assert::AreEqual(array_2[i], array[i]);
		}
		TEST_METHOD(BogoSort)
		{
			int const size = 5;
			int array_2[size] = { 1,2,3,4,5 };
			int array[size] = { 3,4,1,5,2 };
			Algoritms test;
			test.BogoSort(array, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(array_2[i], array[i]);
		}
		TEST_METHOD(CountingSort)
		{
			int const size = 26;
			char alphabet[size] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
			char array[size] = { 'a','g','m','b','h','n','c','i','o','d','j','p','e','k','q','f','l','r','s','x','t','y','u','z','w','v' };
			Algoritms test;
			test.CountingSort(array, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(alphabet[i], array[i]);
		}
		TEST_METHOD(BinarySearch)
		{
			int const size = 5;
			int array[size] = { 1,2,3,4,5 };
			Algoritms test;
			int Num = 3;
			test.BinarySearch(array, Num, 0, size);
			Assert::AreEqual(2, Num);
		}
	};
}
