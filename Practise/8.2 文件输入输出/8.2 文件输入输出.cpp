// 8.2 �ļ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//8.2.1 ʹ���ļ�������
void usingFstream();
int main()
{
	usingFstream();
	system("pause");
    return 0;
}
void usingFstream()
{
	//������������ָ���ļ������ļ��ж�ȡ���ݣ��ļ������ڣ�����״̬��Ч��failbit��λ��
	ifstream input("C:\\Users\\zhoukb\\Desktop\\��־.txt");
	string content;
	string tmp;
	while (input >> tmp)
	{
		content = content + tmp + "\n";
	}
	if (content != "")
	{
		cout << "�ļ�ԭ����Ϊ��" << endl;
		cout << content << endl;
	}
	else
	{
		cout << "���껪" << endl;
	}
	input.open("C:\\Users\\zhoukb\\Desktop\\��ǩ.txt");
	cout << "\n�����������ݣ�" << endl;
	getline(cin, content);
	if (content!="")
	{
		//�����������ָ���ļ������ļ���д�����ݣ����ļ��������򴴽�,������������ݣ�
		ofstream output("temp.txt");
		output << content;
		output.close();
	}
	input.close();
}
