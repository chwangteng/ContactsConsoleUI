#ifndef _TRIVIA_H
#define _TRIVIA_H
#include"PersonList.h"
void cursor_position(const int &, const int &);//设置光标坐标
void hide_cursor();                   //隐藏光标
void show_cursor();                   //显示光标
void draw_background();               //绘制最底层暗蓝色背景
void draw_edit_mode();                //绘制编辑模式下的背景
void draw_user_interface_();          //绘制第一种用户界面
void draw_user_interface_2();         //绘制第二种用户界面
void Saving();                        //绘制保存正在编辑对象时的动画
void BackingUp();                     //绘制备份通讯录时的动画
void Recovering(PersonList&);         //绘制恢复通讯录时的动画
void draw_search_mode();              //绘制搜索模式界面
void draw_search_mode_select(int &);  //绘制搜索模式选择界面
void draw_group_select();             //绘制群组选择界面
void draw_delete_window(const int&);  //绘制删除提示框
#endif