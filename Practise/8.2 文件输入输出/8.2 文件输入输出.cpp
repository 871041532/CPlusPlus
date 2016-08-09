// 8.2 文件输入输出.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//8.2.1 使用文件流对象
void usingFstream();
//8.2.2文件模式
void IOModule();
int main()
{
	//usingFstream();
	//IOModule();
	system("pause");
    return 0;
}
void usingFstream()
{
	//输入流关联到指定文件，从文件中读取数据（文件不存在，则流状态无效，failbit置位）
	ifstream input("C:\\Users\\zhoukb\\Desktop\\日志.txt");
	string content;
	string tmp;
	//while (input >> tmp)//输入单个单词以空格结束
	while(getline(input,tmp))//获得每一行的内容
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
void IOModule()
{
	/*
		in 以读方式打开
		out 以写方式打开
		app 追加模式，每次写操作前均指定到文件末尾
		ate 打开文件后立即定位到文件末尾
		trunc 截断文件
		binary 以二进制方式进行IO
	*/
	//截断。以下三条语句等价
	ofstream out1("C:\\Users\\zhoukb\\Desktop\\实验.txt");//隐含out | trunc：以输出模式打开文件并截断
	ofstream out2("C:\\Users\\zhoukb\\Desktop\\实验.txt",ofstream::out);//隐含trunc截断文件
	ofstream out3("C:\\Users\\zhoukb\\Desktop\\实验.txt", ofstream::out | ofstream::trunc);
	//不截断文件，追加模式。以下两条语句等价
	ofstream out4("C:\\Users\\zhoukb\\Desktop\\实验.txt", ofstream::app); //隐含out
	out4 << "hello";
	out4 << " world";
	out4.close();//不close则不写入追加到文件头位置。当文件再次被open时定位为空，同时写入。
	ofstream out5("C:\\Users\\zhoukb\\Desktop\\实验.txt", ofstream::app | ofstream::out);
	out5 << "插"<<"入：";
}