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
//8.3.2 使用stringstream类型转换
void convertType();
//8.3.4 李白诗集精校
void evalLiBai1();
int main()
{
	//phoneNotesEval1();
	//convertType();
	evalLiBai1();
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
	vector<PersonInfo>::iterator k = peoples.begin(); //auto k=peoples.begin();
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
void convertType()
{
	int v1;
	double v2;
	string s1;
	stringstream media;
	cin >> s1;
	//media.str(s1);
	media << s1;
	media >> v1;
	cout <<"输入的字符串转换为int："<< v1<<endl;

	string s2;
	//media.clear();
	stringstream media2;
	media2 << 231;
	media2 >> s2;
	cout << "int型231转换为字符串为：" << s2 << endl;

}
void eraseChildString(string& father,const string child) //删除字符串中所有子串
{
	int childLength = child.length();
	int pos = father.find(child);
	if (pos!=string::npos) eraseChildString(father.erase(pos, childLength),child);//递归调用
	else return;
}
void evalLiBai1()
{
	ifstream readLiBai("C:\\Users\\zhoukb\\Desktop\\李白诗集.txt");
	ofstream writeLiBai("C:\\Users\\zhoukb\\Desktop\\李白诗集精校版.txt");//追加模式
	string lastLine="  ";
	string line;
	int lineNumber= 1;
	while (getline(readLiBai,line))
	{  
		cout << "撸" << lineNumber ++<<"行："<< line << endl;
		//去字母
		for (size_t i =65 ; i < 91; i++)
		{
			char tempChar = i;
			string tempChild(1, tempChar);
			eraseChildString(line, tempChild);
		}
		eraseChildString(line, ">");
		eraseChildString(line, " ");
		eraseChildString(line, "\t");
		eraseChildString(line, "唐·");
		//eraseChildString(line, "李白");
		eraseChildString(line, "--引自\"超纯斋诗词\"bookbest.163.net翻译、评析：刘建勋");
		if (line.find("光明日报") != string::npos || line.find("全唐诗") != string::npos) line = ""; //诗是写景的。唐
		bool b1 = line.find("。") == line.length() - 1;
		eraseChildString(line, "李白");
		if (b1) writeLiBai << line + "\n";
		else writeLiBai << line;
		lastLine = line;
	}
	cout << "精校完毕，共"<< --lineNumber<<"行" << endl;
}

