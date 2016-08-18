// 10.3 lambda��bind����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//lambdaֵ����
void fcn1()
{
	size_t v1 = 8;
	auto f = [v1] {return v1; };
	v1 = 1;
	auto g = f();
	auto g2 = g;
}
//lambda���ò�����ȷ��ִ��lambdaʱ���ö����Ǵ��ڵ�
void fcn2()
{
	int a = 3;
	auto f1 = [&a] {return a; };
	a = 0;
	cout << f1() << endl;
}
//ֵ����ɱ�lambda
void fcn3()
{
	int v1 = 42;
	auto f = [=]() mutable {return ++v1; };
	v1 = 0;
	cout << "f3��" << f() << endl;
}
//���ò���ɱ�lambda
void fcn4()
{
	int v1 = 42;
	auto f2 = [&]{return ++v1; };
	v1 = 2;
	cout << "fcn4��" << f2() << endl;
}
//ָ��lambda�������� transform()����������Χ���滻��ָ��λ��
void fcn5()
{
	vector<int> v = {-1,2,-3,4,-5,6,-7,8,-9};
	//transform(v.begin(), v.end(), v.begin(), [](int i) {return i < 0 ? -i : i; });
	transform(v.begin(), v.end(), v.begin(), [](int i)->int {if (i > 0) return i; else return -i; });
	cout << "fcn5��" << ends;
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

