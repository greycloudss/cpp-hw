#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#pragma once

class Number {
private:
	static int maxnum;
	static int minnum;
	int value;
public:
	static void set(int which, int val);
	void setVal(int val);
	int getVal() const;
};