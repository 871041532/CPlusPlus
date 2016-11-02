#include "stdafx.h"
#include "Person.h"


Person::Person(string _name,int _phone)
{
	name = _name;
	number = _phone;
}

Person::Person(const Person& another)
{
	name = another.name;
	number = another.number;
}
Person& Person::operator=(const Person& another)
{
	name = another.name;
	number = another.number;
	return *this;
}
bool operator<(const Person& a, const Person& b)
{
	return a.number <b.number;
}
bool operator>(const Person& a, const Person& b)
{
	return a.number > b.number;
}
bool operator==(const Person& a, const Person& b)
{
	return a.number == b.number;
}
ostream& operator<<(ostream& out, const Person& a)
{
	//ͷ�ļ����粻����string��˴���ݹ�
	cout << "name: " << a.name << "   number:"<< a.number<<endl; 
	return out;
}
Person::~Person()
{
}
