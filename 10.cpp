#include <iostream>
using namespace std;

class planet
{
protected:
	double distance;
	int revolve;
public: 
	planet(double d, int r) { distance = d; revolve = r; }
};

class earth: public planet
{
	double circumference;
public:
	earth(double d, int r) : planet(d, r) 
	{
		circumference = 2 * r * 3.1416;
	}
	void show()
	{
        cout << "Distance from the Sun: " << distance << " miles." << endl;
        cout << "Days to revolve around the Sun: " << revolve << " days." << endl;
        cout << "Circumference of Earth's orbit: " << circumference << " miles." << endl;
	}
};

int main()
{
	earth obj(93000000, 365);
	obj.show();

	return 0;
}