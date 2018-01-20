#pragma once

/*
	��������:
			1. normal_sort	��ͨ��������
			2. bs_sort		���ֲ��Ҳ�������
			3. std::vector	ֻ�Ǵ�����ͨ����,Ҳ��ʹ���������Ӳ����ٶ�
*/

#include "common.h"

// T����С�ڲ�����
template<typename T>
class InsertSort
{
	typedef std::vector<T> SORTLIST;

public:
	InsertSort(unsigned int max = 10000) : m_max(max) { }

	bool init(SORTLIST& t);
	void normal_sort();
	void bs_sort();
	void print();
	bool isMax() { return m_sortlist.size() >= m_max; }

private:
	unsigned int m_max;
	SORTLIST m_sortlist;
};

template<typename T>
bool InsertSort<T>::init(SORTLIST& t)
{
	if (isMax())
		return false;

	m_sortlist = t;
	return true;
}

template<typename T>
void InsertSort<T>::print()
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
void InsertSort<T>::normal_sort()
{
	T temp;
	int i = 0, j = 0;
	int len = m_sortlist.size();
	if (len <= 1)
		return;

	for (i = 1; i < len; ++i)
	{
		temp = m_sortlist[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (m_sortlist[j] < temp)
				break;
			else
				m_sortlist[j + 1] = m_sortlist[j];
		}

		m_sortlist[j + 1] = temp;
	}
}

template<typename T>
void InsertSort<T>::bs_sort()
{
	T temp;
	int mid = 0;

	int len = m_sortlist.size();
	if (len <= 1)
		return;

	for (int i = 1; i < len; ++i)
	{
		temp = m_sortlist[i];
		// ���ֲ��Ҷ�λ����λ��
		int start = 0, end = i - 1;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (temp < m_sortlist[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}

		// �Ӷ�λ��λ�ÿ�ʼ����ƶ�
		for (int j = i - 1; j >= start; --j)
		{
			m_sortlist[j + 1] = m_sortlist[j];
		}

		//�����뵽��λ
		m_sortlist[start] = temp;
	}
}