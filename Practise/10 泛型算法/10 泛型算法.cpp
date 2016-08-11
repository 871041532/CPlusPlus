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
	//copy 算法 参数三个迭代器，起始迭代器，终止迭代器， 目标容器起始迭代器。返回值为目的位置递增后的值。
	int a1[] = {1,2,3,4,5,6,7,8,9};
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);//指向end(a2)
	cout << "a2的值为：" << flush;
	for each (auto var in a2)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << (ret == end(a2) ? "ret返回目的位置递增后的迭代器" : "ret未返回目的位置递增后的迭代器" )<< endl;
	//replace 将序列中所有等于定值的元素替换为另一个值，改变原有序列
	//replac_copy将序列中所有等于定值的元素替换为另一个值，原序列不变，返回一个新序列。
	//replace参数为4个，起始位置迭代器，终止位置迭代器，定值元素，要替换的定值元素
	//replac_copy参数5个，起始位置，终止位置，目标序列插入迭代器，定值元素，要替换的元素
	vector<int> v5 = { 1,2,3,4,5};
	vector<int> v6;
    replace(v5.begin(), v5.end(),1,42);
	replace_copy(v5.begin(), v5.end(),back_inserter(v6),42,25);
	cout << "v5的值为：" << endl;
	for each (auto var in v5)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << "v6的值为" << endl;
	for each (auto var in v6)
	{
		cout << var << ends;
	}
	cout << endl;
	//sort算法 需要 < 运算符重载 参数2：起始位置迭代器，终止位置迭代器
	vector<string> ss1 = {"fox","over","jumps","over","quick","jumps","red","slow","red","the","turtle "};
	//先排序以查找重复单词
	sort(ss1.begin(), ss1.end());
	//unique去除相邻重复元素,指向不重复区域之后一个位置的迭代器
	//unique标准算法库并不直接删除元素而是“擦除“，不会使迭代器失效。返回迭代器其后元素值依然存在，值未知。
	auto end_unique = unique(ss1.begin(), ss1.end());
	//删除重复单词（为了真正删除元素，必须使用容器操作）
	ss1.erase(end_unique,ss1.end());
	cout << "排序去重后的ss1值为：" << flush;
	for each (auto var in ss1)
	{
		cout << var << ends;//std::string <<运算符重载定义在sstream头文件中
	}
	cout << endl;
	system("pause");
    return 0;
}

