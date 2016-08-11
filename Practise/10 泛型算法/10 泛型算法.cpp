// 10 泛型算法.cpp : 定义控制台应用程序的入口点。
//
//泛型算法不执行容器操作不改变容器大小；但依赖于容器中元素的操作符重载操作。
#include "stdafx.h"
int main()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = {1.3,2.3,3.3,4.3,5.3};
	//只读泛型算法
	//find 查找
	auto result1 = find(v1.begin(), v1.end(), 1);
	auto result2 = find(v1.begin(), v1.end(), 6);
	if (result1 != v1.end()) cout << "v1中找到了该元素：" << *result1 << endl;
	else cout << "v1中没有元素1" << endl;
	if (result2 != v1.end()) cout << "v1中找到了该元素：" << *result2 << endl;
	else cout << "v1中没有元素6" << endl;
	//accumulate 元素求和（会隐式转换元素类型）
	auto result3 = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << "v1中所有元素和为：" << result3 << endl;
	//equal 比较v1与v2是否相等（前提是v1与v2中元素数目相等,容器类型无要求）
	auto result = equal(v1.cbegin(), v1.cend(), v2.begin());
	cout <<(result? "v1与v2中元素相等":"v1与v2不相等" )<< endl;
	//fill 将容器范围内的元素用指定元素替换
	fill(v3.begin(), v3.end(), 1.1);
	cout << "容器中的元素被替换后新值为：" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
	//fill_n与back_inserter 泛型插入2与插入迭代器
	fill_n(back_inserter(v3), 20, 0);//添加20个元素0到v3中
	cout << "容器v3插入20个元素后的新值为：" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
	system("pause");
    return 0;
}

