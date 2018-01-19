#pragma once
/*
	快速排序:
			采用分治法的思想，进行递归调用;
			对于每个分治序列，选取最后一个作为基数，根据该基数划分左右两个序列，左序列小于基数，右序列大于基数;
			每次递归确定基数位置
*/

#include "common.h"

// T为支持随机存储的容器,如vector
template<typename T>
class QuickSort
{
	typedef std::vector<T> SORTLIST;
public:
	QuickSort(unsigned int max = 10000) : m_max(max) { }
	~QuickSort() { }

	bool init(SORTLIST& t);
	void sort();
	void print();

	bool isMax() { return m_sortlist.size() >= m_max; }

private:
	void sort_recursive(int start, int end);

private:
	unsigned int m_max;
	SORTLIST m_sortlist;
};

template<typename T>
bool QuickSort<T>::init(SORTLIST& t)
{
	if (isMax())
		return false;

	m_sortlist = t;
	return true;
}

template<typename T>
void QuickSort<T>::print()
{
	for (size_t i = 0; i < m_sortlist.size(); ++i)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::cout << m_sortlist[i] << "\t";
	}
	std::cout << "\n" << std::endl;
}

template<typename T>
void QuickSort<T>::sort()
{
	int len = m_sortlist.size();
	if (len <= 1)
		return;

	sort_recursive(0, len - 1);
}

template<typename T>
void QuickSort<T>::sort_recursive(int start, int end)
{
	if (start >= end || end <= 0)
		return;

	T& pivot = m_sortlist[end];	// 基准值
	int left = start;
	int right = end - 1;

	while (left < right)
	{
		while (m_sortlist[left] <= pivot && left < right)
			++left;

		while (m_sortlist[right] >= pivot && left < right)
			--right;

		std::swap(m_sortlist[left], m_sortlist[right]);
	}

	if (m_sortlist[left] >= m_sortlist[end])
		std::swap(m_sortlist[left], m_sortlist[end]);

	else
		++left;

	sort_recursive(start, left - 1);
	sort_recursive(left + 1, end);
}