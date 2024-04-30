#include <iostream>
using namespace std;

class coord
{
public:
    int x, y;
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    friend coord operator+(const coord &ob1, const coord &ob2);
    friend coord operator-(const coord &ob1, const coord &ob2);
    coord &operator=(const coord &ob);
};

coord operator+(const coord &ob1, const coord &ob2)
{
    cout << "Using coord operator +()\n";
    coord temp;
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}

coord operator-(const coord &ob1, const coord &ob2)
{
    cout << "Using coord operator -()\n";
    coord temp;
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}

coord &coord::operator=(const coord &ob)
{
    cout << "Using coord operator =()\n";
    x = ob.x;
    y = ob.y;
    return *this;
}

class quad : public coord
{
    int quadrant;

public:
    quad() { x = 0; y = 0; quadrant = 0; }
    quad(int x, int y) : coord(x, y)
    {
        if (x >= 0 && y >= 0)
            quadrant = 1;
        else if (x < 0 && y >= 0)
            quadrant = 2;
        else if (x < 0 && y < 0)
            quadrant = 3;
        else
            quadrant = 4;
    }

    void showq() const { cout << "Point in Quadrant: " << quadrant << '\n'; }
    quad &operator=(const coord &ob2)
    {
        cout << "Using quad operator =()\n";
        x = ob2.x;
        y = ob2.y;
        if (x >= 0 && y >= 0)
            quadrant = 1;
        else if (x < 0 && y >= 0)
            quadrant = 2;
        else if (x < 0 && y < 0)
            quadrant = 3;
        else
            quadrant = 4;
        return *this;
    }
};

int main()
{
    quad o1(7, 4), o2(10, 1), o3;
    int x, y;

    o3 = o1 + o2;
    o3.get_xy(x, y);
    o3.showq();
    cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2;
    o3.showq();
    o3.get_xy(x, y);
    cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1;
    o3.showq();
    o3.get_xy(x, y);
    cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}

