#include <iostream>
#include <vector>
#pragma once

class Window {
private:
	float x, y;

public:
	void Constructor(float valx, float valy);
	float retX();
	float retY();
};

class Doors {
private:
	float x, y;

public:
	void Constructor(float valx, float valy);
	float retX();
	float retY();
};

class Room {
private:
	float x, y, z;
	std::vector<Doors> door;
	std::vector<Window> window;
public:
	void Constructor(float coord[]);
	void addDoors(Doors arg);
	void addWindow(Window arg);
	float getC(char coord);
	float wallArea();
	float gridFloor();
};