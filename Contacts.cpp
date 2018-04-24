#include "Contacts.h"

void Contact::SetName()
{
	cout << "姓名：";
	cin >> name;
}
string Contact::GetName() const
{
	string temp = name;
	return temp;
}
void Contact::SetTel()
{
	cout << "电话：";
	cin >> tel;
}
string Contact::GetTel() const
{
	string temp = tel;
	return temp;
}
void Contact::SetAddr()
{
	cout << "地址：";
	cin >> address;
}
string Contact::GetAddr() const
{
	string temp = address;
	return temp;
}
void Contact::SetPost()
{
	cout << "邮箱：";
	cin >> post;
}
string Contact::GetPost() const
{
	string temp = post;
	return temp;
}
//输出某个人联系人信息
void Contact::Display(vector<Contact>::iterator it)
{
	cout << "姓名:" <<it->GetName() << " - ";
	cout << "电话:" <<it->GetTel() << " - ";
	cout << "地址:" <<it->GetAddr() << " - ";
	cout << "邮箱:" <<it->GetPost();
} 

//添加联系人
void Contact::Input()            //添加联系人 
{
	Contact temp;
	int flag = 0;
	vector<Contact>::iterator it;
loop1:            //添加联系人循环体
	temp.SetName();
	for (it = per.begin(); it != per.end(); ++it)
	{
		if (!((it->GetName()).compare(temp.GetName())))     //比较是否有同姓名联系人
		{

			Display(it);
			cout << endl;
			flag = 1;                                      //存在同名人，flag置为1
		}
	}
	if (flag == 1)                                     
	{
		cout << "与已有联系人重名，其信息如上" << endl;
		cout << "是否继续添加此联系人(y/n)：";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			temp.SetTel();
			temp.SetAddr();
			temp.SetPost();
			per.push_back(temp);
		}                                  //继续添加此人
		else
			goto loop2;                                 //跳转到检测循环
	}
	else
	{
		temp.SetTel();
		temp.SetAddr();
		temp.SetPost();
		per.push_back(temp);
	}
loop2:                                                    //检测是否添加其他人
	{
		cout << "是否继续添加联系人(y/n)：";
	char ch1;
	cin >> ch1;
	if (ch1 == 'y' || ch1 == 'Y')
	{
		flag = 0;                         //将flag的值重置为1，再次添加时用
		goto loop1;
	}
	else
	{
		cout << "操作完成！";
		system("pause");
	}
	}
}
void Contact::Show()            //显示所有联系人
{
	vector<Contact>::iterator it;
	if (per.empty())                         //检测通讯录是否为空
		cout << "通讯录暂无联系人！" << endl;
	else
	{
		for (it = per.begin(); it != per.end(); ++it)    //输出联系人
		{
			Display(it); cout << endl;
		}
		system("pause");
	}
}
void Contact::Search()       //查找联系人
{
	vector<Contact>::iterator it;
	string na;                        //查找的信息
	if (per.empty())                  //检查通讯录是否为空
		cout << "通讯录暂无联系人！" << endl;
	cout << "请选择查找方式：1、姓名 2、地址 3、邮箱：";
	int i; 
	cin >> i;                         //选择方式
	int flag = 0;                     //是否查找成功
	if (i == 1)
	{
		cout << "请输入查找的姓名：";
		cin >> na;
		for (it = per.begin(); it != per.end(); ++it)
		{
			if (!((it->GetName()).compare(na)))
			{
				flag = 1;
				Display(it);
				cout << endl;
			}
		}
	}
	if (i == 2)
	{
		cout << "请输入查找的地址：";
		cin >> na;
		for (it = per.begin(); it != per.end(); ++it)
		{
			if (!((it->GetAddr()).compare(na)))
			{
				flag = 1;
				Display(it);
				cout << endl;
			}
		}
	}
	if (i == 3)
	{
		cout << "请输入查找的邮箱：";
		cin >> na;
		for (it = per.begin(); it != per.end(); ++it)
		{
			if (!((it->GetPost()).compare(na)))
			{
				flag = 1;
				Display(it);
				cout << endl;
			}
		}
	}
	if (flag == 0)
		cout << "通讯录中无此联系人！" << endl;
	else
		cout << "以上是所查找联系人信息！" << endl;
	system("pause");
}
void Contact::Modify()
{
	vector<Contact>::iterator it;         //声明一个通讯类的指针
	if (per.empty())                      //检测通讯录是否为空
		cout << "通讯录暂无联系人！" << endl;

		vector<vector<Contact>::iterator > temp_vec;   //存放同名信息的指针
		int flag = 0; //修改对象查找成功与否标志 
		int flag1 = 0; //是否修改了联系人的某个信息
		int count = 0;    //用来记录可修改人数的个数
		cout << "请输入你要编辑的人的姓名：";
		string na;                      //输入被修改人的姓名
		cin >> na;
		for (it = per.begin(); it != per.end(); it++)  //显示所有此名字人的信息
		{
				if (!((it->GetName()).compare(na)))           //比较同名的人并显示出来
				{
					flag = 1;
					temp_vec.push_back(it);
					count++;
					cout << count << "、";
					Display(it);
					cout << endl;
				}
		}
			cout << "以上为可修改人的信息，请输入您要修改人前的序号：";
				int ch1;          //如有几个同名人，通过选择序号的方式选择出来
				char ch2;
				cin >> ch1;                            //要修改的联系人的序号
				if (ch1 <= count)                        //输入的序号是否合法
				{
					ch1--;
					cout << "你要修改的是：1、电话 2、地址 3、邮箱：";
					cin >> ch2;
					switch (ch2)
					{
					case '1':             //修改电话
					{

						temp_vec[ch1]->SetTel();
						cout << "修改成功！该联系人信息改为：" << endl;
						Display(temp_vec[ch1]);
						cout << endl;
						flag1 = 1;
						break;
					}
					case '2':             //修改地址
					{
						temp_vec[ch1]->SetAddr();
						cout << "修改成功！该联系人信息改为：" << endl;
						Display(temp_vec[ch1]);
						cout << endl;
						flag1 = 1;
						break;
					}
					case '3':             //修改邮箱
					{
						temp_vec[ch1]->SetPost();
						Display(temp_vec[ch1]);
						cout << endl;
						flag1 = 1;
						break;
					}
					default:
					{
						cout << "指令输入错误！" << endl;
						break;
					}
					}
				}
				else
					cout << "输入指令非法！\n";
		if (flag == 0)
			cout << "没有找到此联系人" << endl;
		if (flag1 == 0)
			cout << "修改失败!" << endl;
		temp_vec.clear();              //释放临时数组
		system("pause");
}
void Contact::Delete()
{
	vector<Contact>::iterator it;         //声明一个通讯类的指针
	if (per.empty())                      //检测通讯录是否为空
		cout << "通讯录暂无联系人！" << endl;

	vector<vector<Contact>::iterator > temp_vec;   //存放同名信息的指针
	int flag = 0;  //删除对象查找成功与否标志 
	int flag1 = 0; //是否删除了联系人的某个信息
	int count = 0;    //用来记录可删除人数的个数
	cout << "请输入你要删除的人的姓名：";
	string na;                      //输入被删除人的姓名
	cin >> na;
	for (it = per.begin(); it != per.end(); it++)  //显示所有此名字人的信息
	{
		if (!((it->GetName()).compare(na)))           //比较同名的人并显示出来
		{
			flag = 1;
			temp_vec.push_back(it);
			count++;
			cout << count << "、";
			Display(it);
			cout << endl;
		}
	}
	if (flag == 1)
	{
		cout << "以上为可修改人的信息，请输入您要修改人前的序号：";
		int ch;          //如有几个同名人，通过选择序号的方式选择出来
		cin >> ch;                            //要修改的联系人的序号
		if (ch <= count)
		{
			ch--;
			per.erase(temp_vec[ch]);
			flag1 = 1;             //删除成功
		}
	}
	else
		cout << "不存在此联系人！";
	if (flag1 == 1)
		cout << "删除成功！" << endl;
	system("pause");
}
void Contact::Exit()          //退出函数
{
	cout << "确定退出此通讯录吗？y/n: ";
	char ch1;
	cin >> ch1;
	if (ch1 == 'y' || ch1 == 'Y')
		exit(1);
	else
		Choose();
}
void Contact::ReadContact(const char * filename)     //读入函数
{
	Contact c;
	char s;
	ifstream fin;
	fin.open(filename, ios::in | ios::_Nocreate);
	if (!fin)
	{
		cout << "cannot open " << filename << ". \n";
		exit(1);
	}
	fin >> c.name >> s >> c.tel >> s >> c.address >> s >> c.post;
	while (!fin.eof())
	{
		per.push_back(c);
		fin >> c.name >> s >> c.tel >> s >> c.address >> s >> c.post;
	}
	fin.close();
}
void Contact::WriteContact(const char * filename, vector<Contact> a)//写入函数
{
	vector<Contact>::iterator it;
	ofstream fout;
	fout.open(filename, ios::trunc);               //打开并清空
	if (!fout)                                     //无法打开该文件
	{
		cout << "cannot open" << filename << endl;
		exit(1);
	}
	for (it = a.begin(); it != a.end(); it++)
	{
		fout << it->name << " - ";
		fout << it->tel << " - ";
		fout << it->address<< " - ";
		fout << it->post;
		fout << endl;
	}
}

//功能界面
void Contact::Interface()
{
	system("cls");
	cout << endl;
	cout << "              |*************************************************|\n";
	cout << "              |*          多 功 能 电 子 通 讯 录              *|\n";
	cout << "              |*                                               *|\n";
	cout << "              |*************************************************|\n";
	cout << "              |*                                               *|\n";
	cout << "              |*                 1. 添加联系人信息             *|\n";
	cout << "              |*                 2. 查看联系人信息             *|\n";
	cout << "              |*                 3. 查询联系人信息             *|\n";
	cout << "              |*                 4. 修改联系人信息             *|\n";
	cout << "              |*                 5. 删除联系人信息             *|\n";
	cout << "              |*************************************************|\n";
	cout << "              |*      请输入你想要实现的功能：                 *|\n";
	cout << "              |*                                               *|\n";
	cout << "              |*    1添加 2查看 3查询 4修改 5删除 6退出        *|\n";
	cout << "              |*************************************************|\n";
}
//选择功能
void Contact::Choose()
{
	char action;
	Contact temp;
	cout << "请输入你要实现的功能(1-6)：";
	cin >> action;
	switch (action)
	{
	case '1':     //增加联系人
	{
		temp.Input();
		temp.Interface();
		Choose();
		break;
	}
	case '2':     //显示所有联系人
	{
		temp.Show();
		temp.Interface();
		Choose();
		break;
	}
	case '3':    //查找联系人
	{
		temp.Search();
		temp.Interface();
		Choose();
	}
	case '4':     //修改联系人
	{
		temp.Modify();
		temp.Interface();
		Choose();
		break;
	}
	case '5':    //删除联系人
	{
		temp.Delete();
		temp.Interface();
		Choose();
		break;
	}
	case '6':     //退出程序
	{
		temp.WriteContact("D:\\Contacts.txt", per);  //写入通讯录
		temp.Exit();
		break;
	}
	default:      //错误指令
	{
		cout << "输入指令有误，请重新输入！" << endl;
		Choose();
		break;
	}
	}
}
