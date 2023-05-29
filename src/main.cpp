#define MAIN
#include "../include/head.h"
#include "../include/shell.h"
// 命令处理所用的头文件
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

int main()
{
	cout << "===============================================" << endl;
	cout << "              仿UNIX V6++文件系统              " << endl;
	cout << "===============================================" << endl;
	cout << endl;

	help();

	fstream fd;
	fd.open(DISK_NAME, ios::in);

	map<string, File *> file_open;

	if (!fd.is_open())
	{
		cout << "文件系统不存在，按任意键进行初始化..." << endl;
		while (getchar() != '\n')
			;
		Init();
	}
	else
	{
		fd.close();
		cout << "是否进行文件系统初始化？（y/n）" << endl;
		char ch;
		if ((ch = getchar()) == 'y')
		{
			Init();
		}
		while (ch != '\n' && getchar() != '\n')
			;
	}

	Activate();

	string demand;
	while (1)
	{
		try
		{
			if (Get_User(NULL) == static_cast<unsigned short>(-1))
			{
				cout << "用户未登录，请输入用户名和密码" << endl;
				cout << "用户名： ";
				char user_name[USER_NAME_MAX];
				cin >> user_name;
				cout << "密码： ";
				char user_password[USER_PASSWORD_MAX];
				cin >> user_password;
				User_Login(user_name, user_password);
				getchar();
			}
			cout << Current_Directory() << ">";
			getline(cin, demand);
			vector<string> demand_vector = split(demand);

			if (demand_vector.empty())
				continue;
			else
			{
				Switch_Demand(demand_vector, file_open);
			}
		}
		catch (int &e)
		{
			cout << "【错误码】" << e << endl;
		}
		cout << endl;
	}

	return 0;
}