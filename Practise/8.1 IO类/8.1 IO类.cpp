// 8.1 IO��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//8.1.2 ����״̬����һ��istream&����������ֵ����Ҳ��istream&�����������ж�ȡ����֪�������ļ�������־ֹͣ������ӡ�ڱ�׼���
istream& readForm(istream&);
//8.1.3 ˢ�����������
void buffRefresh();
//8.1.3 �������������
void relationIOstream();
int main()
{
	////ostream���� 
	//auto bool1=cout.good();
	//auto bool2 = cout.eof();
	//cout <<"������Ƿ�����:" <<bool1 << " " <<"������Ƿ����:"<< bool2 << endl;
	////istream
	//string a;
	//auto old_state = cin.rdstate(); //cin�ĵ�ǰ״̬
	//cin.clear(); //ʹcin��Ч
	//cin >> a;//ʹ��cin
	//cin.setstate(old_state);//��cin��Ϊԭ��״̬
	//cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);//��λfailbit����badbit����������λ����
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
	cout << "hi" << endl;//ˢ�»�����������
	cout << "world" << ends;//ˢ�»����������ո�
	cout << "llo" << flush;//ˢ�»������޲���
	//unitbuf������
	cout << unitbuf;//�������������������ˢ�»�����
	cout << nounitbuf;//�ص�������ģʽ
	cin >> unitbuf;
	cin >> nounitbuf;
}
void relationIOstream()
{
	//���󷽷�cin.tie���������آٲ����������ط��ش����������������ָ�룬��δ�������ؿ�ָ�롣
	//�ڽ���һ��ostreamָ�룬�������������������������ĺô��ǣ��κδ���������ȡ���ݵĲ�������ˢ��������������
	cin.tie(&cout);//cin��cout�����
	ostream *old_tie = cin.tie(); //�����cin������������
	if (old_tie)
	{
		*old_tie << "��cin�������ostream����Ϊ��" << endl;
	}
	cin.tie(&cerr);//������������
	cin.tie(old_tie);
}