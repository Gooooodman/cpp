//友元函数
//声明是使用friend关键词的函数被称为友元函数，一个函数可在任意多个类中声明为友元
//友元函数虽然不是类的成员函数，但对类的私有数据有完全访问的权限
//友元函数的特性如下:
//1.友元函数声明于类内，但它的作用域不在类内
//2.因为友元函数的作用域不在类内，所以它不可被类对象调用
//3.不使用对象，友元函数和常规函数一样能被调用
//4.和成员函数不同的是，友元函数不可直接访问成员，而是借助于一个对象和点隶属操作符，
//才能访问对象的各个成员（比如A.x）
//5.友元函数可以声明在类的公共或私有部分，不影响其意义
//6.通常情况下，友元函数的自变量是对象
#include<iostream>
using namespace std;
class class_2;               //前置声明
class class_1
{
private:
	int value1;
public:
	void indata(int a)
	{
		value1 = a;
	}
	void display(void)
	{
		cout << value1 << "\n";
	}
	friend void exchange(class_1&,class_2&);
};
class class_2
{
	int value2;
	public:
	void indata(int a)
	{
		value2 = a;
	}
	void display(void)
	{
		cout << value2 << "\n";
	}
	friend void exchange(class_1&, class_2&);
};
//交换类的私有数据
void exchange(class_1& x, class_2& y)   //友元函数的定义
{
	int temp = x.value1;
	x.value1 = y.value2;
	y.value2 = temp;
}
int main()
{
	class_1 C1;
	class_2 C2;
	C1.indata(100);
	C2.indata(200);
	cout << "Values before exchange " << "\n";
	C1.display();
	C2.display();
	exchange(C1,C2);    //传递的是对象的指针
	cout << "Values after exchange " << "\n";
	C1.display();
	C2.display();
	system("pause");
	return 0;
}