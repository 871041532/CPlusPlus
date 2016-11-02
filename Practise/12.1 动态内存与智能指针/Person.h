#pragma once
#include "stdafx.h"
class Person
{
public:
	Person(string _name="",int number=0); //普通构造
	Person(const Person& another); //拷贝构造
	Person& Person::operator=(const Person& another);//赋值运算符重载
	friend bool operator==(const Person& a, const Person& b);
	friend bool operator>(const Person& a, const Person& b);
	friend bool operator<(const Person& a, const Person& b);
	friend ostream& operator<<(ostream& out, const Person& a);
	~Person();
private:
	string name;
	int number;
};

