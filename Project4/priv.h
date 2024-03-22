#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <string>
#pragma once

template <class T> class vect {
private:
	int cap;
	int elems;
	int step;
	T* x;
public:
	vect(int a, int b)::cap(a), step(b) { 
		this->x = new T[cap];
		this->elems = 0;
	}

	~vect() {
		delete T;
	}


	vecto operator[](const size_t a) {
		return this->x[a]
	}
};




template <typename opa> void sorter(std::vector<opa> arr) {
	bool status = false;
	size_t n = arr.size();
	for (size_t i = 0; i < n - 1; ++i) {
		for (int i = 0; i < n - 1; i++)
			for (int j = n - 1; i < j; j--)
				if (arr[j] < arr[j - 1])
					swap(arr[j], arr[j - 1]);
	}

	for (auto& i : arr)
		std::cout << i << " ";
}