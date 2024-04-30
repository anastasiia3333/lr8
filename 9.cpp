#include <iostream>
using namespace std;

class building {
protected:
    int stages;
    int rooms;
    double area;

public: 
    building(int s, int r, double a) : stages(s), rooms(r), area(a) {}  

    void showb() {
        cout << "Building has " << stages << " stages and " << rooms << " rooms in total. Area of rooms is " << area << " m^3" << endl; 
    }
};

class house : public building {
    int bathrooms;
    int bedrooms;

public:
    house(int s, int r, double a, int b, int br) : building(s, r, a), bathrooms(b), bedrooms(br) {}

    void showh()  {
        showb(); 
        cout << "House has " << bathrooms << " bathrooms and " << bedrooms << " bedrooms." << endl; 
    }
};

class office : public building {
    int extinguishers;
    int phones;

public:
    office(int s, int r, double a, int e, int p) : building(s, r, a), extinguishers(e), phones(p) {}

    void showo()  {
        cout << "Office has " << extinguishers << " extinguishers and " << phones << " phones." << endl; 
    }
};

int main() {
    house h(3, 300, 1098.9, 2, 4);
    office o(2, 100, 500.7, 5, 10);
    h.showh();
    o.showo();

    return 0;
}

