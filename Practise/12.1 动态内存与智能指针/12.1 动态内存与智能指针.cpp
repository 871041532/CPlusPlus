// 12.1 ��̬�ڴ�������ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
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

