#include "priv.h"



void printArray(const std::vector<std::string>& arr) {
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
	
int main() {
	std::string tmp;
	std::vector<std::string> arr;
	
	do {
		std::cin >> tmp;
		if (tmp[0] != '-') {
			arr.push_back(tmp);
		}
		else break;
	} while (1);
	printArray(arr);
	
	/*
	do {
		std::cin >> tmp;
		if (tmp != 0) {
			arr.push_back(tmp);
		}
		else break;
	} while (1);
	printArray(arr);
	sorter<int>(arr);
	*/
	sorter<std::string>(arr);

	return 0;
}
