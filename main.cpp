#include <iostream>
#include "bubble.h"

int main() {
	std::vector<double> vec = {1, 2, 5, 14, 32, 2, 0, -5, 6, 17, 44, 52, 11};
	sortVector_bubble(vec);
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	return 0;
}