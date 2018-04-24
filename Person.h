#pragma once
#include<iostream>
using namespace std;
class Person
{
protected:
	string name;         //人员姓名
	string tel;          //电话
	string address;      //地址
	string post;         //邮箱
public:
	Person() {}
	Person(string name1, string address1, string tel1, string post1)
	{name = name1; address = address1; tel = tel1; post = post1;}
};
