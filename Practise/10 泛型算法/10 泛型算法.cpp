// 10 泛型算法.cpp : 定义控制台应用程序的入口点。
//
//泛型算法不执行容器操作不改变容器大小；但依赖于容器中元素的操作符重载操作。
#include "stdafx.h"
//只读泛型算法
//find查找
void generic_find()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	auto result1 = find(v1.begin(), v1.end(), 1);
	auto result2 = find(v1.begin(), v1.end(), 6);
	if (result1 != v1.end()) cout << "v1中找到了该元素：" << *result1 << endl;
	else cout << "v1中没有元素1" << endl;
	if (result2 != v1.end()) cout << "v1中找到了该元素：" << *result2 << endl;
	else cout << "v1中没有元素6" << endl;
}
//accumulate 元素求和（会隐式转换元素类型）
void generic_accumulate()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	auto result3 = accumulate(v1.cbegin(), v1.cend(), 0);
	cout << "v1中所有元素和为：" << result3 << endl;
}
//equal 比较v1与v2是否相等（前提是v1与v2中元素数目相等,容器类型无要求）
void generic_equal()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	//equal 比较v1与v2是否相等（前提是v1与v2中元素数目相等,容器类型无要求）
	auto result = equal(v1.cbegin(), v1.cend(), v2.begin());
	cout << (result ? "v1与v2中元素相等" : "v1与v2不相等") << endl;
}
//fill 将容器范围内的元素用指定元素替换
void generic_fill()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	fill(v3.begin(), v3.end(), 1.1);
	cout << "容器中的元素被替换后新值为：" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
}
//fill_n与back_inserter 泛型插入2与插入迭代器
void generic_fill_nAndback_inserter()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	fill_n(back_inserter(v3), 20, 0);//添加20个元素0到v3中
	cout << "容器v3插入20个元素后的新值为：" << flush;
	for each (auto var in v3)
	{
		cout << var << ends;
	}
	cout << endl;
}
//copy 算法 参数三个迭代器，起始迭代器，终止迭代器， 目标容器起始迭代器。返回值为目的位置递增后的值。
void generic_copy()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	int a1[] = { 1,2,3,4,5,6,7,8,9 };
	int a2[sizeof(a1) / sizeof(*a1)];
	auto ret = copy(begin(a1), end(a1), a2);//指向end(a2)
	cout << "a2的值为：" << flush;
	for each (auto var in a2)
	{
		cout << var << ends;
	}
	cout << endl;
	cout << (ret == end(a2) ? "ret返回目的位置递增后的迭代器" : "ret未返回目的位置递增后的迭代器") << endl;
}
/*replace 将序列中所有等于定值的元素替换为另一个值，改变原有序列
//replac_copy将序列中所有等于定值的元素替换为另一个值，原序列不变，返回一个新序列。
//replace参数为4个，起始位置迭代器，终止位置迭代器，定值元素，要替换的定值元素
//replac_copy参数5个，起始位置，终止位置，目标序列插入迭代器，定值元素，要替换的元素*/
void generic_replaceAndreplace_copy()
{
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2 = { 1,2,3,4,5,6 };
	vector<double> v3 = { 1.3,2.3,3.3,4.3,5.3 };
	vector<int> v5 = { 1,2,3,4,5 };
	vector<int> v6;
	replace(v5.begin(), v5.end(), 1, 42);
	replace_copy(v5.begin(), v5.end(), back_inserter(v6), 42, 25);
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
}
//sort算法 需要 < 运算符重载 参数2：起始位置迭代器，终止位置迭代器
//unique去除相邻重复元素,指向不重复区域之后一个位置的迭代器
void generic_sortAndunique()
{
	vector<string> ss1 = { "fox","over","jumps","over","quick","jumps","red","slow","red","the","turtle " };
	//先排序以查找重复单词
	sort(ss1.begin(), ss1.end());
	//unique标准算法库并不直接删除元素而是“擦除“，不会使迭代器失效。返回迭代器其后元素值依然存在，值未知。
	auto end_unique = unique(ss1.begin(), ss1.end());
	//删除重复单词（为了真正删除元素，必须使用容器操作）
	ss1.erase(end_unique, ss1.end());
	cout << "排序去重后的ss1值为：" << flush;
	for each (auto var in ss1)
	{
		cout << var << ends;//std::string <<运算符重载定义在sstream头文件中
	}
	cout << endl;
}
//sort 算法谓词参数，起始位置迭代器，终止位置迭代器，返回值为bool的谓词函数名 （内部满足谓词则不替换位置）
bool isSatisfySort(const int& a,const int& b)
{
	return a > b;
}
void generic_sortWeiCi()
{
	vector<int> v = { 8,234,56,546,768,768,2 };
	sort(v.begin(), v.end(), isSatisfySort);
	cout << "排序后的数组为：" << flush;
	for each (auto var in v)
	{
		cout << var << ends;
	}
	cout << endl;
}
//stable_sort 起始迭代器，终止迭代器，谓词函数。在sort排序的基础上，将相等元素重载<运算符再排序
bool isSatisfySS(const string& s1, const string& s2)
{
	return s1.size() > s2.size();
}
void generic_stable_sort()
{
	vector<string> v = {"fox","red","the","over","slow","jumps","quick","sturtle"};
	stable_sort(v.begin(),v.end(),isSatisfySS);
	cout << "排序后的数组为：" << flush;
	for each (auto var in v)
	{   
		cout << var << ends;        
	}
	cout << endl;
}      
//practise 10.12 定义结构体，按照某种规则将其排序
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
	friends f1; f1.name = "小赵"; f1.isbn = 1;
	friends f3; f3.name = "小钱"; f3.isbn = 3;
	friends f2; f2.name = "小孙"; f2.isbn = 2;
	friends f5; f5.name = "小李"; f5.isbn = 5;
	friends f4; f4.name = "小周"; f4.isbn = 4;
	vector<friends> v = { f1,f3,f2,f5,f4 };
	sort(v.begin(), v.end(), isSatisfyBn);
	cout << "排序后的好友为：" << endl;
	for each (auto var in v)
	{
		cout << "\t" << var.name << " isbn：" << var.isbn << endl;
	}
	cout << endl;
}
//practise 10.13   one定义算法检测字符串是否有五个元素，two：将vector<string> words 使用partition算法排序，改算法作用是将谓词为true的放在容器的前半部分，false的放在后半部分；返回一个迭代器指向最后一个true元素之后位置。
//打印出容器words中元素个数大于5的所有元素
bool checkString(const string& s)
{
	return s.size() > 4;
}
void evalWords()
{
	vector<string> words = { "fox","red","the","over","slow","jumps","quick","sturtle" };
	auto pEnd = partition(words.begin(), words.end(), checkString);
	words.erase(pEnd,words.end());
	cout << "长度大于等于5的元素有：" << endl;
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

