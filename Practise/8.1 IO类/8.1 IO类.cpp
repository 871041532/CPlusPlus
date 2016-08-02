// 8.1 IO类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	cout << 1;
	auto bool1=cout.good();
	auto bool2 = cout.eof();
	cout << endl;
	getchar();
    return 0;
}
