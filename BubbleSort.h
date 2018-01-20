#pragma once

/*
	冒泡排序:
			使用鸡尾酒排序法，正序和反序各遍历一次；
			如果一次遍历中没有交换位置，则排序完成
*/

#include "common.h"

template<typename T>
class BubbleSort
{
	typedef std::vector<T> SORTLIST;

public:
	BubbleSort(unsigned int max = 10000) : m_max(max) { }

	void init(SORTLIST& t);
	void sort();
	void print();

	bool isMax() { return m_sortlist.size() >= m_max; }

private:
	SORTLIST m_sortlist;
	unsigned int m_max;
};

template<typename T>
void BubbleSort<T>::init(SORTLIST& t)
{
	if (isMax())
		return;

	m_sortlist = t;
	return;
}

template<typename T>
void BubbleSort<T>::sort()
{
	int len = m_sortlist.size();
	if (len <= 1)
		return;

	int left = 0, right = len - 1;

	bool swap_flag = false;
	while (left < right)
	{
		swap_flag = false;
		for (int i = left; i < right; ++i)
		{
			if (m_sortlist[i + 1] < m_sortlist[i])
			{
				std::swap(m_sortlist[i], m_sortlist[i + 1]);
				swap_flag = true;
			}
		}

		if (!swap_flag)
			return;

		--right;

		swap_flag = false;
		for (int i = right; i > left; --i)
		{
			if (m_sortlist[i] < m_sortlist[i - 1])
			{
				std::swap(m_sortlist[i], m_sortlist[i - 1]);
				swap_flag = true;
			}
		}

		if (!swap_flag)
			return;

		++left;
	}
}

template<typename T>
void BubbleSort<T>::print()
{
	for (size_t i = 0; i < m_sortlist.size(); ++i)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::cout << m_sortlist[i] << "\t";
	}
	std::cout << "\n" << std::endl;
}