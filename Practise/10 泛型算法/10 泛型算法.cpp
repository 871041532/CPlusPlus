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
	//copy �㷨 ������������������ʼ����������ֹ�������� Ŀ��������ʼ������������ֵΪĿ��λ�õ������ֵ��
	int a1[] = {1,2,3,4,5,6,7,8,9};
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);//ָ��end(a2)
	cout << "a2��ֵΪ��" << flush;
	for each (auto var in a2)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << (ret == end(a2) ? "ret����Ŀ��λ�õ�����ĵ�����" : "retδ����Ŀ��λ�õ�����ĵ�����" )<< endl;
	//replace �����������е��ڶ�ֵ��Ԫ���滻Ϊ��һ��ֵ���ı�ԭ������
	//replac_copy�����������е��ڶ�ֵ��Ԫ���滻Ϊ��һ��ֵ��ԭ���в��䣬����һ�������С�
	//replace����Ϊ4������ʼλ�õ���������ֹλ�õ���������ֵԪ�أ�Ҫ�滻�Ķ�ֵԪ��
	//replac_copy����5������ʼλ�ã���ֹλ�ã�Ŀ�����в������������ֵԪ�أ�Ҫ�滻��Ԫ��
	vector<int> v5 = { 1,2,3,4,5};
	vector<int> v6;
    replace(v5.begin(), v5.end(),1,42);
	replace_copy(v5.begin(), v5.end(),back_inserter(v6),42,25);
	cout << "v5��ֵΪ��" << endl;
	for each (auto var in v5)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << "v6��ֵΪ" << endl;
	for each (auto var in v6)
	{
		cout << var << ends;
	}
	cout << endl;
	//sort�㷨 ��Ҫ < ��������� ����2����ʼλ�õ���������ֹλ�õ�����
	vector<string> ss1 = {"fox","over","jumps","over","quick","jumps","red","slow","red","the","turtle "};
	//�������Բ����ظ�����
	sort(ss1.begin(), ss1.end());
	//uniqueȥ�������ظ�Ԫ��,ָ���ظ�����֮��һ��λ�õĵ�����
	//unique��׼�㷨�Ⲣ��ֱ��ɾ��Ԫ�ض��ǡ�������������ʹ������ʧЧ�����ص��������Ԫ��ֵ��Ȼ���ڣ�ֵδ֪��
	auto end_unique = unique(ss1.begin(), ss1.end());
	//ɾ���ظ����ʣ�Ϊ������ɾ��Ԫ�أ�����ʹ������������
	ss1.erase(end_unique,ss1.end());
	cout << "����ȥ�غ��ss1ֵΪ��" << flush;
	for each (auto var in ss1)
	{
		cout << var << ends;//std::string <<��������ض�����sstreamͷ�ļ���
	}
	cout << endl;
	system("pause");
    return 0;
}

