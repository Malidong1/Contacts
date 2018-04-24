#include"Contacts.h"  
int main()
{
	Contact c;
	c.ReadContact("D:\\Contacts.txt");     //读入通讯录
	c.Interface();                         //操作界面
	c.Choose();                            //功能选择
	system("pause");
	return 0;
}
