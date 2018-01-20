#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertSort.h"
#include "BubbleSort.h"

void test_heapsort()
{
	std::vector<int> sortlist = { 1,5,3,100,3,2,5,6,7,8,19,10 };
	HeapSort<int> heapsort(10000);

	heapsort.init(sortlist);
	heapsort.print();
	std::cout << "---------------------" << std::endl;
	int a = 6;
	heapsort.add(a);
	heapsort.print();
	std::cout << "---------------------" << std::endl;
	a = 9;
	heapsort.add(a);
	heapsort.print();
	std::cout << "---------------------" << std::endl;
	heapsort.del(true);
	heapsort.print();
	std::cout << "---------------------" << std::endl;
	heapsort.get_sortlist(sortlist);
	for (size_t i = 0; i < sortlist.size(); ++i)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::cout << sortlist[i] << "\t";
	}
	std::cout << "\n" << std::endl;
}

void test_quicksort()
{
	std::vector<int> sortlist = { 1,5,3,100,3,2,5,6,7,8,19,10 };
	QuickSort<int> quicksort(10000);
	quicksort.init(sortlist);
	quicksort.print();
	std::cout << "---------------------" << std::endl;
	quicksort.sort();
	quicksort.print();
	std::cout << "---------------------" << std::endl;
}

void test_mergesort()
{
	std::vector<int> sortlist = { 1,5,3,100,3,2,5,6,7,8,19,10 };
	MergeSort<int> mergesort(10000);
	mergesort.init(sortlist);
	mergesort.print();
	std::cout << "---------------------" << std::endl;
	mergesort.sort();
	mergesort.print();
	std::cout << "---------------------" << std::endl;
}

void test_insertsort()
{
	std::vector<int> sortlist = { 1,5,3,100,3,2,5,6,7,8,19,10 };
	InsertSort<int> insertsort(1000);
	insertsort.init(sortlist);
	insertsort.bs_sort();
	insertsort.print();
}

void test_bubblesort()
{
	std::vector<int> sortlist = { 1,5,3,100,3,2,5,6,7,8,19,10 };
	BubbleSort<int> bubblesort(100);
	bubblesort.init(sortlist);
	bubblesort.sort();
	bubblesort.print();
}

int main()
{
	//test_heapsort();
	//test_quicksort();
	//test_mergesort();
	//test_insertsort();
	test_bubblesort();
}