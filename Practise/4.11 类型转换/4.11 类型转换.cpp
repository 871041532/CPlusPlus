// 4.11 ����ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	const char* a = "12345";
	cout << static_cast<int>(*a)<<endl;
	cout << const_cast<const char*>(a) << endl;
	getchar();
    return 0;
}

