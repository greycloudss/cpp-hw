#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include <string>

class Window {
private:
	float x, y;

public:
	void setX(float val) {
		this->x = val;
	}
	void setY(float val) {
		this->y = val;
	}

	float retX() {
		return this->x;
	}
	float retY() {
		return this->y;
	}
};

class Doors {
private:
	float x, y;

public:
	void setX(float val) {
		this->x = val;
	}
	void setY(float val) {
		this->y = val;
	}

	float retX() {
		return this->x;
	}
	float retY() {
		return this->y;
	}
};

class Room {
private:
	float x, y, z;
	std::vector<Doors> door;
	std::vector<Window> window;
public:
	void addWindow(Window arg) {
		window.push_back(arg);
	}

	void addDoors(Doors arg) {
		door.push_back(arg);
	}
	float getC(char coord) {
		coord = tolower(coord);
		if (coord == 'x')
			return this->x;
		if (coord == 'y')
			return this->y;
		if (coord == 'z')
			return this->z;
		return 0;
	}

	void setC(char coord, float val) {
		coord = tolower(coord);
		if (coord == 'x')
			this->x = val;
		if (coord == 'y')
			this->y = val;
		if (coord == 'z')
			this->z = val;
	}

	float wallArea() {
		float wall_area = 4 * (this->x * this->y);
		float remArea = 0;

		for (auto i = (this->door).begin(); i != (this->door).end(); ++i)
			remArea += i->retX() * i->retY();

		for (auto i = (this->window).begin(); i != (this->window).end(); ++i)
			remArea += i->retX() * i->retY();

		return wall_area - remArea;
	}

	float gridFloor() {
		float fl_perim = this->x + this->z;

		for (auto& d : door)
			fl_perim -= d.retX();

		return fl_perim;
	}

};


void main() {
	Window A[2];
	Doors B[2];
	Room AB;

	//windows
	A[0].setX(10.5);
	A[0].setY(5.6);

	A[1].setX(5.5);
	A[1].setY(9.5);

	AB.addWindow(A[0]);
	AB.addWindow(A[1]);


	//doors
	B[0].setX(10.5);
	B[0].setY(5.6);

	B[1].setX(5.5);
	B[1].setY(9.5);

	AB.addDoors(B[0]);
	AB.addDoors(B[1]);

	//room
	AB.setC('x', (float)50.2);
	AB.setC('y', (float)20.5);
	AB.setC('z', (float)20.3);

	std::cout << "Grid: " << AB.gridFloor() << "; Wall Area: " << AB.wallArea() << std::endl;

}