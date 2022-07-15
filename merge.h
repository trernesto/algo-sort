#pragma once
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right) {
	long left_prt = 0; 
	long right_ptr = 0;
	std::vector<T> new_vec;
	while (left_prt < left.size() || right_ptr < right.size()) {
		if (right_ptr == right.size() || (left_prt < left.size() && left[left_prt] < right[right_ptr])) {
			new_vec.push_back(left[left_prt]);
			left_prt++;
		} else {
			new_vec.push_back(right[right_ptr]);
			right_ptr++;
		}
	}
	//debug
	/*std::cout << std::endl << "MERGE VECTOR: ";
	std::cout << std::endl << "right: ";
	for (int i = 0; i < right.size(); ++i) {
		std::cout << right[i] << " ";
	}
	std::cout << std::endl << "left: ";
	for (int i = 0; i < left.size(); ++i) {
		std::cout << left[i] << " ";
	}
	std::cout << std::endl << "new vec: ";
	for (int i = 0; i < new_vec.size(); ++i) {
		std::cout << new_vec[i] << " ";
	}*/

	return new_vec;
}


template<typename T>
std::vector<T> sortVector_merge(std::vector<T> vec) {
	if (vec.size() == 1) {
		//debug
		//std::cout << std::endl << "ended: " << vec[0] << std::endl;
		return vec;
	}
	int half = vec.size() / 2 + vec.size() % 2;

	//debug
	/*std::cout << std::endl << "Vector: ";
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl << "Vectors sizes:" << std::endl << 
	"right: " << 0 << " " << half - 1 << std::endl << 
	"left " << half << " " << vec.size() - 1 << std::endl;*/
	
	std::vector<T> right(vec.begin(), vec.begin() + half);
	right = sortVector_merge(right);
	std::vector<T> left(vec.begin() + half, vec.end());
	left = sortVector_merge(left);	
	std::vector<T> new_vec = merge(right, left);
	return new_vec;
}