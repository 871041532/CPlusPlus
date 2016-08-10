// 9.2 容器库概览.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//9.2.1 迭代器
bool finding(vector<int>&, int&);
vector<int>::iterator finding2(vector<int>&, int&);
void compareV1AndV2();
int main()
{
	vector<int> v = { 1,3,2,3,4,3,5,6,7,3,8 };
	//int a = 8;
	//auto k = (finding2(v, a));
	//if (k!=v.end()) cout << *k << endl;
	//vector<int> v1 = { 1,2,3,4,5,6,7 };
	//vector<int> v2 = { 1,2,3,4,5,6,7,8 };
	//list<int>l1 = { 1,2,3,4,5,6,7,8 };
	//cout << "v和v1是否相等" <<( v == v1 )<< endl;
	//cout << "v和v1是否相等" << (v == v2) << endl;
	int a2 = 3;
	auto result = find(v.begin(), v.end(), a2); //泛型算法，在集合中查找元素，找到返回指向它的迭代器否则返回8
	if (result != v.end()) cout <<"已找到元素："<< *result << endl;
	cout << "3在容器中出现的次数为" << count(v.begin(), v.end(), 3) << endl;
	cout << "7在容器中出现的次数为" << count(v.begin(), v.end(), 7) << endl;
	cout << "10在容器中出现的次数为" << count(v.begin(), v.end(), 10) << endl;

	system("pause");
    return 0;
}
bool finding(vector<int> &v1, int &a)
{
	for (auto k = v1.begin(); k!=v1.end();k++)
	{
		if (*k==a)
		{
			return true;
		}
	}
	return false;
}
vector<int>::iterator finding2(vector<int>& v1, int& a)
{
	for (auto k = v1.begin(); k != v1.end(); k++)
	{
		if (*k == a)
		{
			return k;
		}
	}
	return v1.end();
}