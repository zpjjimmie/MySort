#include "HeapSort.h"

int main()
{
	test_heapsort();
}

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

}