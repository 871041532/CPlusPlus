// 10 �����㷨.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�����㷨��ִ�������������ı�������С����������������Ԫ�صĲ��������ز�����
#include "stdafx.h"
//ֻ�������㷨
//find����
void generic_find()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	auto result1 = find(v1.begin(), v1.end(), 1);
	auto result2 = find(v1.begin(), v1.end(), 6);
	if (result1 != v1.end()) cout << "v1���ҵ��˸�Ԫ�أ�" << *result1 << endl;
	else cout << "v1��û��Ԫ��1" << endl;
	if (result2 != v1.end()) cout << "v1���ҵ��˸�Ԫ�أ�" << *result2 << endl;
	else cout << "v1��û��Ԫ��6" << endl;
}
//accumulate Ԫ����ͣ�����ʽת��Ԫ�����ͣ�
void generic_accumulate()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	auto result3 = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << "v1������Ԫ�غ�Ϊ��" << result3 << endl;
}
//equal �Ƚ�v1��v2�Ƿ���ȣ�ǰ����v1��v2��Ԫ����Ŀ���,����������Ҫ��
void generic_equal()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	//equal �Ƚ�v1��v2�Ƿ���ȣ�ǰ����v1��v2��Ԫ����Ŀ���,����������Ҫ��
	auto result = equal(v1.cbegin(), v1.cend(), v2.begin());
	cout << (result ? "v1��v2��Ԫ�����" : "v1��v2�����") << endl;
}
//fill ��������Χ�ڵ�Ԫ����ָ��Ԫ���滻
void generic_fill()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	fill(v3.begin(), v3.end(), 1.1);
	cout << "�����е�Ԫ�ر��滻����ֵΪ��" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
}
//fill_n��back_inserter ���Ͳ���2����������
void generic_fill_nAndback_inserter()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	fill_n(back_inserter(v3), 20, 0);//���20��Ԫ��0��v3��
	cout << "����v3����20��Ԫ�غ����ֵΪ��" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
}
//copy �㷨 ������������������ʼ����������ֹ�������� Ŀ��������ʼ������������ֵΪĿ��λ�õ������ֵ��
void generic_copy()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	int a1[] = { 1,2,3,4,5,6,7,8,9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);//ָ��end(a2)
	cout << "a2��ֵΪ��" << flush;
	for each (auto var in a2)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << (ret == end(a2) ? "ret����Ŀ��λ�õ�����ĵ�����" : "retδ����Ŀ��λ�õ�����ĵ�����") << endl;
}
/*replace �����������е��ڶ�ֵ��Ԫ���滻Ϊ��һ��ֵ���ı�ԭ������
//replac_copy�����������е��ڶ�ֵ��Ԫ���滻Ϊ��һ��ֵ��ԭ���в��䣬����һ�������С�
//replace����Ϊ4������ʼλ�õ���������ֹλ�õ���������ֵԪ�أ�Ҫ�滻�Ķ�ֵԪ��
//replac_copy����5������ʼλ�ã���ֹλ�ã�Ŀ�����в������������ֵԪ�أ�Ҫ�滻��Ԫ��*/
void generic_replaceAndreplace_copy()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	vector<int> v5 = { 1,2,3,4,5 };
	vector<int> v6;
	replace(v5.begin(), v5.end(), 1, 42);
	replace_copy(v5.begin(), v5.end(), back_inserter(v6), 42, 25);
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
}
//sort�㷨 ��Ҫ < ��������� ����2����ʼλ�õ���������ֹλ�õ�����
//uniqueȥ�������ظ�Ԫ��,ָ���ظ�����֮��һ��λ�õĵ�����
void generic_sortAndunique()
{
	vector<string> ss1 = { "fox","over","jumps","over","quick","jumps","red","slow","red","the","turtle " };
	//�������Բ����ظ�����
	sort(ss1.begin(), ss1.end());
	//unique��׼�㷨�Ⲣ��ֱ��ɾ��Ԫ�ض��ǡ�������������ʹ������ʧЧ�����ص��������Ԫ��ֵ��Ȼ���ڣ�ֵδ֪��
	auto end_unique = unique(ss1.begin(), ss1.end());
	//ɾ���ظ����ʣ�Ϊ������ɾ��Ԫ�أ�����ʹ������������
	ss1.erase(end_unique, ss1.end());
	cout << "����ȥ�غ��ss1ֵΪ��" << flush;
	for each (auto var in ss1)
	{
		cout << var << ends;//std::string <<��������ض�����sstreamͷ�ļ���
	}
	cout << endl;
}
//sort �㷨ν�ʲ�������ʼλ�õ���������ֹλ�õ�����������ֵΪbool��ν�ʺ����� ���ڲ�����ν�����滻λ�ã�
bool isSatisfySort(const int& a,const int& b)
{
	return a > b;
}
void generic_sortWeiCi()
{
	vector<int> v = { 8,234,56,546,768,768,2 };
	sort(v.begin(), v.end(), isSatisfySort);
	cout << "����������Ϊ��" << flush;
	for each (auto var in v)
	{
		cout << var << ends;
	}
	cout << endl;
}
//stable_sort ��ʼ����������ֹ��������ν�ʺ�������sort����Ļ����ϣ������Ԫ������<�����������
bool isSatisfySS(const string& s1, const string& s2)
{
	return s1.size() > s2.size();
}
void generic_stable_sort()
{
	vector<string> v = {"fox","red","the","over","slow","jumps","quick","sturtle"};
	stable_sort(v.begin(),v.end(),isSatisfySS);
	cout << "����������Ϊ��" << flush;
	for each (auto var in v)
	{   
		cout << var << ends;        
	}
	cout << endl;
}      
//practise 10.12 ����ṹ�壬����ĳ�ֹ���������
struct friends
{
	string name;
	int isbn;
};
bool isSatisfyBn(const friends&f1,const friends&f2)
{
	return f1.isbn < f2.isbn;
}
void compareIsbn()
{
	friends f1; f1.name = "С��"; f1.isbn = 1;
	friends f3; f3.name = "СǮ"; f3.isbn = 3;
	friends f2; f2.name = "С��"; f2.isbn = 2;
	friends f5; f5.name = "С��"; f5.isbn = 5;
	friends f4; f4.name = "С��"; f4.isbn = 4;
	vector<friends> v = { f1,f3,f2,f5,f4 };
	sort(v.begin(), v.end(), isSatisfyBn);
	cout << "�����ĺ���Ϊ��" << endl;
	for each (auto var in v)
	{
		cout << "\t" << var.name << " isbn��" << var.isbn << endl;
	}
	cout << endl;
}
//practise 10.13   one�����㷨����ַ����Ƿ������Ԫ�أ�two����vector<string> words ʹ��partition�㷨���򣬸��㷨�����ǽ�ν��Ϊtrue�ķ���������ǰ�벿�֣�false�ķ��ں�벿�֣�����һ��������ָ�����һ��trueԪ��֮��λ�á�
//��ӡ������words��Ԫ�ظ�������5������Ԫ��
bool checkString(const string& s)
{
	return s.size() > 4;
}
void evalWords()
{
	vector<string> words = { "fox","red","the","over","slow","jumps","quick","sturtle" };
	auto pEnd = partition(words.begin(), words.end(), checkString);
	words.erase(pEnd,words.end());
	cout << "���ȴ��ڵ���5��Ԫ���У�" << endl;
	for each (auto var in words)
	{
		cout << var << ends;
	}
	cout << endl;
}

int main()
{
	vector<int> v1 = {1,2,3,4,5};
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = {1.3,2.3,3.3,4.3,5.3};	
	evalWords();
	system("pause");
    return 0;
}

