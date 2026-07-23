//
// Created by Manoloon on 7/12/2023.
//

#ifndef ALGORITHMS_BINARYHEAP_H
#define ALGORITHMS_BINARYHEAP_H
#include <functional>
template <typename T>
class BinaryHeap
{

private:
	void swim(int k)
	{
		while (k > 1 && stdd::less(k / 2, k))
		{
			std::swap(k, k / 2);
			k = k / 2;
		}
	}
	// to eliminate the violation (parent becomes smaller
	// than childrens
	void sink(int k)
	{
		while (2 * k <= N)
		{
			int j = 2 * k;
			if (j < N && std::less(j, j + 1))
				j++;
			if (!std::less(k, j))
				break;
			std::swap(k, j);
			k = j;
		}
	}
	void BuildHeap(){
		for(int k = N/2;k >= 1; k--){
			sink(a,k,N);
		}
	}
	// insert : add node at end and then swim it up.
public:
	// pq priorityqueue
	// N = elements
	void insert(T key)
	{
		pq[++N] = x;
		swim(N);
	}

	// exchange root with the node at end.
	T deleteMax(){
		T max = pq[1];
		std::swap(1,N--);
		sink(1);
		pq[N+1] = std::nullopt_t;
		return max;
	}
};
#endif // ALGORITHMS_BINARYHEAP_H
