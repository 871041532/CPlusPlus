// 10 �����㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�����㷨��ִ�������������ı�������С����������������Ԫ�صĲ��������ز�����
#include "stdafx.h"
int main()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = {1.3,2.3,3.3,4.3,5.3};
	//ֻ�������㷨
	//find ����
	auto result1 = find(v1.begin(), v1.end(), 1);
	auto result2 = find(v1.begin(), v1.end(), 6);
	if (result1 != v1.end()) cout << "v1���ҵ��˸�Ԫ�أ�" << *result1 << endl;
	else cout << "v1��û��Ԫ��1" << endl;
	if (result2 != v1.end()) cout << "v1���ҵ��˸�Ԫ�أ�" << *result2 << endl;
	else cout << "v1��û��Ԫ��6" << endl;
	//accumulate Ԫ����ͣ�����ʽת��Ԫ�����ͣ�
	auto result3 = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << "v1������Ԫ�غ�Ϊ��" << result3 << endl;
	//equal �Ƚ�v1��v2�Ƿ���ȣ�ǰ����v1��v2��Ԫ����Ŀ���,����������Ҫ��
	auto result = equal(v1.cbegin(), v1.cend(), v2.begin());
	cout <<(result? "v1��v2��Ԫ�����":"v1��v2�����" )<< endl;
	//fill ��������Χ�ڵ�Ԫ����ָ��Ԫ���滻
	fill(v3.begin(), v3.end(), 1.1);
	cout << "�����е�Ԫ�ر��滻����ֵΪ��" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
	//fill_n��back_inserter ���Ͳ���2����������
	fill_n(back_inserter(v3), 20, 0);//���20��Ԫ��0��v3��
	cout << "����v3����20��Ԫ�غ����ֵΪ��" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
	system("pause");
    return 0;
}

