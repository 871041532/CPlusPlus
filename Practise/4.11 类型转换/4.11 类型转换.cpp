// 4.11 类型转换.cpp : 定义控制台应用程序的入口点。
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

