// 9.2 ���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//9.2.1 ������
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
	//cout << "v��v1�Ƿ����" <<( v == v1 )<< endl;
	//cout << "v��v1�Ƿ����" << (v == v2) << endl;
	int a2 = 3;
	auto result = find(v.begin(), v.end(), a2); //�����㷨���ڼ����в���Ԫ�أ��ҵ�����ָ�����ĵ��������򷵻�8
	if (result != v.end()) cout <<"���ҵ�Ԫ�أ�"<< *result << endl;
	cout << "3�������г��ֵĴ���Ϊ" << count(v.begin(), v.end(), 3) << endl;
	cout << "7�������г��ֵĴ���Ϊ" << count(v.begin(), v.end(), 7) << endl;
	cout << "10�������г��ֵĴ���Ϊ" << count(v.begin(), v.end(), 10) << endl;

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