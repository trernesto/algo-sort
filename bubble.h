#pragma once
#include <vector>
#include <iostream>

template<typename T>
void sortVector_bubble(std::vector<T>& vec) {
	int j;
	T temp;
	for (int i = 0; i < vec.size(); ++i) {
		j = i;
		while (j > 0 && vec[j] < vec[j - 1]) {
			//swap
			temp = vec[j];
			vec[j] = vec[j - 1];
			vec[j - 1] = temp;
			j--;
		}
	}
}