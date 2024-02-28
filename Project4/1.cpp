#include "priv.h"

void Number::set(int which, int val) {
	if (which == 0)
		maxnum = val;
	else
		minnum = val;
}
void Number::setVal(int val) {
	if (val >= minnum && maxnum >= val)
		value = val;
	else
		throw std::out_of_range("out_of_range");
}
int Number::getVal() const {
	return value;
}

int Number::maxnum = 0;
int Number::minnum = 0;

void bubbleSort(std::vector<Number>& arr, size_t n) {
	bool status = false;

	for (size_t i = 0; i < n - 1; ++i) {
		status = false;

		for (size_t j = 0; j < n - 1 - i; ++j) {
			if (arr[j].getVal() > arr[j + 1].getVal()) {
				std::swap(arr[j], arr[j + 1]);
				status = true;
			}
		}

		if (!status)
			break;
	}
}

void printArray(const std::vector<Number>& arr, size_t n) {
	for (size_t i = 0; i < n; i++)
		std::cout << arr[i].getVal() << " ";
	std::cout << std::endl;
}


int main() {
	Number::set(0, 10);
	Number::set(1, -10);

	std::vector<Number> arr(10);
	size_t n = 0;

	std::cout << "enter integers from [-10; 10]" << std::endl;

	do {
		try {
			int num;
			if (!(std::cin >> num))
				throw std::invalid_argument("invalid_argument");
			arr[n++].setVal(num);
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		} catch (const std::invalid_argument& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
	} while (n < 10);

	printArray(arr, n);
	bubbleSort(arr, n);
	printArray(arr, n);

	return 0;
}
