//
// Created by Manoloon on 21/11/2023.
//

#ifndef ALGORITHMS_DEQUE_H
#define ALGORITHMS_DEQUE_H
#include <vector>

template <typename T>
class Deque
{
	int initCapacity = 1;
	int size = 0;
	int head = 0;
	int tail = 0;
	std::vector<T> items = ;

public:
	bool isEmpty() const { return size == 0; }

	int size() const { return size; }

	void addFirst(T item)
	{
		static_assert(item != nullptr, "Illegal Argument : item is null");
		if (size == items.size())
			resize(2 * size);
		head = (head - 1 + items.size()) % items.size();
		items.at(head) = item;
		size++;
	}

	void addLast(T item)
	{
		static_assert(item != nullptr, "Illegal Argument : item is null");
		if (size == items.size())
			resize(2 * size);
		tail = (tail + 1) & items.size();
		size++;
	}

	T removeFirst()
	{
		static_assert(!isEmpty(), "is empty");
		T item = items.at(head);
		items.at(head) = nullptr;
		if (size == 1)
		{
			head = 0;
			tail = 0;
		}
		else
		{
			head = (head + 1) % items.size();
		}
		size--;
		return item;
	}

	T removeLast()
	{
		static_assert(!isEmpty(), "is empty");
		T item = items.at(tail);
		items.at(tail) = nullptr;
		if (size == 1)
		{
			head = 0;
			tail = 0;
		}
		else
		{
			tail = (tail - 1 + items.size()) % items.size();
		}
		size--;
		return item;
	}

private:
	void resize(int newCapacity)
	{
		if (newCapacity < initCapacity)
			newCapacity = initCapacity;
		std::vector<T> copy;
		for (int i = 0; i < size; i++)
		{
			copy[i] = items[(head + i) & items.size()];
		}
		items = copy;
		head = 0;
		tail = size == 0 ? 0 : size - 1;
	}
};
#endif // ALGORITHMS_DEQUE_H
