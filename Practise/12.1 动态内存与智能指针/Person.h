#pragma once
#include "stdafx.h"
class Person
{
public:
	Person(string _name="",int number=0); //��ͨ����
	Person(const Person& another); //��������
	Person& Person::operator=(const Person& another);//��ֵ���������
	friend bool operator==(const Person& a, const Person& b);
	friend bool operator>(const Person& a, const Person& b);
	friend bool operator<(const Person& a, const Person& b);
	friend ostream& operator<<(ostream& out, const Person& a);
	~Person();
private:
	string name;
	int number;
};

