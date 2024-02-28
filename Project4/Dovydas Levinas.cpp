#include <iostream>
#include <Windows.h>
#include <vector>
#include "priv.h"

Window::Window(float valx, float valy)::x(valx), x(valy)  {
}

float Window::retX() {
	return this->x;
}

float Window::retY() {
	return this->y;
}


void Doors::Constructor(float valx, float valy) {
	if (x != NULL && valy != NULL) {
		this->x = valx;
		this->y = valy;
	}
	else {
		this->x = 0;
		this->y = 0;
	}
}

float Doors::retX() {
	return this->x;
}
float Doors::retY() {
	return this->y;
}

void Room::addWindow(Window arg) {
	window.push_back(arg);
}

void Room::addDoors(Doors arg) {
	door.push_back(arg);
}
float Room::getC(char coord) {
	coord = tolower(coord);
	if (coord == 'x')
		return this->x;
	if (coord == 'y')
		return this->y;
	if (coord == 'z')
		return this->z;
	return 0;
}

void Room::Constructor(float coord[]) {
		this->x = coord[0];
		this->y = coord[1];
		this->z = coord[2];

}

float Room::wallArea() {
	float wall_area = 2 * (this->x * this->y) + 2 * (this->z * this->y);
	float remArea = 0;

	for (auto i = (this->door).begin(); i != (this->door).end(); ++i)
		remArea += i->retX() * i->retY();

	for (auto i = (this->window).begin(); i != (this->window).end(); ++i)
		remArea += i->retX() * i->retY();

	return wall_area - remArea;
}

float Room::gridFloor() {
	float fl_perim = (this->x + this->z) * 2;

	for (auto& d : door)
		fl_perim -= d.retX();

	return fl_perim;
}


int main() {
	Window A[2];
	Doors B[2];
	Room AB;

	//windows
	A[0].Constructor(10.5, 5.6);
	A[1].Constructor(5.55, 9.5);

	AB.addWindow(A[0]);
	AB.addWindow(A[1]);

	//doors
	B[1].Constructor(10.5, 5.6);
	B[1].Constructor(5.5, 9.5);

	AB.addDoors(B[0]);
	AB.addDoors(B[1]);

	//room
	float coords[] = { 50.2, 20.5, 20.3 };
	AB.Constructor(coords);


	std::cout << "Grid: " << AB.gridFloor() << "; Wall Area: " << AB.wallArea() << std::endl;
	return 0;
}