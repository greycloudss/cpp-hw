#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#define max 1000


void bubbleSort(std::vector<int> arr, int n) {
	int tmp;
	bool status = false;
	for (int i = 0; i < n; i++) {
		status = false;


		for (int ii = arr.begin(); ii < n - i - 1; ii++) {
			if (arr[ii] > arr[ii + 1]) {
				std::swap(arr[ii], arr[ii + 1]);
				status = true;
			}
		}

		if (status == false)
			break;
		if (arr[i] == 0)
			break;
	}


}

void printArray(std::vector<int> arr, int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			return;

		std::cout << arr[i] << " ";
	}
}

int main(void) {
	int tmp;
	std::vector<int> arr;
	int n = 0;
	std::cout << "Hello world!";
	Sleep(3000);
	do {
		system("cls");
		//std::cout << "Enter any integer you wish. the maximum is 1000 integers, however if you enter 0 the program stops" << std::endl;
		std::cout << "Enter an integer: ";
		std::cin >> tmp;
		if (tmp != 0) {
			arr.push_back(tmp);
			n++;
		}
		else {
			system("cls");
			printArray(arr, n); // unsorted
			bubbleSort(arr, n);
			puts("\n\n");
			printArray(arr, n); //sorted
			break;
		}

	}while (1);

	return 0;
}

/*
* 
  --------------------
 |  1 2 ir 3 uzduotys |
  --------------------
* 
* 
* 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#define max 1000


void bubbleSort(int arr[], int n) {
	int tmp;
	bool status = false;
	for (int i = 0; i < n; i++) {
		status = false;
		

		for (int ii = 0; ii < n - i - 1; ii++) {
			if (arr[ii] > arr[ii + 1]) {
				std::swap(arr[ii], arr[ii + 1]);
				status = true;
			}
		}

		if (status == false)
			break;
		if (arr[i] == 0)
			break;
	}


}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			return;

		std::cout << arr[i] << " ";
	}
}

int main(void) {
	int tmp;
	int arr[max] = { 0 };
	int n = 0;
	std::cout << "Hello world!";
	Sleep(3000);
	for (int i = 0; i < max; i++) {
		system("cls");
		//std::cout << "Enter any integer you wish. the maximum is 1000 integers, however if you enter 0 the program stops" << std::endl;
		std::cout << "Enter an integer: ";
		std::cin >> tmp;
		if (tmp != 0) {
			arr[i] = tmp;
			n++;
		}
		else {
			system("cls");
			printArray(arr, n); // unsorted
			bubbleSort(arr, n);
			puts("\n\n");
			printArray(arr, n); //sorted
			break;
		}
	}

	return 0;
}
*/