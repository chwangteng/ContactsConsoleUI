#include<fstream>
#include<string>
#include<sstream>
#include<iostream>
#include"Length.h"
#include"Person.h"
#include"PersonList.h"
#include"Color.h"
#include"GUIHelper.h"
#include"Trivia.h"
int PersonList::get_ori_code(const int & code)
{
	pTemp = pBegin;
	while (pTemp != 0)
	{
		if (pTemp->code == code)
			return pTemp->oricode;
		pTemp = pTemp->next;
	}
}
void PersonList::search_group(const string & group)
{
	pTemp = pBegin;
	while (pTemp != 0)
	{
		int cod = pTemp->code;
		if (pTemp->group != group)
		{
			pTemp = pBegin;
			pCurrent = pBegin;
			while (pTemp->code != cod)
			{
				pCurrent = pTemp;
				pTemp = pTemp->next;
			}
			if (pTemp->code == 1)
			{
				pBegin = pCurrent->next;
				while (pCurrent != pEnd)
				{
					pCurrent = pCurrent->next;
					pCurrent->code = pCurrent->code - 1;
				}
			}
			else if (pTemp->code == record_number)
			{
				pEnd = pCurrent;
				pEnd->next = 0;
			}
			else
			{
				pCurrent->next = pTemp->next;
				while (pTemp != pEnd)
				{
					pTemp = pTemp->next;
					pTemp->code = pTemp->code - 1;
				}
				pTemp = pCurrent;
			}
			record_number = record_number - 1;
		}
		pTemp = pTemp->next;
	}
}
bool PersonList::search_address(const string&  KW)
{
	pTemp = pBegin;
	while (pTemp != 0)
	{
		int match = 0;
		for (int j = 0; j != KW.size(); ++j)
			for (int i = 0; i != (pTemp->address).size(); ++i)
				if (pTemp->address[i] == KW[j])
				{
					++match;
					break;
				}
		int cod = pTemp->code;
		if (match < KW.size())
		{
			if (record_number == 1)
				return 0;
			pTemp = pBegin;
			pCurrent = pBegin;
			while (pTemp->code != cod)
			{
				pCurrent = pTemp;
				pTemp = pTemp->next;
			}
			if (pTemp->code == 1)
			{
				pBegin = pCurrent->next;
				while (pCurrent != pEnd)
				{
					pCurrent = pCurrent->next;
					pCurrent->code = pCurrent->code - 1;
				}
			}
			else if (pTemp->code == record_number)
			{
				pEnd = pCurrent;
				pEnd->next = 0;
			}
			else
			{
				pCurrent->next = pTemp->next;
				while (pTemp != pEnd)
				{
					pTemp = pTemp->next;
					pTemp->code = pTemp->code - 1;
				}
				pTemp = pCurrent;
			}
			record_number = record_number - 1;
		}
		pTemp = pTemp->next;
	}
	return 1;
}
int PersonList::search_phone(const char*phone)
{
	pTemp = pBegin;
	while (pTemp != 0)
	{
		if (pTemp->phone == phone)
			return pTemp->code;
		pTemp = pTemp->next;
	}
	return 0;
}
int PersonList::search_name(const char* name)
{
	pTemp = pBegin;
	while (pTemp != 0)
	{
		if (pTemp->name == name)
			return pTemp->code;
		pTemp = pTemp->next;
	}
	return 0;
}
void PersonList::MoveP()
{
	this->pBegin = NULL;
	this->pEnd = NULL;
}
void PersonList::RecoveryFile(PersonList & backup)
{
	fstream file;
	file.open("test.txt", ios::out);
	file.close();
	this->pBegin = backup.begin();
	this->pEnd = backup.end();
	this->record_number = backup.record_number;
	for (int i = 1; i != record_number + 1; ++i)
		Inject2File(i, 1, "test.txt");
}
PersonList::PersonList(char* filename)
{
	fstream file;
	file.open(filename, ios::in | ios::out | ios::binary);
	file.seekg(0, ios::end);
	record_number = file.tellg() / row_size;
	file.seekg(0, ios::beg);
	pBegin = new Person;
	pCurrent = pBegin;
	for (int i = 0; i != record_number; ++i)
	{
		pCurrent->code = i + 1;
		pCurrent->oricode = i + 1;
		string str;
		getline(file, str);
		istringstream iss(str);
		iss >> pCurrent->name;
		iss >> pCurrent->sex;
		iss >> pCurrent->phone;
		iss >> pCurrent->address;
		iss >> pCurrent->zip;
		iss >> pCurrent->mail;
		iss >> pCurrent->qq;
		iss >> pCurrent->group;
		if (pCurrent->code == record_number)
		{
			pEnd = pCurrent;
			pEnd->next = 0;
			break;
		}
		pTemp = new Person;
		pCurrent->next = pTemp;
		pCurrent = pTemp;
	}
	file.close();
}
PersonList::~PersonList()
{
		/*pTemp = pBegin;
		while (pTemp != pEnd)
		{
			pCurrent = pTemp;
			pTemp = pTemp->next;
			delete[] pCurrent;
		}
		delete [] pEnd;*/
}
Person* PersonList::begin()
{
	return pBegin;
}
Person* PersonList::end()
{
	return pEnd;
}
void PersonList::BackUpFile()
{
	fstream file;
	file.open("backup.txt", ios::out);
	file.close();
	for (int i = 1; i != record_number + 1; ++i)
		Inject2File(i, 1, "backup.txt");
}
void PersonList::Rank()
{
	for (int i = 1; i < record_number - 1; ++i)
	{
		pTemp = pBegin;
		for (int j = 0; j < record_number - i; ++j)
		{
			if ((((pTemp->name)[0] - 0xa1) * 100 + (pTemp->name)[1] - 0xa1) >(((pTemp->next->name)[0] - 0xa1) * 100 + (pTemp->next->name)[1] - 0xa1))
			{
				Person pe;
				pe.name = pTemp->name;
				pe.sex = pTemp->sex;
				pe.phone = pTemp->phone;
				pe.address = pTemp->address;
				pe.zip = pTemp->zip;
				pe.mail = pTemp->mail;
				pe.qq = pTemp->qq;
				pe.group = pTemp->group;
				pe.next = NULL;

				pTemp->name = pTemp->next->name;
				pTemp->sex = pTemp->next->sex;
				pTemp->phone = pTemp->next->phone;
				pTemp->address = pTemp->next->address;
				pTemp->zip = pTemp->next->zip;
				pTemp->mail = pTemp->next->mail;
				pTemp->qq = pTemp->next->qq;
				pTemp->group = pTemp->next->group;

				pTemp->next->name = pe.name;
				pTemp->next->sex = pe.sex;
				pTemp->next->phone = pe.phone;
				pTemp->next->address = pe.address;
				pTemp->next->zip = pe.zip;
				pTemp->next->mail = pe.mail;
				pTemp->next->qq = pe.qq;
				pTemp->next->group = pe.group;
			}
			else if (((((pTemp->name)[0] - 0xa1) * 100 + (pTemp->name)[1] - 0xa1) == (((pTemp->next->name)[0] - 0xa1) * 100 + (pTemp->next->name)[1] - 0xa1)) && ((((pTemp->name)[2] - 0xa1) * 100 + (pTemp->name)[3] - 0xa1) >(((pTemp->next->name)[2] - 0xa1) * 100 + (pTemp->next->name)[3] - 0xa1)))
			{
				Person pe;
				pe.name = pTemp->name;
				pe.sex = pTemp->sex;
				pe.phone = pTemp->phone;
				pe.address = pTemp->address;
				pe.zip = pTemp->zip;
				pe.mail = pTemp->mail;
				pe.qq = pTemp->qq;
				pe.group = pTemp->group;
				pe.next = NULL;

				pTemp->name = pTemp->next->name;
				pTemp->sex = pTemp->next->sex;
				pTemp->phone = pTemp->next->phone;
				pTemp->address = pTemp->next->address;
				pTemp->zip = pTemp->next->zip;
				pTemp->mail = pTemp->next->mail;
				pTemp->qq = pTemp->next->qq;
				pTemp->group = pTemp->next->group;

				pTemp->next->name = pe.name;
				pTemp->next->sex = pe.sex;
				pTemp->next->phone = pe.phone;
				pTemp->next->address = pe.address;
				pTemp->next->zip = pe.zip;
				pTemp->next->mail = pe.mail;
				pTemp->next->qq = pe.qq;
				pTemp->next->group = pe.group;
			}
			pTemp = pTemp->next;
		}
	}
	fstream file;
	file.open("test.txt", ios::out | ios::binary);
	file.close();
	for (int i = 1; i != record_number + 1; ++i)
		Inject2File(i, 1, "test.txt");
}
void PersonList::Insert(const int &cod)
{
	pTemp = pBegin;
	pCurrent = pBegin;
	while (pTemp->code != cod)
	{
		pCurrent = pTemp;
		pTemp = pTemp->next;
	}
	Person *pNew = new Person;
	if (pTemp->code == 1)
	{
		pNew->code = 1;
		pNew->name = "NULL";
		pNew->sex = "N";
		pNew->phone = "NULL";
		pNew->address = "NULL";
		pNew->zip = "NULL";
		pNew->mail = "NULL";
		pNew->qq = "NULL";
		pNew->group = "NULL";
		pNew->next = pTemp;
		pBegin = pNew;
	}
	else
	{
		pNew->code = pTemp->code;
		pNew->name = "NULL";
		pNew->sex = "N";
		pNew->phone = "NULL";
		pNew->address = "NULL";
		pNew->zip = "NULL";
		pNew->mail = "NULL";
		pNew->qq = "NULL";
		pNew->group = "NULL";
		pNew->next = pTemp;
		pCurrent->next = pNew;
	}
	while (pTemp != pEnd)
	{
		pTemp->code = pTemp->code + 1;
		pTemp = pTemp->next;
	}
	++pEnd->code;
	++record_number;
	fstream file;
	file.open("test.txt", ios::out | ios::binary);
	file.close();
	for (int i = 1; i != record_number + 1; ++i)
		Inject2File(i, 1, "test.txt");
}
void PersonList::Restore(Person * pBack)
{
	pTemp = pBegin;
	while (pTemp->code != pBack->code)
		pTemp = pTemp->next;
	pTemp->name = pBack->name;
	pTemp->sex = pBack->sex;
	pTemp->phone = pBack->phone;
	pTemp->address = pBack->address;
	pTemp->zip = pBack->zip;
	pTemp->mail = pBack->mail;
	pTemp->qq = pBack->qq;
	pTemp->group = pBack->group;
}
void PersonList::BackUp(Person * p, const int& cod)
{
	pTemp = pBegin;
	while (pTemp->code != cod)
		pTemp = pTemp->next;
	p->code = pTemp->code;/////////////copy construct
	p->name = pTemp->name;
	p->phone = pTemp->phone;
	p->sex = pTemp->sex;
	p->address = pTemp->address;
	p->zip = pTemp->zip;
	p->mail = pTemp->mail;
	p->qq = pTemp->qq;
	p->group = pTemp->group;
	p->next = 0;
}
void PersonList::Print_edit(const int & item, const int & code)
{
	pTemp = pBegin;
	while (pTemp->code != code)
		pTemp = pTemp->next;
	cursor_position(10, 4);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "姓名：" << pTemp->name;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 6);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "电话：" << pTemp->phone;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 8);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "性别：" << pTemp->sex;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 10);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "地址：" << pTemp->address;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 12);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "邮编：" << pTemp->zip;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 14);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "邮箱：" << pTemp->mail;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 16);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "QQ号：" << pTemp->qq;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(10, 18);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "群组：" << pTemp->group;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(9, 20);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[保存]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(9, 22);
	if (item == pos.Y)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[取消]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
}
void PersonList::Print_name(int &cur, int &first_code, bool dele, const int &posy)//if record<9????????????????????????
{
	if ((first_code > record_number - 8) && first_code>1)
		first_code = record_number - 8;
	if (record_number < 100)
	{
		cursor_position(67, 23);
		cout << " " << record_number << "位联系人";
	}
	else
	{
		cursor_position(67, 23);
		cout << record_number << "位联系人";
	}
	pTemp = pBegin;
	while (pTemp->code != first_code)
		pTemp = pTemp->next;
	int last;
	if (record_number > 8)
		last = 22;
	else
		last = 4 + record_number * 2;
	if (dele == 1 && record_number < 10 && cur == last)
	{
		cur = cur - 2;
	}
	for (int i = 4; i != last; ++i)
	{
		if (pTemp->code == ((cur - 4)*0.5 + first_code))
			SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(3, i);
		cout << "                  "; //17
		cursor_position(4, i);
		cout << pTemp->name;
		++i;
		cursor_position(3, i);
		cout << "                  "; //17
		cursor_position(4, i);
		cout << pTemp->phone;
		pTemp = pTemp->next;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	}
	if (record_number < 9)
	{
		for (int i = last; i != 22; ++i)
		{
			cursor_position(3, i);
			cout << "                  "; //17
			++i;
			cursor_position(3, i);
			cout << "                  "; //17
			SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		}
	}
	pTemp = pBegin;
	while (pTemp->code != ((cur - 4)*0.5 + first_code))
		pTemp = pTemp->next;
	cursor_position(26, 4);//size of name=70
	cout << "                                                    ";
	cursor_position(26, 4);
	cout << "性别：" << pTemp->sex;
	cursor_position(26, 6);
	cout << "                                                    ";
	cursor_position(26, 6);
	cout << "地址：" << pTemp->address;
	cursor_position(26, 8);
	cout << "                                                    ";
	cursor_position(26, 8);
	cout << "邮编：" << pTemp->zip;
	cursor_position(26, 10);
	cout << "                                                    ";
	cursor_position(26, 10);
	cout << "邮箱：" << pTemp->mail;
	cursor_position(26, 12);
	cout << "                                                    ";
	cursor_position(26, 12);
	cout << "QQ号：" << pTemp->qq;
	cursor_position(26, 14);
	cout << "                                                    ";
	cursor_position(26, 14);
	cout << "群组：" << pTemp->group;
}
void PersonList::Print_search(const string &KW)
{
	for (int i = 4; i != 22; ++i)
	{
		cursor_position(3, i);
		cout << "                  "; //17
	}
	pTemp = pBegin;
	int x = 4;
	while (pTemp != pEnd)//wrong
	{
		int match_name = 0;
		for (int j = 0; j != KW.size(); ++j)
			for (int i = 0; i != (pTemp->name).size(); ++i)
				if (pTemp->name[i] == KW[j])
				{
			++match_name;
			break;
				}

		int match_phone = 0;
		for (int j = 0; j != KW.size(); ++j)
			for (int i = 0; i != (pTemp->phone).size(); ++i)
				if (pTemp->phone[i] == KW[j])
				{
			++match_phone;
			break;
				}

		if (match_name >= KW.size() || match_phone >= KW.size())
		{
			cursor_position(4, x);
			cout << pTemp->name;
			cursor_position(4, x + 1);
			cout << pTemp->phone;
			if (x <= 19)//wrong
				x = x + 2;;
		}
		pTemp = pTemp->next;
	}
}
void PersonList::Edit(const int & item, const int & cod, Person * p)
{
	string line(50, ' ');
	if (item == 4)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 4);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 4);
		cout << "姓名：";
		cursor_position(16, 4);
		show_cursor();
		cin >> pTemp->name;
		if (pTemp->name.size() > 16)
		{
			string Temp(pTemp->name, 0, 16);
			pTemp->name = Temp;
		}
		hide_cursor();
	}
	else if (item == 6)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 6);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 6);
		cout << "电话：";
		cursor_position(16, 6);
		show_cursor();
		cin >> pTemp->phone;
		if (pTemp->phone.size() > 16)
		{
			string Temp(pTemp->phone, 0, 16);
			pTemp->phone = Temp;
		}
		hide_cursor();
	}
	else if (item == 8)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 8);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 8);
		cout << "性别：";
		cursor_position(16, 8);
		show_cursor();
		cin >> pTemp->sex;
		if (pTemp->sex.size() > 2)
		{
			string Temp(pTemp->sex, 0, 2);
			pTemp->sex = Temp;
		}
		hide_cursor();
	}
	else if (item == 10)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 10);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 10);
		cout << "地址：";
		cursor_position(16, 10);
		show_cursor();
		cin >> pTemp->address;
		if (pTemp->address.size() > 42)
		{
			string Temp(pTemp->address, 0, 42);
			pTemp->address = Temp;
		}
		hide_cursor();
	}
	else if (item == 12)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 12);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 12);
		cout << "邮编：";
		cursor_position(16, 12);
		show_cursor();
		cin >> pTemp->zip;
		if (pTemp->zip.size() > 8)
		{
			string Temp(pTemp->zip, 0, 8);
			pTemp->zip = Temp;
		}
		hide_cursor();
	}
	else if (item == 14)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 14);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 14);
		cout << "邮箱：";
		cursor_position(16, 14);
		show_cursor();
		cin >> pTemp->mail;
		if (pTemp->mail.size() > 28)
		{
			string Temp(pTemp->mail, 0, 28);
			pTemp->mail = Temp;
		}
		hide_cursor();
	}
	else if (item == 16)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 16);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 16);
		cout << "QQ号：";
		cursor_position(16, 16);
		show_cursor();
		cin >> pTemp->qq;
		if (pTemp->qq.size() > 13)
		{
			string Temp(pTemp->qq, 0, 13);
			pTemp->qq = Temp;
		}
		hide_cursor();
	}
	else if (item == 18)
	{
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		cursor_position(10, 18);
		cout << line;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(10, 18);
		cout << "群组：";
		cursor_position(16, 18);
		show_cursor();
		cin >> pTemp->group;
		if (pTemp->group.size() > 13)
		{
			string Temp(pTemp->group, 0, 13);
			pTemp->group = Temp;
		}
		hide_cursor();
	}
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
}
void PersonList::Inject2File(const int& cod, const bool& ALL, char* NameOfFile)
{
	pTemp = pBegin;
	while (pTemp->code != cod)
		pTemp = pTemp->next;
	fstream file;
	string filename = NameOfFile;
	file.open(filename.c_str(), ios::in | ios::out | ios::binary);
	//name
	file.seekp((cod - 1)*row_size, ios::beg);
	file.write("                    ", name_size);
	file.seekp((cod - 1)*row_size, ios::beg);
	file.write(pTemp->name.c_str(), pTemp->name.size());
	//sex
	file.seekp((cod - 1)*row_size + name_size, ios::beg);
	file.write("    ", sex_size);
	file.seekp((cod - 1)*row_size + name_size, ios::beg);
	file.write((pTemp->sex).c_str(), pTemp->sex.size());
	//phone
	file.seekp((cod - 1)*row_size + name_size + sex_size, ios::beg);
	file.write("                    ", phone_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size, ios::beg);
	file.write((pTemp->phone).c_str(), pTemp->phone.size());
	//address
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size, ios::beg);
	file.write("                                                                    ", address_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size, ios::beg);
	file.write((pTemp->address).c_str(), pTemp->address.size());
	//zip
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size, ios::beg);
	file.write("          ", zip_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size, ios::beg);
	file.write((pTemp->zip).c_str(), pTemp->zip.size());
	//mail
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size, ios::beg);
	file.write("                              ", mail_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size, ios::beg);
	file.write((pTemp->mail).c_str(), pTemp->mail.size());
	//qq
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size + mail_size, ios::beg);
	file.write("               ", qq_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size + mail_size, ios::beg);
	file.write((pTemp->qq).c_str(), pTemp->qq.size());
	//group
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size + mail_size + group_size, ios::beg);
	file.write("               ", group_size);
	file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size + mail_size + group_size, ios::beg);
	file.write((pTemp->group).c_str(), pTemp->group.size());
	if (ALL == 1)
	{
		file.seekp((cod - 1)*row_size + name_size + sex_size + phone_size + address_size + zip_size + mail_size + group_size, ios::beg);
		file.seekp(15, ios::cur);
		file.write("\r\n", 2);
	}
	file.close();
}
void PersonList::Delete(const int & cod)
{

	pTemp = pBegin;
	pCurrent = pBegin;
	while (pTemp->code != cod)
	{
		pCurrent = pTemp;
		pTemp = pTemp->next;
	}
	if (pTemp->code == 1)
	{
		pBegin = pCurrent->next;
		while (pCurrent != pEnd)
		{
			pCurrent = pCurrent->next;
			pCurrent->code = pCurrent->code - 1;
		}
	}
	else if (pTemp->code == record_number)
	{
		pEnd = pCurrent;
		pEnd->next = 0;
	}
	else
	{
		pCurrent->next = pTemp->next;
		while (pTemp != pEnd)
		{
			pTemp = pTemp->next;
			pTemp->code = pTemp->code - 1;
		}
	}
	record_number = record_number - 1;
	fstream file;
	file.open("test.txt", ios::out | ios::binary);
	file.close();
	for (int i = 1; i != record_number + 1; ++i)
		Inject2File(i, 1, "test.txt");
}
