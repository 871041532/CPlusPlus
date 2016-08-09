// 8.2 文件输入输出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//8.2.1 使用文件流对象
void usingFstream();
int main()
{
	usingFstream();
	system("pause");
    return 0;
}
void usingFstream()
{
	//输入流关联到指定文件，从文件中读取数据（文件不存在，则流状态无效，failbit置位）
	ifstream input("C:\\Users\\zhoukb\\Desktop\\日志.txt");
	string content;
	string tmp;
	while (input >> tmp)
	{
		content = content + tmp + "\n";
	}
	if (content != "")
	{
		cout << "文件原内容为：" << endl;
		cout << content << endl;
	}
	else
	{
		cout << "嘉年华" << endl;
	}
	input.open("C:\\Users\\zhoukb\\Desktop\\书签.txt");
	cout << "\n请输入新内容：" << endl;
	getline(cin, content);
	if (content!="")
	{
		//输出流关联到指定文件，向文件中写入数据（该文件不存在则创建,已有则清空数据）
		ofstream output("temp.txt");
		output << content;
		output.close();
	}
	input.close();
}
