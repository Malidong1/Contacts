# Contacts
#pragma once
#include "Preson.h"
#include <vector>
#include <list>
#include <iostream>
#include <string> 
#include <fstream>

class Contact :public Person
{
public:
	Contact() {}
	Contact(string name1, string address1, string tel1, string post1) :Person(name1, address1, tel1, post1) {}
	void SetName();
	string GetName() const;
	void SetTel();
	string GetTel() const;
	void SetAddr();
	void SetPost();
	string GetPost() const;
	string GetAddr() const;
	void Display(vector<Contact>::iterator it);    //显示某个成员的信息
	void Input();                //添加联系人
	void Show();                 //显示所有联系人
	void Search();               //寻找联系人
	void Modify();               //修改联系人信息
	void Delete();               //删除某个联系人
	void Exit();                 //退出程序
	void ReadContact(const char * filename);          //从文件读入联系人信息
	void WriteContact(const char * filename, vector<Contact> per);      //将通讯录信息保存在一个文件中
	void Interface();                          //登陆界面
	void Choose();
};

static vector<Contact> per;
