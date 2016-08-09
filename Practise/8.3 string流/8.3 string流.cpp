// 8.3 string��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
struct PersonInfo
{
	string name;
	vector<string> phones;
};
//8.3.1 ʹ��istringstream
void phoneNotesEval1();
//8.3.2 ʹ��ostringstream
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
	ifstream open("C:\\Users\\zhoukb\\Desktop\\�绰��.txt");//��һ���ļ���
	istringstream record;//�����ж�ȡ�ַ���
	while (getline(open, line))
	{
		record.str(line);
		PersonInfo item;	
		record >> item.name; //��ȡ����
		while (record>>world)
		{
			item.phones.push_back(world); //����ÿ���绰
		}
		peoples.push_back(item);//����ÿ��item
		record.clear();
	}
	//�������������peoples����
	vector<PersonInfo>::iterator k = peoples.begin();
	while (k != peoples.end())
	{
		int i = 1;
		cout <<"������"<< (*k).name << ends;
		vector<string>::iterator k2 = (*k).phones.begin();
		while (k2!= (*k).phones.end())
		{
			cout << "�绰" <<i++<<"��"<< *k2 << ends;
			k2++;
		}
		k++;
		cout << endl;		
	}
	cout << "����������������" << endl<<endl;
	phoneNotesEval2(peoples);
}
void phoneNotesEval2(vector<PersonInfo> &peoples)
{
	for each (auto peopleItem in peoples)
	{
		ostringstream numbers; //������д���ַ�����ջ�ṹ��
		int i = 1;
		for each (auto phoneItem in peopleItem.phones)
		{
			numbers << "�绰"<<i++<<"Ϊ��"<<phoneItem<<" ";
		}
		cout << peopleItem.name << ends << numbers.str() << endl;
	}
	cout << "����for each����������" << endl;
}