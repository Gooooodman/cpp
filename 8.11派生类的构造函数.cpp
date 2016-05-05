//8.11 派生类的构造函数
//只要基类的构造函数不需要参数，派生类就不需要构造函数
//一旦基类包含了带参的构造函数，那么它的派生类就必须有构造函数，
//并将参数传递给基类的构造函数
#include<iostream>
using namespace std;
class A
{
private:
	int x;
public:
	A(int i)
	{
		x = i;
		cout << "A \n";
	}
	void show_x(void)
	{
		cout << "x=" << x << "\n";
	}
};
class B
{
private:
	float y;
protected:
public:
	B(float j)
	{
		y = j;
		cout << "B \n";
	}
	void show_y(void)
	{
		cout << "y=" << y << "\n";
	}
};
class C :public B, public A    //B首先被初始化，所以第一个被调用
{
	int m, n;
public:
	C(int a, float b, int c, int d) :A(a), B(b)
	{
		m = c;
		n = d;
		cout << "C \n";
	
	}
	void show_mn(void)
	{
		cout << "m=" <<m <<"\n"<< "n=" << n<< "\n";
	}
};
int main()
{
	C g(5, 10.75, 20, 30);
	cout << "\n";
	g.show_x();
	g.show_y();
	g.show_mn();
	system("pause");
	return 0;
}