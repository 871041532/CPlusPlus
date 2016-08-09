// 8.1 IO类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//8.1.2 条件状态接受一个istream&参数，返回值类型也是istream&。从输入流中读取数据知道遇到文件结束标志停止。并打印在标准输出
istream& readForm(istream&);
//8.1.3 刷新输出缓冲区
void buffRefresh();
//8.1.3 关联输入输出流
void relationIOstream();
int main()
{
	////ostream函数 
	//auto bool1=cout.good();
	//auto bool2 = cout.eof();
	//cout <<"输出流是否正常:" <<bool1 << " " <<"输出流是否结束:"<< bool2 << endl;
	////istream
	//string a;
	//auto old_state = cin.rdstate(); //cin的当前状态
	//cin.clear(); //使cin有效
	//cin >> a;//使用cin
	//cin.setstate(old_state);//将cin置为原有状态
	//cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);//复位failbit环绕badbit，保持其他位不变
	//readForm(cin);
	//buffRefresh();
	relationIOstream();
	getchar();
    return 0;
}

istream& readForm(istream& istre)
{
	auto oldState = istre.rdstate();
	string a;
	getline(istre, a);
	cout << a;
	istre.setstate(oldState);
	return istre;
}
void buffRefresh()
{
	cout << "hi" << endl;//刷新缓冲区并换行
	cout << "world" << ends;//刷新缓冲区并换空格
	cout << "llo" << flush;//刷新缓冲区无操作
	//unitbuf操作符
	cout << unitbuf;//所有输出操作都会立即刷新缓冲区
	cout << nounitbuf;//回到正常流模式
	cin >> unitbuf;
	cin >> nounitbuf;
}
void relationIOstream()
{
	//对象方法cin.tie：两个重载①不带参数重载返回此流所关联的输出流指针，如未关联返回空指针。
	//②接受一个ostream指针，将自身关联到此输出流。关联的好处是：任何从输入流读取数据的操作都会刷新相关联的输出流
	cin.tie(&cout);//cin与cout相关联
	ostream *old_tie = cin.tie(); //获得与cin相关联的输出流
	if (old_tie)
	{
		*old_tie << "与cin相关联的ostream对象不为空" << endl;
	}
	cin.tie(&cerr);//更换关联对象
	cin.tie(old_tie);
}