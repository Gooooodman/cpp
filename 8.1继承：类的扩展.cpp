//继承：类的扩展
//旧类派生出新类的机制被称为继承（或派生化）。
//旧类被称为基类，新类称为派生类或子类。
//当从基类私有派生一个继承类时，基类的公用成员成为了派生类的私有成员，
//所以它们只能由派生类的成员函数访问，而不能被派生类的对象直接访问。
//当基类被公用继承时，其公用成员变成派生类的公用成员，所以它们可被派生类对象访问。
#include<iostream>
using namespace std;
class B
{
private:
	int a;
public:
	int b;
	void get_ab();
	int get_a(void);
	void show_a(void);
};
class D :private B
{
private:
	int c;
public:
	void mul(void);
	void display(void);

};
void B::get_ab(void)
{
	cout << "Enter values for a and b:";
	cin >> a >> b;
}
int B::get_a()
{
	return a;
}
void B::show_a()
{
	cout << "a=" << a << "\n";
}
void D::mul()
{
	get_ab();
	c = b*get_a();
}
void D::display()
{
	show_a();
	cout << "b=" << b << "\n"
		<< "c=" << c << "\n\n";

}
int main()
{
	D d;
	//d.get_ab();
	d.mul();
	//d.show_a();
	d.display();
	//d.b=20;
	d.mul();
	d.display();
	system("pause");
	return 0;
}