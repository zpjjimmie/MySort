#pragma once

/*
	归并排序：
			将序列分成若干个子序列;
			每两个序列进行合并排序，直到完成所有排序
*/

#include "common.h"

template<typename T>
class MergeSort
{
	typedef std::vector<T> SORTLIST;
public:
	MergeSort(unsigned int max = 10000) : m_max(max) { }
	~MergeSort() { }

	bool init(SORTLIST& t);
	void sort();
	void print();

	bool isMax() { return m_sortlist.size() >= m_max; }

private:
	void sort_recursive(int start, int end);

private:
	unsigned int m_max;
	SORTLIST m_sortlist;
	SORTLIST m_sortedlist;
};

template<typename T>
bool MergeSort<T>::init(SORTLIST& t)
{
	if (isMax())
		return false;

	m_sortlist = t;
	return true;
}

template<typename T>
void MergeSort<T>::print()
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
void MergeSort<T>::sort()
{
	int len = m_sortlist.size();
	m_sortedlist.clear();
	m_sortedlist.resize(len);
	if (len <= 1)
		return;

	sort_recursive(0, len - 1);
}

template<typename T>
void MergeSort<T>::sort_recursive(int start, int end)
{
	if (start >= end)
		return;

	int len = end - start + 1;
	int mid = start + len / 2 - 1;

	// 存储开始结束标记
	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;

	sort_recursive(start1, end1);
	sort_recursive(start2, end2);

	int cursor = start;
	// 开始归并排序
	while (start1 <= end1 && start2 <= end2)
	{
		if (m_sortlist[start1] <= m_sortlist[start2])
			m_sortedlist[cursor++] = m_sortlist[start1++];
		else
			m_sortedlist[cursor++] = m_sortlist[start2++];
	}
	
	while (start1 <= end1)
		m_sortedlist[cursor++] = m_sortlist[start1++];

	while (start2 <= end2)
		m_sortedlist[cursor++] = m_sortlist[start2++];

	for (int i = start; i <= end; ++i)
	{
		m_sortlist[i] = m_sortedlist[i];
	}
}