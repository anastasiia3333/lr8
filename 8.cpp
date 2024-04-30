#include <iostream>
using namespace std;

class A 
{
	int i;
public:
	A(int a) { i = a; }
	void showa() { cout << "A:" << i << endl; }
};

class B 
{
	int j;
public:
	B(int a) { j = a; }
	void showb() { cout << "B:" << j << endl; }
}; 

class C : public A, public B 
{
	int k;
public: 
	C(int a, int b, int c) : A(a), B(b) { k = c; }
	void showc() 
	{ 
        showa();
        showb();
		cout << "C:" << k << endl; }
};

int main()
{
	C objC(1,3,5);
	objC.showc(); 

	return 0;
}