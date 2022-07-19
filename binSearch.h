#pragma once
#include <vector>
#include <iostream>

//inv
//l, r
//a[l] < x, a[r] >= x
//function gets index of number or nearest(from right side) number
//if you want nearest number from left size you should change return r -> return l
template<typename T>
int findBinSearch(std::vector<T> sortedVec, T x) {
	int l = -1; int r = sortedVec.size();
	while (r - l > 1) {
		int m = (r + l) / 2;
		if (sortedVec[m] >= x) {
			r = m;
		} else {
			l = m;
		}
	}
	return r;
}