#include "../include/shell.h"

vector<string> split(string str)
{
    string buf;
    stringstream ss(str);
    vector<string> v;
    // �ַ���ss
    while (ss >> buf)
    {
        // תСд
        transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
        v.push_back(buf);
    }

    return v;
}

void Switch_Demand(vector<string> demand_vector, map<string, File *> file_open)
{
    if (demand_vector[0] == "help")
    {
        if (demand_vector.size() == 1)
        {
            help();
        }
        else if (demand_vector[1] == "attrib")
        {
            help_attrib();
        }
        else if (demand_vector[1] == "cd")
        {
            help_cd();
        }
        else if (demand_vector[1] == "del")
        {
            help_del();
        }
        else if (demand_vector[1] == "dir")
        {
            help_dir();
        }
        else if (demand_vector[1] == "exit")
        {
            help_exit();
        }
        else if (demand_vector[1] == "mkdir")
        {
            help_mkdir();
        }
        else if (demand_vector[1] == "rmdir")
        {
            help_rmdir();
        }
        else if (demand_vector[1] == "print")
        {
            help_print();
        }
        else if (demand_vector[1] == "write")
        {
            help_write();
        }
        else if (demand_vector[1] == "open")
        {
            help_open();
        }
        else if (demand_vector[1] == "close")
        {
            help_close();
        }
        else if (demand_vector[1] == "fseek")
        {
            help_fseek();
        }
        else if (demand_vector[1] == "logout")
        {
            help_logout();
        }
        else if (demand_vector[1] == "whoami")
        {
            help_whoami();
        }
        else if (demand_vector[1] == "format")
        {
            help_format();
        }
        else if (demand_vector[1] == "register")
        {
            help_register();
        }
        else if (demand_vector[1] == "deleteaccount")
        {
            help_deleteaccount();
        }
        else if (demand_vector[1] == "su")
        {
            help_su();
        }
        else if (demand_vector[1] == "chgrp")
        {
            help_chgrp();
        }
        else if (demand_vector[1] == "userlist")
        {
            help_userlist();
        }
        else if (demand_vector[1] == "create")
        {
            help_create();
        }
        else if (demand_vector[1] == "openlist")
        {
            help_openlist();
        }
        else
        {
            cout << "�������" << endl;
        }
    }
    else if (demand_vector[0] == "attrib")
    {
        if (demand_vector.size() != 4)
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[1].size() != 2)
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[1][0] != '+' && demand_vector[1][0] != '-')
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[1][1] != 'r' && demand_vector[1][1] != 'w' && demand_vector[1][1] != 'e')
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[2].size() != 1)
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[2][0] != 'o' && demand_vector[2][0] != 'g' && demand_vector[2][0] != 'e')
            cout << "ATTRIB�������﷨����ȷ��ʹ��\"HELP ATTRIB\"����鿴ʹ�ù���" << endl;
        else
        {
            unsigned int permission = 0;
            bool add;
            if (demand_vector[1][0] == '+')
                add = true;
            else
                add = false;
            if (demand_vector[1][1] == 'r' && demand_vector[2] == "o")
                permission = Inode::OWNER_R;
            else if (demand_vector[1][1] == 'w' && demand_vector[2] == "o")
                permission = Inode::OWNER_W;
            else if (demand_vector[1][1] == 'e' && demand_vector[2] == "o")
                permission = Inode::OWNER_E;
            else if (demand_vector[1][1] == 'r' && demand_vector[2] == "g")
                permission = Inode::GROUP_R;
            else if (demand_vector[1][1] == 'w' && demand_vector[2] == "g")
                permission = Inode::GROUP_W;
            else if (demand_vector[1][1] == 'e' && demand_vector[2] == "g")
                permission = Inode::GROUP_E;
            else if (demand_vector[1][1] == 'r' && demand_vector[2] == "e")
                permission = Inode::ELSE_R;
            else if (demand_vector[1][1] == 'w' && demand_vector[2] == "e")
                permission = Inode::ELSE_W;
            else if (demand_vector[1][1] == 'e' && demand_vector[2] == "e")
                permission = Inode::ELSE_E;
            Edit_File_Permission(demand_vector[3].c_str(), permission, add);
            cout << "�ѳɹ������ļ���д����" << endl;
        }
    }
    else if (demand_vector[0] == "cd")
    {
        if (demand_vector.size() == 1)
        {
            cout << Current_Directory() << endl;
        }
        else
        {
            Open_Directory(demand_vector[1].c_str());
        }
    }
    else if (demand_vector[0] == "del")
    {
        if (demand_vector.size() < 2)
            cout << "DEL�������﷨����ȷ��ʹ��\"HELP DEL\"����鿴ʹ�ù���" << endl;
        else
        {
            for (int i = 1; i < demand_vector.size(); i++)
            {
                Delete_File(demand_vector[i].c_str());
                cout << "�ɹ�ɾ���ļ�" << demand_vector[i] << endl;
            }
        }
    }
    else if (demand_vector[0] == "dir")
    {
        if (demand_vector.size() > 2)
            cout << "DIR�������﷨����ȷ��ʹ��\"HELP DIR\"����鿴ʹ�ù���" << endl;
        else if (demand_vector.size() == 2 && demand_vector[1] != "/q")
            cout << "DIR�������﷨����ȷ��ʹ��\"HELP DIR\"����鿴ʹ�ù���" << endl;
        else
        {
            if (demand_vector.size() == 1)
                Show_File_List(false);
            else
                Show_File_List(true);
        }
    }
    else if (demand_vector[0] == "exit")
    {
        if (demand_vector.size() > 2)
            cout << "EXIT�������﷨����ȷ��ʹ��\"HELP EXIT\"����鿴ʹ�ù���" << endl;
        else if (demand_vector.size() == 2 && !isdigit(demand_vector[1][0]))
            cout << "EXIT�������﷨����ȷ��ʹ��\"HELP EXIT\"����鿴ʹ�ù���" << endl;
        else
        {
            if (demand_vector.size() == 1)
            {
                cout << "�˳��ļ�ϵͳ" << endl;
                exit(0);
            }
            else
            {
                cout << "�˳��ļ�ϵͳ" << endl;
                exit((int)demand_vector[1][0] - 48);
            }
        }
    }
    else if (demand_vector[0] == "mkdir")
    {
        if (demand_vector.size() != 2)
            cout << "MKDIR�������﷨����ȷ��ʹ��\"HELP MKDIR\"����鿴ʹ�ù���" << endl;
        else
        {
            Create_Directory(demand_vector[1].c_str());
            cout << "�ɹ�����Ŀ¼" << demand_vector[1] << endl;
        }
    }
    else if (demand_vector[0] == "rmdir")
    {
        if (demand_vector.size() != 2)
            cout << "MKDIR�������﷨����ȷ��ʹ��\"HELP RMDIR\"����鿴ʹ�ù���" << endl;
        else
        {
            Remove_Directory(demand_vector[1].c_str());
            cout << "�ɹ�ɾ��Ŀ¼" << demand_vector[1] << endl;
        }
    }
    else if (demand_vector[0] == "open")
    {
        if (demand_vector.size() != 2)
            cout << "OPEN�������﷨����ȷ��ʹ��\"HELP OPEN\"����鿴ʹ�ù���" << endl;
        else
        {
            File *file = Open_File(demand_vector[1].c_str());
            if (file_open.find(Current_Directory() + "\\" + demand_vector[1]) == file_open.end())
            {
                file_open[Current_Directory() + "\\" + demand_vector[1]] = file;
                cout << "�ѳɹ����ļ�" << demand_vector[1] << endl;
            }
            else
            {
                cout << "��ǰ�ļ��ѱ��򿪣��޷��ظ���" << endl;
            }
        }
    }
    else if (demand_vector[0] == "close")
    {
        if (demand_vector.size() != 2)
            cout << "CLOSE�������﷨����ȷ��ʹ��\"HELP CLOSE\"����鿴ʹ�ù���" << endl;
        else
        {
            auto it = file_open.find(Current_Directory() + "\\" + demand_vector[1]);
            if (it == file_open.end())
            {
                cout << "δ���ļ�" << demand_vector[1] << endl;
            }
            else
            {
                Close_File(it->second);
                file_open.erase(it);
                cout << "�ѳɹ��ر��ļ�" << demand_vector[1] << endl;
            }
        }
    }
    else if (demand_vector[0] == "print")
    {
        if (demand_vector.size() > 6)
            cout << "PRINT�������﷨����ȷ��ʹ��\"HELP PRINT\"����鿴ʹ�ù���" << endl;
        else
        {
            int length = -1;
            vector<string>::iterator it;
            for (it = demand_vector.begin(); it != demand_vector.end(); it++)
            {
                if (*it == "-l")
                    break;
                if (it->at(0) == '-' && !(it->at(1) == 'p' || it->at(1) == 'l'))
                {
                    cout << "PRINT�������﷨����ȷ��ʹ��\"HELP PRINT\"����鿴ʹ�ù���" << endl;
                    return;
                }
            }
            if (it != demand_vector.end())
            {
                it++;
                if (!isdigit(it->at(0)))
                {
                    cout << "PRINT�������﷨����ȷ��ʹ��\"HELP PRINT\"����鿴ʹ�ù���" << endl;
                    return;
                }
                length = atoi((*it).c_str());
            }

            char *content = new char[100000000];
            auto i = file_open.find(Current_Directory() + "\\" + demand_vector[1]);
            if (i == file_open.end())
            {
                cout << "δ���ļ�" << demand_vector[1] << endl;
                return;
            }
            Read_File(i->second, content, length);

            for (it = demand_vector.begin(); it != demand_vector.end(); it++)
            {
                if (*it == "-p")
                    break;
            }
            if (it != demand_vector.end())
            {
                it++;
                fstream f(*it, ios::out);
                if (!f.is_open())
                {
                    cout << "�޷�д���ļ�" << *it << endl;
                    return;
                }
                f << content;
                f.close();
                cout << "�ѽ�" << demand_vector[1] << "�ļ�����д��" << *it << endl;
            }
            else
            {
                cout << content << endl;
            }
            delete[] content;
        }
    }
    else if (demand_vector[0] == "write")
    {
        if (demand_vector.size() > 4)
            cout << "WRITE�������﷨����ȷ��ʹ��\"HELP WRITE\"����鿴ʹ�ù���" << endl;
        else if (demand_vector[2] != "-s" && demand_vector[2] != "-f")
            cout << "WRITE�������﷨����ȷ��ʹ��\"HELP WRITE\"����鿴ʹ�ù���" << endl;

        else
        {
            auto it = file_open.find(Current_Directory() + "\\" + demand_vector[1]);
            if (it == file_open.end())
            {
                cout << "δ���ļ�" << demand_vector[1] << endl;
                return;
            }

            if (demand_vector[2] == "-s")
            {
                Write_File(it->second, demand_vector[3].c_str());
                cout << "�ɹ�д���ļ�" << endl;
            }
            else
            {
                string content;
                fstream f(demand_vector[3], ios::in);
                if (!f.is_open())
                {
                    cout << "�޷����ļ�" << demand_vector[2] << endl;
                    return;
                }
                while (!f.eof())
                {
                    getline(f, content);
                    content += '\n';
                    Write_File(it->second, content.c_str());
                }
                f.close();
                cout << "�ѽ�" << demand_vector[3] << "�ļ�����д��" << demand_vector[1] << endl;
            }
        }
    }
    else if (demand_vector[0] == "fseek")
    {
        if (demand_vector.size() != 3)
            cout << "FSEEK�������﷨����ȷ��ʹ��\"HELP FSEEK\"����鿴ʹ�ù���" << endl;
        else
        {
            auto it = file_open.find(Current_Directory() + "\\" + demand_vector[1]);
            if (it == file_open.end())
            {
                cout << "δ���ļ�" << demand_vector[1] << endl;
            }
            else
            {
                Seek_File(it->second, atoi(demand_vector[2].c_str()));
                cout << "�ѽ�" << demand_vector[1] << "�ļ�ָ�붨λ��" << demand_vector[2] << endl;
            }
        }
    }
    else if (demand_vector[0] == "create")
    {
        if (demand_vector.size() != 2)
            cout << "CREATE�������﷨����ȷ��ʹ��\"HELP CREATE\"����鿴ʹ�ù���" << endl;
        else
        {
            Create_File(demand_vector[1].c_str());
            cout << "�ɹ������ļ�" << demand_vector[1] << endl;
        }
    }
    else if (demand_vector[0] == "logout")
    {
        if (demand_vector.size() != 1)
            cout << "LOGOUT�������﷨����ȷ��ʹ��\"HELP LOGOUT\"����鿴ʹ�ù���" << endl;
        else
        {
            User_Logout();
            cout << "�û��ɹ��ǳ�" << endl;
        }
    }
    else if (demand_vector[0] == "whoami")
    {
        if (demand_vector.size() != 1)
            cout << "WHIAMI�������﷨����ȷ��ʹ��\"HELP WHIAMI\"����鿴ʹ�ù���" << endl;
        else
        {
            char user_name[USER_NAME_MAX];
            cout << "userid��" << Get_User(user_name) << endl;
            cout << "username��" << user_name << endl;
        }
    }
    else if (demand_vector[0] == "openlist")
    {
        if (demand_vector.size() != 1)
            cout << "WHIAMI�������﷨����ȷ��ʹ��\"HELP WHIAMI\"����鿴ʹ�ù���" << endl;
        else
        {
            cout << "��ǰ�򿪵��ļ��У�" << endl;
            for (auto &it : file_open)
            {
                cout << it.first << endl;
            }
        }
    }
    else if (demand_vector[0] == "format")
    {
        if (demand_vector.size() != 1)
            cout << "FORMAT�������﷨����ȷ��ʹ��\"HELP FORMAT\"����鿴ʹ�ù���" << endl;
        else
        {
            Init();
            Activate();
            cout << "�ѳɹ���ʽ���ļ���" << endl;
        }
    }
    else if (demand_vector[0] == "register")
    {
        if (demand_vector.size() != 3)
            cout << "REGISTER�������﷨����ȷ��ʹ��\"HELP REGISTER\"����鿴ʹ�ù���" << endl;
        else
        {
            User_Register(demand_vector[1].c_str(), demand_vector[2].c_str());
            cout << "�ɹ������û�" << endl;
        }
    }
    else if (demand_vector[0] == "deleteaccount")
    {
        if (demand_vector.size() != 2)
            cout << "DELETEACCOUNT�������﷨����ȷ��ʹ��\"HELP DELETEACCOUNT\"����鿴ʹ�ù���" << endl;
        else
        {
            User_Delete(demand_vector[1].c_str());
            cout << "�ɹ�ɾ���û�" << endl;
        }
    }
    else if (demand_vector[0] == "su")
    {
        if (demand_vector.size() != 3)
            cout << "SU�������﷨����ȷ��ʹ��\"HELP SU\"����鿴ʹ�ù���" << endl;
        else
        {
            User_Logout();
            User_Login(demand_vector[1].c_str(), demand_vector[2].c_str());
            cout << "�ɹ������û�" << endl;
        }
    }
    else if (demand_vector[0] == "chgrp")
    {
        if (demand_vector.size() != 3)
            cout << "CHGRP�������﷨����ȷ��ʹ��\"HELP CHGRP\"����鿴ʹ�ù���" << endl;
        else
        {
            Change_User_Group(demand_vector[1].c_str(), atoi(demand_vector[2].c_str()));
            cout << "�ɹ������û�" << demand_vector[1] << "��" << demand_vector[2] << "��" << endl;
        }
    }
    else if (demand_vector[0] == "userlist")
    {
        if (demand_vector.size() != 1)
            cout << "USERLIST�������﷨����ȷ��ʹ��\"HELP USERLIST\"����鿴ʹ�ù���" << endl;
        else
        {
            Show_User_List();
        }
    }
    else
    {
        cout << demand_vector[0] << "�����ڲ����ⲿ���Ҳ���ǿ����еĳ�����������ļ���" << endl;
    }
}