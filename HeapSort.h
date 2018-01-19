#pragma once

/*
	堆排序:
			索引从0开始;
			父节点为i, 则左子节点为i * 2 + 1,右子节点为i * 2 + 2;
			子节点为i, 则父节点为 (i - 1) / 2;
			最后一个父节点为len / 2 - 1, len为总节点数;
			有右子树一定有左子树，反之不一定成立;

	维护一个大顶堆列表, get_sortlist返回排序好的列表
*/

#include "common.h"
#include <vector>

template<typename T>
class HeapSort
{
	typedef std::vector<T> SORTLIST;
public:
	HeapSort(unsigned int max = 10000) : m_max(max) { }

	bool init(SORTLIST& sortlist);
	bool add(T& elem);
	bool del(bool root);
	void get_sortlist(SORTLIST& newsortlist);
	void print();

	bool isMax() { return m_sortlist.size() >= m_max; }

protected:
	void create_heap();
	void shift_up();
	void shift_down();

protected:
	void max_heapify(SORTLIST&, int start, int end);

private:
	SORTLIST m_sortlist;
	unsigned int m_max;
};

template<typename T>
bool HeapSort<T>::init(SORTLIST& sortlist)
{
	if (isMax())
		return false;
	m_sortlist = sortlist;
	create_heap();
	return true;
}

template<typename T>
void HeapSort<T>::max_heapify(SORTLIST& sortlist, int start, int end)
{
	int parent = start;
	int child = start * 2 + 1;

	while (child <= end)
	{
		// 取左右子树中较大的那个
		if (child + 1 <= end && sortlist[child] < sortlist[child + 1])
			child = child + 1;

		// 与父节点比较
		if (sortlist[parent] < sortlist[child])
		{
			std::swap(sortlist[parent], sortlist[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
			return;
	}
}

// 创建一个大顶堆
template<typename T>
void HeapSort<T>::create_heap()
{
	int len = m_sortlist.size();
	// 从最后一个父节点开始往前遍历
	for (int i = len / 2 - 1; i >= 0; --i)
	{
		max_heapify(m_sortlist, i, len - 1);
	}
}

template<typename T>
void HeapSort<T>::get_sortlist(SORTLIST& newsortlist)
{
	newsortlist = m_sortlist;

	int len = newsortlist.size();
	if (!len)
		return;

	for (int i = len - 1; i > 0; --i)
	{
		std::swap(newsortlist[0], newsortlist[i]);
		max_heapify(newsortlist, 0, i - 1);
	}
}

template<typename T>
void HeapSort<T>::print()
{
	for (size_t i = 0; i < m_sortlist.size(); ++i)
	{
		if (i % 10 == 0)
			std::cout << std::endl;
		std::cout << m_sortlist[i] << "\t";
	}
	std::cout << "\n" << std::endl;
}

// 将末尾节点上浮
template<typename T>
void HeapSort<T>::shift_up()
{
	if (m_sortlist.size() <= 1)
		return;

	int child = m_sortlist.size() - 1;
	int parent = 0;

	while (child >= 1)
	{
		parent = (child - 1) / 2;
		max_heapify(m_sortlist, parent, child);
		child = parent;
	}
}

// 将根节点下沉
template<typename T>
void HeapSort<T>::shift_down()
{
	if (m_sortlist.size() <= 1)
		return;

	max_heapify(m_sortlist, 0, m_sortlist.size() - 1);
}

// 添加节点
template<typename T>
bool HeapSort<T>::add(T& elem)
{
	if (isMax())
		return false;

	m_sortlist.push_back(elem);
	shift_up();

	return true;
}

/*
	删除节点
	root: true-根节点 false-最后一个叶子节点
*/
template<typename T>
bool HeapSort<T>::del(bool root)
{
	if (m_sortlist.empty())
		return false;

	if (root)
	{
		std::swap(m_sortlist[0], m_sortlist[m_sortlist.size() - 1]);
		m_sortlist.pop_back();
		shift_down();
	}
	else
		m_sortlist.pop_back();

	return true;
}