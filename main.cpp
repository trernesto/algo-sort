#include <iostream>
#include "bubble.h"
#include "merge.h"
#include "Heap.h"
#include "QuickSort.h"
#include "binSearch.h"

int main() {
	std::vector<int> vec = {1, 2, 2, 5, 14, 32, 2, 0, -5, 6, 17, 44, 52, 11};
	//Heap heap = Heap(vec);
	//sortVectorBubble(vec);
	//vec = sortVectorMerge(vec);
	/*for (int i = 0; i < heap.size(); ++i) {
		std::cout << heap.getElement(i) << " ";
	}
	std::cout << std::endl;
	*/
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout <<std::endl;
	sortVectorQuick(vec, 0, vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << findBinSearch(vec, 6) << std::endl;
	std::cout << std::endl << findBinSearch(vec, 5) << std::endl;
	std::cout << std::endl << findBinSearch(vec, 10) << std::endl;
	return 0;
}