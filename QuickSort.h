#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

template<typename T>
int split(std::vector<T>& vec, int l, int r);

template<typename T>
void swap(T& first, T&second) {
	T temp = first;
	first = second;
	second = temp;
}

template<typename T>
void sortVectorQuick(std::vector<T>& vec, int l, int r) {
	if (r - l <= 1) {
		return;
	}
	int m = split(vec, l, r);
	sortVectorQuick(vec, l, m);
	sortVectorQuick(vec, m + 1, r);
}

//split vector into 2 pieces
//first is less than x = vec[rand]
//second is greater or equal than x
template<typename T>
int split(std::vector<T>& vec, int l, int r) {
	int rand = l + std::rand() % (r - l);
	T x = vec[rand];
	swap(vec[rand], vec[r - 1]);
	int m = l;
	for(int i = l; i < r; ++i) {
		if (vec[i] < x) {
			if (i > rand) {
				rand++;
			}
			swap(vec[i], vec[m]);
			m++;
		}
	}
	swap(vec[m], vec[r - 1]);
	return m;
}