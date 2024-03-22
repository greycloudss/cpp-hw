#include <iostream>
#include <vector>

class Window {
public:
    float x;
    float y;
    static int createdWindows;

    Window(float valx, float valy) : x(valx), y(valy) {
        createdWindows++;
    }

    ~Window() {
        createdWindows--;
    }

    float retX() {
        return this->x;
    }

    float retY() {
        return this->y;
    }
};

int Window::createdWindows = 0;

class Doors {
public:
    float x;
    float y;
    static int createdDoors;

    Doors(float valx, float valy) : x(valx), y(valy) {
        createdDoors++;
    }

    ~Doors() {
        createdDoors--;
    }

    float retX() {
        return this->x;
    }

    float retY() {
        return this->y;
    }
};

int Doors::createdDoors = 0;

class Room {
public:
    float x;
    float y;
    float z;
    std::vector<Window*> windows;
    std::vector<Doors*> doors;

    ~Room() {
        for (Window* window : windows) {
            delete window;
        }
        for (Doors* door : doors) {
            delete door;
        }
    }

    void addWindow(Window* arg) {
        windows.push_back(arg);
        std::cout << "Number of Windows: " << windows.size() << std::endl;
    }

    void addDoors(Doors* arg) {
        doors.push_back(arg);
        std::cout << "Number of Doors: " << doors.size() << std::endl;
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

    void Constructor(float coord[]) {
        this->x = coord[0];
        this->y = coord[1];
        this->z = coord[2];
    }

    float wallArea() {
        float wall_area = 2 * (this->x * this->y) + 2 * (this->z * this->y);
        float remArea = 0;

        for (auto i : doors)
            remArea += i->retX() * i->retY();

        for (auto i : windows)
            remArea += i->retX() * i->retY();

        return wall_area - remArea;
    }

    float gridFloor() {
        float fl_perim = (this->x + this->z) * 2;

        for (auto& d : doors)
            fl_perim -= d->retX();

        return fl_perim;
    }
};

int main() {
    Window* A[2];
    Doors* B[2];
    Room* AB = new Room();

    // Windows
    A[0] = new Window(10.5, 5.6);
    AB->addWindow(A[0]);

    A[1] = new Window(5.55, 9.5);
    AB->addWindow(A[1]);

    // Doors
    B[0] = new Doors(10.5, 5.6);
    AB->addDoors(B[0]);

    B[1] = new Doors(5.5, 9.5);
    AB->addDoors(B[1]);

    // Room
    float coords[] = { 50.2, 20.5, 20.3 };
    AB->Constructor(coords);

    std::cout << "Grid: " << AB->gridFloor() << "; Wall Area: " << AB->wallArea() << std::endl;

    delete AB;
    delete A[0];
    delete A[1];
    delete B[0];
    delete B[1];

    return 0;
}