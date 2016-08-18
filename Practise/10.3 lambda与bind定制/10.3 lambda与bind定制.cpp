// 10.3 lambda与bind定制.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//lambda值捕获
void fcn1()
{
	size_t v1 = 8;
	auto f = [v1] {return v1; };
	v1 = 1;
	auto g = f();
	auto g2 = g;
}
//lambda引用捕获。需确保执行lambda时引用对象是存在的
void fcn2()
{
	int a = 3;
	auto f1 = [&a] {return a; };
	a = 0;
	cout << f1() << endl;
}
//值捕获可变lambda
void fcn3()
{
	int v1 = 42;
	auto f = [=]() mutable {return ++v1; };
	v1 = 0;
	cout << "f3：" << f() << endl;
}
//引用捕获可变lambda
void fcn4()
{
	int v1 = 42;
	auto f2 = [&]{return ++v1; };
	v1 = 2;
	cout << "fcn4：" << f2() << endl;
}
//指定lambda返回类型 transform()函数遍历范围并替换到指定位置
void fcn5()
{
	vector<int> v = {-1,2,-3,4,-5,6,-7,8,-9};
	//transform(v.begin(), v.end(), v.begin(), [](int i) {return i < 0 ? -i : i; });
	transform(v.begin(), v.end(), v.begin(), [](int i)->int {if (i > 0) return i; else return -i; });
	cout << "fcn5：" << ends;
	for_each(v.begin(), v.end(), [](int i) {cout << i << ends; });
}
int main()
{
	fcn1();
	fcn2();
	fcn3();
	fcn4();
	fcn5();
	system("pause");
    return 0;
}

