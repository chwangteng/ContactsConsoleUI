#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<sstream>
#include<fstream>
#include"Person.h"
#include"PersonList.h"
#include"Color.h"
#include"Length.h"
#include"Trivia.h"
#include"GUIHelper.h"
#include"Group.h"

using namespace std;

CONSOLE_CURSOR_INFO cci;                                //定义光标信息
COORD pos;                                              //定义光标坐标
HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);  //定义获并得标准输出句柄
HANDLE inPutHandle = GetStdHandle(STD_INPUT_HANDLE);    //定义并获得标准输入句柄
INPUT_RECORD Input_Record;                              //定义输入事件结构体
DWORD res;                                              //定义返回记录

int main()
{
	hide_cursor();
	draw_background();
	draw_user_interface_();
	PersonList per("test.txt");
	int i = 4;
	int first_code=1;
	per.Print_name(i, first_code, 0, NULL);
	for (;;)
	{
		int bound;
		if (per.record_number > 8)
			bound = 19;
		else
			bound = 4 + 2 * per.record_number-3;
		if (per.record_number < 10)
			first_code = 1;
		ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
		if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
		{
			if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				
				if (i == 20 && first_code < per.record_number - 8)
					++first_code;
				if (i < bound)
					i = i + 2;
				hide_cursor(); 
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				
				if (i == 4 && first_code > 1)
					--first_code;
				if (i > 5)
					i = i - 2;
				hide_cursor(); 
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'S'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				draw_search_mode();
				int mode = 1;
				draw_search_mode_select(mode);
				for (;;)
				{
					ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
					if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
					{
						if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (mode < 4)
								++mode;
							draw_search_mode_select(mode);
						}
						else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (mode > 1)
								--mode;
							draw_search_mode_select(mode);
						}
						else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (mode == 1)
							{
								cursor_position(30, 5);
								cout << "查询：";
								cursor_position(36, 5);
								cout << "                    ";
								cursor_position(36, 5);
								show_cursor();
								string name;
								cin >> name;
								int c=per.search_name(name.c_str());
								if (c == 0)
								{
									cursor_position(36, 5);
									cout << "                    ";
									cursor_position(36, 5);
									cout << "没有结果";
									hide_cursor();
									continue;
								}
								else
								{
									i = 4;
									if (c > per.record_number - 8)
										i = (c - (per.record_number - 8)) * 2 + 4;	
									draw_background();
									draw_user_interface_();
									first_code = c;
									if (per.record_number < 10)
									{
										first_code = 1;
										i = (c - first_code) * 2 + 4;
									}
									per.Print_name(i, first_code, 0, NULL);
									hide_cursor();
									break;
								}
							}
							else if (mode == 2)
							{
								cursor_position(30, 5);
								cout << "查询：";
								cursor_position(36, 5);
								cout << "                    ";
								cursor_position(36, 5);
								show_cursor();
								string phone;
								cin >> phone;
								int c = per.search_phone(phone.c_str());
								if (c == 0)
								{
									cursor_position(36, 5);
									cout << "                    ";
									cursor_position(36, 5);
									cout << "没有结果";
									hide_cursor();
									continue;
								}
								else
								{
									i = 4;
									if (c > per.record_number - 8)
										i = (c - (per.record_number - 8)) * 2 + 4;
									first_code = c;
									draw_background();
									draw_user_interface_();
									if (per.record_number < 10)
									{
										first_code = 1;
										i = (c - first_code) * 2 + 4;
									}
									per.Print_name(i, first_code, 0, NULL);
									hide_cursor();
									break;
								}
							}
							else if (mode == 3)
							{
								cursor_position(30, 5);
								cout << "查询：";
								cursor_position(36, 5);
								cout << "                    ";
								cursor_position(36, 5);
								show_cursor();
								string address;
								cin >> address;
								PersonList temp("test.txt");
								bool exist = temp.search_address(address);
								if (exist == 0)
								{
									cursor_position(36, 5);
									cout << "                    ";
									cursor_position(36, 5);
									cout << "没有结果";
									hide_cursor();
									Sleep(1000);
									continue;
								}
								int ic = 4;
								int first_codec = 1;
								draw_background();
								draw_user_interface_2();
								temp.Print_name(ic, first_codec, 0, NULL);
								hide_cursor();
								for (;;)
								{
									int bound;
									if (temp.record_number > 8)
										bound = 19;
									else
										bound = 4 + 2 * temp.record_number - 3;
									if (temp.record_number < 10)
										first_codec = 1;
									ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
									if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
									{
										if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{

											if (ic == 20 && first_codec < temp.record_number - 8)
												++first_codec;
											if (ic < bound)
												ic = ic + 2;
											hide_cursor();
											temp.Print_name(ic, first_codec, 0, NULL);
										}
										else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{

											if (ic == 4 && first_codec > 1)
												--first_codec;
											if (ic > 5)
												ic = ic - 2;
											hide_cursor();
											temp.Print_name(ic, first_codec, 0, NULL);
										}
										else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{
											draw_background();
											draw_user_interface_();
											per.Print_name(i,first_code,0,NULL);
											break;
										}
										else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{
											int realcode=temp.get_ori_code((ic-4)*0.5+first_codec);
											i = 4;
											if (realcode > per.record_number - 8)
												i = (realcode - (per.record_number - 8)) * 2 + 4;
											first_code = realcode;
											draw_background();
											draw_user_interface_();
											if (per.record_number < 10)
											{
												first_code = 1;
												i = (realcode - first_code) * 2 + 4;
											}
											per.Print_name(i, first_code, 0, NULL);
											break;
										}
									}
								}
								break;
							}
							else if (mode == 4)
							{
								Group g;
								draw_group_select();
								int cursor = 6;
								int first = 1;
								g.print_group(cursor,first);
								for (;;)
								{
									int limit;
									if (g.record_number < 4)
										limit = 6 + 3 * (g.record_number - 2) + 1;
									else
										limit = 13;
									if (g.record_number < 5)
										first = 1;
									ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
									if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
									{
										if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{

											if (cursor == 15 && first < g.record_number - 3)
												++first;
											if (cursor < limit)
												cursor = cursor + 3;
											g.print_group(cursor, first);
										}
										else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{

											if (cursor == 6 && first > 1)
												--first;
											if (cursor>8)
												cursor = cursor - 3;
											g.print_group(cursor, first);
										}
										else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
										{
											string group = g.getgroup(cursor, first);
											PersonList temp("test.txt");
											temp.search_group(group);
											int ic = 4;
											int first_codec = 1;
											draw_background();
											draw_user_interface_2();
											temp.Print_name(ic, first_codec, 0, NULL);

											for (;;)
											{
												int bound;
												if (temp.record_number > 8)
													bound = 19;
												else
													bound = 4 + 2 * temp.record_number - 3;
												if (temp.record_number < 10)
													first_codec = 1;
												ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
												if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
												{
													if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
													{

														if (ic == 20 && first_codec < temp.record_number - 8)
															++first_codec;
														if (ic < bound)
															ic = ic + 2;
														hide_cursor();
														temp.Print_name(ic, first_codec, 0, NULL);
													}
													else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
													{

														if (ic == 4 && first_codec > 1)
															--first_codec;
														if (ic > 5)
															ic = ic - 2;
														hide_cursor();
														temp.Print_name(ic, first_codec, 0, NULL);
													}
													else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE&& Input_Record.Event.KeyEvent.bKeyDown == true)
													{
														draw_background();
														draw_user_interface_();
														per.Print_name(i, first_code, 0, NULL);
														break;
													}
													else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
													{
														int realcode = temp.get_ori_code((ic - 4)*0.5 + first_codec);
														i = 4;
														if (realcode > per.record_number - 8)
															i = (realcode - (per.record_number - 8)) * 2 + 4;
														first_code = realcode;
														draw_background();
														draw_user_interface_();
														if (per.record_number < 10)
														{
															first_code = 1;
															i = (realcode - first_code) * 2 + 4;
														}
														per.Print_name(i, first_code, 0, NULL);
														break;
													}
												}
											}break;
										}
									}
								}break;
							}
						}
						else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{

							draw_background();
							draw_user_interface_();
							per.Print_name(i, first_code, 0, NULL);
							break;
						}
					  }
					}
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'D'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				int opinion = 2;
				draw_delete_window(opinion);
				for (;;)
				{
					ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
					if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
					{
						if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							opinion = 2;
							draw_delete_window(opinion);
						}
						else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_LEFT&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							opinion = 1;
							draw_delete_window(opinion);
						}
						else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (opinion == 1)
							{
								per.Delete(((i - 4)*0.5 + first_code));
								per.Print_name(i, first_code, 1, NULL);
								draw_background();
								draw_user_interface_();
								per.Print_name(i, first_code, 0, NULL);
								break;
							}
							if (opinion == 2)//cancel
							{
								draw_background();
								draw_user_interface_();
								per.Print_name(i, first_code, 0, NULL);
								break;
							}
						}
					}
				}
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'A'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				per.Insert(((i - 4)*0.5 + first_code));
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'R'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				per.Rank();
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'B'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				per.BackUpFile();
				BackingUp();
				Sleep(1000);
				draw_background();
				draw_user_interface_();
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'H'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				PersonList rec("backup.txt");
				per.RecoveryFile(rec);
				rec.MoveP();
				Recovering(rec);
				Sleep(2000);
				draw_background();
				draw_user_interface_();
				per.Print_name(i, first_code, 0, NULL);
			}
			else if (Input_Record.Event.KeyEvent.wVirtualKeyCode == 'E'&& Input_Record.Event.KeyEvent.bKeyDown == true)
			{
				Person *pBackup = new Person;
				per.BackUp(pBackup, ((i - 4)*0.5 + first_code));
				draw_edit_mode();
				int selected_item = 4;
				per.Print_edit(selected_item, ((i - 4)*0.5 + first_code));
				for (;;)
				{
					ReadConsoleInput(inPutHandle, &Input_Record, 1, &res);      //读取输入事件
					if (Input_Record.EventType == KEY_EVENT)      //如果当前事件是键盘事件
					{
						if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_DOWN&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if(selected_item<21)
								selected_item = selected_item + 2;
							per.Print_edit(selected_item,((i - 4)*0.5 + first_code));
						}
						if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_UP&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (selected_item>5)
								selected_item = selected_item-2;
							per.Print_edit(selected_item,((i - 4)*0.5 + first_code));
						}
						if (Input_Record.Event.KeyEvent.wVirtualKeyCode == VK_RETURN&& Input_Record.Event.KeyEvent.bKeyDown == true)
						{
							if (selected_item == 22)//cancel
							{
								per.Restore(pBackup);//////if not modified
								draw_background();
								draw_user_interface_();
								per.Print_name(i, first_code, NULL, NULL);
								delete pBackup;
								break;
							}
							else if (selected_item == 20)//save
							{
								per.Inject2File(pBackup->code,0,"test.txt");
								Saving();
								draw_background();
								draw_user_interface_();
								per.Print_name(i, first_code, NULL, NULL);
								delete pBackup;
								break;
							}
							else
								per.Edit(selected_item, ((i - 4)*0.5 + first_code),pBackup);
						}
					}
				}
			}
		}
	}
	
	CloseHandle(outPutHandle);
	
	int j;
	cin >> j;

	CloseHandle(inPutHandle);
	return 0;
}