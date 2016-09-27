#include<string>
#include<iostream>
#include"Trivia.h"
#include"GUIHelper.h"
#include"Color.h"
void cursor_position(const int &x, const int &y)   //将指针移到参数指定的位置
{
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(outPutHandle, pos);
}

void hide_cursor()
{
	GetConsoleCursorInfo(outPutHandle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(outPutHandle, &cci);
}

void show_cursor()
{
	GetConsoleCursorInfo(outPutHandle, &cci);
	cci.bVisible = true;
	SetConsoleCursorInfo(outPutHandle, &cci);
}

void draw_background()
{
	cursor_position(0, 0);
	SetConsoleTextAttribute(outPutHandle, Bwhite_Dblue);
	for (int j = 0; j != 80 * 24; ++j)
		cout << " ";
}
void draw_delete_window(const int& opinion)
{
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	for (int i = 0; i != 8; ++i)
	{
		cursor_position(22, 8 + i);
		cout << "                              ";
	}
	cursor_position(25, 9);
	cout << "确定要删除该联系人吗？";
	if (opinion==1)
		SetConsoleTextAttribute(outPutHandle, Bred_Bwhite);
	cursor_position(24, 13);
	cout << "【确定】";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	if (opinion == 2)
		SetConsoleTextAttribute(outPutHandle, Bred_Bwhite);
	cursor_position(38, 13);
	cout << "【取消】";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);

}

void draw_edit_mode()
{
	draw_background();

	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	for (int i = 2; i != 19; ++i)
	{
		cursor_position(8, i);
		cout << "                                                               ";//30
	}
	cursor_position(9, 20);
	cout << "[保存]";
	cursor_position(9, 22);
	cout << "[取消]";
}

void draw_user_interface_()
{
	SetConsoleTextAttribute(outPutHandle, Bwhite_Dblue);
	cursor_position(2, 23);
	cout << "E:编辑" << " " << "D:删除" << " " << "S:搜索" << " " << "A:增加" << " " << "R:排序" << " " << "B:备份" << " " << "H:恢复"<<" "<<"ESC:返回";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(2, 0);
	cout << "                     ";
	cursor_position(2, 1);
	cout << "查询:________________";
	for (int i = 3; i != 23; ++i)
	{

		cursor_position(2, i);
		cout << "                    ";   //20
		cursor_position(24, i);
		cout << "                                                      ";   //54
	}
	cursor_position(0, 0);
}

void draw_user_interface_2()
{
	/*SetConsoleTextAttribute(outPutHandle, Bwhite_Dblue);
	cursor_position(2, 23);
	cout << "E:编辑" << " " << "D:删除tayayya" ;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(2, 0);
	cout << "                     ";
	cursor_position(2, 1);
	cout << "查询:________________";*/
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	for (int i = 3; i != 23; ++i)
	{

		cursor_position(2, i);
		cout << "                    ";   //20
		cursor_position(24, i);
		cout << "                                                      ";   //54
	}
	cursor_position(0, 0);
}
void draw_group_select(){
	draw_background();
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	for (int i = 2; i != 19; ++i)
	{
		cursor_position(25, i);
		cout << "                        ";
	}
	cursor_position(25, 3);
	cout << "=======请选择群组=======";
}

void Saving()
{
	SetConsoleTextAttribute(outPutHandle, Dgreen_Dwhite);
	cursor_position(16, 20);
	cout << " ";
	Sleep(5);
	cout << "  ";
	Sleep(5);
	cout << "  ";
	Sleep(4);
	cout << "  ";
	Sleep(3);
	cout << "  ";
	Sleep(2);
	cout << " ";
	Sleep(2);
	cout << " ";
	Sleep(2);
	cout << " ";
	Sleep(2);
	cout << " ";
	Sleep(1);
	cout << " ";
	Sleep(1);
	cout << " ";
	Sleep(1);
	cout << " ";
	Sleep(1);
	cout << " ";
	Sleep(1);
	cout << "    ";
	Sleep(1);
	cout << "      ";
	cout << "                            ";
}

void BackingUp()
{
	SetConsoleTextAttribute(outPutHandle, Dgreen_Dwhite);
	string str(50, ' ');
	cursor_position(15, 7);
	cout << str;
	cursor_position(15, 8);
	cout << str;
	cursor_position(15, 9);
	cout << str;
	cursor_position(15, 10);
	cout << str;
	cursor_position(15, 11);
	cout << str;
	cursor_position(15, 12);
	cout << str;
	cursor_position(15, 13);
	cout << str;
	cursor_position(15, 14);
	cout << str;
	cursor_position(15, 15);
	cout << str;
	cursor_position(15, 16);
	cout << str;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Dgreen);
	cursor_position(17, 10);
	cout << "   ";
	cursor_position(17, 11);
	cout << "   ";
	Sleep(100);
	cursor_position(20, 10);
	cout << "  ";
	cursor_position(20, 11);
	cout << "  ";
	Sleep(50);
	cursor_position(22, 10);
	cout << "    ";
	cursor_position(22, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(26, 10);
	cout << "    ";
	cursor_position(26, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(30, 10);
	cout << "    ";
	cursor_position(30, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(30, 10);
	cout << "    ";
	cursor_position(30, 11);
	cout << "    ";
	Sleep(10);
	cursor_position(34, 10);
	cout << "              ";
	cursor_position(34, 11);
	cout << "              ";
	Sleep(10);
	cursor_position(44, 10);
	cout << "                 ";
	cursor_position(44, 11);
	cout << "                 ";
	Sleep(100);
	cursor_position(33, 15);
	cout << "【备份成功】";
}

void Recovering(PersonList& PL)
{
	SetConsoleTextAttribute(outPutHandle, Dgreen_Dwhite);
	string str(50, ' ');
	cursor_position(15, 7);
	cout << str;
	cursor_position(15, 8);
	cout << str;
	cursor_position(15, 9);
	cout << str;
	cursor_position(15, 10);
	cout << str;
	cursor_position(15, 11);
	cout << str;
	cursor_position(15, 12);
	cout << str;
	cursor_position(15, 13);
	cout << str;
	cursor_position(15, 14);
	cout << str;
	cursor_position(15, 15);
	cout << str;
	cursor_position(15, 16);
	cout << str;
	SetConsoleTextAttribute(outPutHandle, Bwhite_Dgreen);
	cursor_position(17, 10);
	cout << "   ";
	cursor_position(17, 11);
	cout << "   ";
	Sleep(100);
	cursor_position(20, 10);
	cout << "  ";
	cursor_position(20, 11);
	cout << "  ";
	Sleep(50);
	cursor_position(22, 10);
	cout << "    ";
	cursor_position(22, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(26, 10);
	cout << "    ";
	cursor_position(26, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(30, 10);
	cout << "    ";
	cursor_position(30, 11);
	cout << "    ";
	Sleep(25);
	cursor_position(30, 10);
	cout << "    ";
	cursor_position(30, 11);
	cout << "    ";
	Sleep(10);
	cursor_position(34, 10);
	cout << "              ";
	cursor_position(34, 11);
	cout << "              ";
	Sleep(10);
	cursor_position(44, 10);
	cout << "                 ";
	cursor_position(44, 11);
	cout << "                 ";
	Sleep(100);
	cursor_position(26, 15);
	cout << "【已从" << PL.record_number << "位联系人中恢复】";
}

void draw_search_mode()
{
	draw_background();
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	for (int i = 2; i != 19; ++i)
	{
		cursor_position(8, i);
		cout << "                                                               ";//30
	}
	cursor_position(8, 3);
	cout << "========================请选择搜索模式=========================";
}

void draw_search_mode_select(int & mode)
{
	cursor_position(32, 7);
	if (mode == 1)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[精确搜索姓名]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(32, 9);
	if (mode == 2)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[精确搜索电话]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(32, 11);
	if (mode == 3)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[模糊搜索地址]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
	cursor_position(32, 13);
	if (mode == 4)
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
	cout << "[按群组查看]";
	SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
}