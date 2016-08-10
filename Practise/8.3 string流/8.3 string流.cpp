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
//8.3.2 ʹ��stringstream����ת��
void convertType();
//8.3.4 ���ʫ����У
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
	vector<PersonInfo>::iterator k = peoples.begin(); //auto k=peoples.begin();
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
	cout <<"������ַ���ת��Ϊint��"<< v1<<endl;

	string s2;
	//media.clear();
	stringstream media2;
	media2 << 231;
	media2 >> s2;
	cout << "int��231ת��Ϊ�ַ���Ϊ��" << s2 << endl;

}
void eraseChildString(string& father,const string child) //ɾ���ַ����������Ӵ�
{
	int childLength = child.length();
	int pos = father.find(child);
	if (pos!=string::npos) eraseChildString(father.erase(pos, childLength),child);//�ݹ����
	else return;
}
void evalLiBai1()
{
	ifstream readLiBai("C:\\Users\\zhoukb\\Desktop\\���ʫ��.txt");
	ofstream writeLiBai("C:\\Users\\zhoukb\\Desktop\\���ʫ����У��.txt");//׷��ģʽ
	string lastLine="  ";
	string line;
	int lineNumber= 1;
	while (getline(readLiBai,line))
	{  
		cout << "ߣ" << lineNumber ++<<"�У�"<< line << endl;
		//ȥ��ĸ
		for (size_t i =65 ; i < 91; i++)
		{
			char tempChar = i;
			string tempChild(1, tempChar);
			eraseChildString(line, tempChild);
		}
		eraseChildString(line, ">");
		eraseChildString(line, " ");
		eraseChildString(line, "\t");
		eraseChildString(line, "�ơ�");
		//eraseChildString(line, "���");
		eraseChildString(line, "--����\"����իʫ��\"bookbest.163.net���롢����������ѫ");
		if (line.find("�����ձ�") != string::npos || line.find("ȫ��ʫ") != string::npos) line = ""; //ʫ��д���ġ���
		bool b1 = line.find("��") == line.length() - 1;
		eraseChildString(line, "���");
		if (b1) writeLiBai << line + "\n";
		else writeLiBai << line;
		lastLine = line;
	}
	cout << "��У��ϣ���"<< --lineNumber<<"��" << endl;
}

