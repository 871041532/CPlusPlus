// 8.2 �ļ��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//8.2.1 ʹ���ļ�������
void usingFstream();
//8.2.2�ļ�ģʽ
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
	//������������ָ���ļ������ļ��ж�ȡ���ݣ��ļ������ڣ�����״̬��Ч��failbit��λ��
	ifstream input("C:\\Users\\zhoukb\\Desktop\\��־.txt");
	string content;
	string tmp;
	//while (input >> tmp)//���뵥�������Կո����
	while(getline(input,tmp))//���ÿһ�е�����
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
void IOModule()
{
	/*
		in �Զ���ʽ��
		out ��д��ʽ��
		app ׷��ģʽ��ÿ��д����ǰ��ָ�����ļ�ĩβ
		ate ���ļ���������λ���ļ�ĩβ
		trunc �ض��ļ�
		binary �Զ����Ʒ�ʽ����IO
	*/
	//�ضϡ������������ȼ�
	ofstream out1("C:\\Users\\zhoukb\\Desktop\\ʵ��.txt");//����out | trunc�������ģʽ���ļ����ض�
	ofstream out2("C:\\Users\\zhoukb\\Desktop\\ʵ��.txt",ofstream::out);//����trunc�ض��ļ�
	ofstream out3("C:\\Users\\zhoukb\\Desktop\\ʵ��.txt", ofstream::out | ofstream::trunc);
	//���ض��ļ���׷��ģʽ�������������ȼ�
	ofstream out4("C:\\Users\\zhoukb\\Desktop\\ʵ��.txt", ofstream::app); //����out
	out4 << "hello";
	out4 << " world";
	out4.close();//��close��д��׷�ӵ��ļ�ͷλ�á����ļ��ٴα�openʱ��λΪ�գ�ͬʱд�롣
	ofstream out5("C:\\Users\\zhoukb\\Desktop\\ʵ��.txt", ofstream::app | ofstream::out);
	out5 << "��"<<"�룺";
}