#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

template<typename T>
int split(std::vector<T>& vec, int l, int r);

template<typename T>
void sortVectorQuick(std::vector<T>& vec, int l, int r) {
	if (r - l <= 1) {
		return;
	}
	int m = split(vec, l, r);
	sortVectorQuick(vec, l, m);
	sortVectorQuick(vec, m, r);
}

//split vector into 2 pieces
//first is less than x = vec[rand]
//second is greater or equal than x
template<typename T>
int split(std::vector<T>& vec, int l, int r) {
	int rand = l + std::rand() % (r - l);
	T x = vec[rand];
	int m = l;
	for(int i = l; i < r; ++i) {
		if (vec[i] < x) {
			//swap i and m element
			T temp = vec[i];
			vec[i] = vec[m];
			vec[m] = temp;
			m++;
		}
	}
	return m;
}