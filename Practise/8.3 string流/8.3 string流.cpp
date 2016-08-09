// 8.3 string流.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
struct PersonInfo
{
	string name;
	vector<string> phones;
};
//8.3.1 使用istringstream
void phoneNotesEval1();
//8.3.2 使用ostringstream
void phoneNotesEval2(vector<PersonInfo> &);

int main()
{
	phoneNotesEval1();
	system("pause");
    return 0;
}
void phoneNotesEval1()
{
	string line, world;
	vector<PersonInfo> peoples;
	ifstream open("C:\\Users\\zhoukb\\Desktop\\电话簿.txt");//打开一个文件流
	istringstream record;//从流中读取字符串
	while (getline(open, line))
	{
		record.str(line);
		PersonInfo item;	
		record >> item.name; //读取名字
		while (record>>world)
		{
			item.phones.push_back(world); //保存每个电话
		}
		peoples.push_back(item);//保存每个item
		record.clear();
	}
	//迭代器遍历输出peoples内容
	vector<PersonInfo>::iterator k = peoples.begin();
	while (k != peoples.end())
	{
		int i = 1;
		cout <<"姓名："<< (*k).name << ends;
		vector<string>::iterator k2 = (*k).phones.begin();
		while (k2!= (*k).phones.end())
		{
			cout << "电话" <<i++<<"："<< *k2 << ends;
			k2++;
		}
		k++;
		cout << endl;		
	}
	cout << "迭代器遍历输出完毕" << endl<<endl;
	phoneNotesEval2(peoples);
}
void phoneNotesEval2(vector<PersonInfo> &peoples)
{
	for each (auto peopleItem in peoples)
	{
		ostringstream numbers; //向流中写入字符串（栈结构）
		int i = 1;
		for each (auto phoneItem in peopleItem.phones)
		{
			numbers << "电话"<<i++<<"为："<<phoneItem<<" ";
		}
		cout << peopleItem.name << ends << numbers.str() << endl;
	}
	cout << "泛型for each遍历输出完毕" << endl;
}