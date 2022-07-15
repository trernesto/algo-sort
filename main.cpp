#include <iostream>
#include "bubble.h"
#include "merge.h"
#include "Heap.h"

int main() {
	std::vector<double> vec = {1, 2, 5, 14, 32, 2, 0, -5, 6, 17, 44, 52, 11};
	Heap heap = Heap(vec);
	//sortVector_bubble(vec);
	//vec = sortVector_merge(vec);
	for (int i = 0; i < heap.size(); ++i) {
		std::cout << heap.getElement(i) << " ";
	}
	std::cout << std::endl;
	
	vec = heap.sortVector_heap();
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	
	return 0;
}