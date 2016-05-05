//静态数据成员
//类的数据成员可修饰为静态，一个静态成员变量有如下特征：
//类的第一个对象被创建时，它被一次性初始化为0
//类的静态成员只有一个实例，不论创建了多少累对象，它们都共享这一个静态成员变量
//静态成员只在类内可见，但其生存期是整个程序的执行期
//静态成员函数
//静态函数只能访问类内声明的其他静态成员（函数或变量）
//调用静态成员函数时，使用的是类名(而非对象)
#include<iostream>
using namespace std;
class item
{
	static int count;     //静态成员变量
	int number;
public:
	void getdata(int a)
	{
		number = a;
		count++;
	}
	void ms(void)
	{
		count = 0;
	}
	void getcount(void)
	{
		cout << "count:";
		cout << count << "\n";
	}
	static void showcount(void)               //静态成员函数
	{
		cout << "count:" << count << "\n";   //调用静态成员变量
		//cout << "number:" << number << "\n";   number不是静态变量
	}
};
int item::count;                //静态数据成员的定义，可对count进行初始化
int main()
{
	item a, b, c;                //对count进行初始化为0，也可对count进行赋值
	a.getcount();
	b.getcount();
	c.getcount();
	a.getdata(100);
	item::showcount();          //访问静态函数
	b.getdata(200);
	item::showcount();          //访问静态函数
	c.getdata(300);
	item::showcount();          //访问静态函数
	cout << "After reading data" << "\n";
	a.getcount();
	b.getcount();
	c.getcount();
	system("pause");
	return 0;
}