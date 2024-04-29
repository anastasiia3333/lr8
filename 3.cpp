#include <iostream>
using namespace std;

class array
{
	int nums[10];
public:
	array();
	void set(int n[10]);
	void show();
	array &operator ++();
	friend array &operator --(array &obj);
};

array::array() 
{
	for (int i = 0; i < 10; i++) nums[i] = 0;
}

void array::set(int *n) 
{
	for (int i = 0; i < 10; i++) nums[i] = n[i];
}

void array::show() 
{
	for(int i = 0; i < 10; i++) 
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

array &array::operator ++()
{
	for(int i = 0; i < 10; i++) ++nums[i];
	return *this;
}

array &operator --(array &obj)
{
	for(int i = 0; i < 10; i++) --obj.nums[i];
	return obj;
}

int main()
{
	array obj1, obj2;
	int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	obj1.set(i);
	obj2.set(i);
	++obj1;
	obj1.show();
	--obj2;
	obj2.show();

	return 0;
}