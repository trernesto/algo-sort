#pragma once
#include <vector>

/*
binary heap
parent: i element
child: 2i + 1, 2i + 2;
insert O(log n)
get min O(1)
remove min O(log n)
 */

template <typename T>
class Heap {
private:
	std::vector<T> heap;
public:
	Heap(std::vector<T> vec) {
		//O(nlogn)
		for (int i = 0; i < vec.size(); ++i) {
			insert(vec[i]);
		}
	}

	void operator = (const Heap& heap) {
		this.heap = heap;
	}

	void insert(T x) {
		int i = heap.size();
		heap.push_back(x);
		//sift up
		//swap child and parent until heap return to normal
		while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
			T temp = heap[i];
			heap[i] = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = temp;
			i = (i - 1) / 2;
		}
	}

	T get_min() {
		return heap[0];
	}

	void remove_min() {
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		int i = 0;
		while (2 * i + 1 < heap.size()) {
			int j = 2*i + 1;
			if (2*i + 2 < heap.size() && heap[2*i + 2] < heap[j]) {
				j = 2*i + 2;
			}
			if (heap[i] < heap[j]) {
				break;
			} else {
				T temp = heap[i];
				heap[i] = heap[j];
				heap[j] = temp;
				i = j;
			}
		}		
	}

	std::vector<T> sortVectorHeap() {
		Heap tempHeap = heap;
		std::vector<T> sortedVec;
		while (tempHeap.size() > 0) {
			sortedVec.push_back(tempHeap.get_min());
			tempHeap.remove_min();
		}
		return sortedVec;
	}

	T getElement(int i) {
		return heap[i];
	}

	long size() {
		return heap.size();
	}
};