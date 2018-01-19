#pragma once
/*
	��������:
			���÷��η���˼�룬���еݹ����;
			����ÿ���������У�ѡȡ���һ����Ϊ���������ݸû������������������У�������С�ڻ����������д��ڻ���;
			ÿ�εݹ�ȷ������λ��
*/

#include "common.h"

// TΪ֧������洢������,��vector
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

	T& pivot = m_sortlist[end];	// ��׼ֵ
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