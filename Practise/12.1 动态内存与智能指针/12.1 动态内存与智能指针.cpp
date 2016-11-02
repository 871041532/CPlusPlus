// 12.1 动态内存与智能指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Person.h"

int main()
{
	Person* a =new Person("Tom", 12);
	cout << *a;
	delete a;
	system("pause");
    return 0;
}

