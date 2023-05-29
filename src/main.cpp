#define MAIN
#include "../include/head.h"
#include "../include/shell.h"
// ��������õ�ͷ�ļ�
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

int main()
{
	cout << "===============================================" << endl;
	cout << "              ��UNIX V6++�ļ�ϵͳ              " << endl;
	cout << "===============================================" << endl;
	cout << endl;

	help();

	fstream fd;
	fd.open(DISK_NAME, ios::in);

	map<string, File *> file_open;

	if (!fd.is_open())
	{
		cout << "�ļ�ϵͳ�����ڣ�����������г�ʼ��..." << endl;
		while (getchar() != '\n')
			;
		Init();
	}
	else
	{
		fd.close();
		cout << "�Ƿ�����ļ�ϵͳ��ʼ������y/n��" << endl;
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
				cout << "�û�δ��¼���������û���������" << endl;
				cout << "�û����� ";
				char user_name[USER_NAME_MAX];
				cin >> user_name;
				cout << "���룺 ";
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
			cout << "�������롿" << e << endl;
		}
		cout << endl;
	}

	return 0;
}