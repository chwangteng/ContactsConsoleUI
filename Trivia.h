#ifndef _TRIVIA_H
#define _TRIVIA_H
#include"PersonList.h"
void cursor_position(const int &, const int &);//���ù������
void hide_cursor();                   //���ع��
void show_cursor();                   //��ʾ���
void draw_background();               //������ײ㰵��ɫ����
void draw_edit_mode();                //���Ʊ༭ģʽ�µı���
void draw_user_interface_();          //���Ƶ�һ���û�����
void draw_user_interface_2();         //���Ƶڶ����û�����
void Saving();                        //���Ʊ������ڱ༭����ʱ�Ķ���
void BackingUp();                     //���Ʊ���ͨѶ¼ʱ�Ķ���
void Recovering(PersonList&);         //���ƻָ�ͨѶ¼ʱ�Ķ���
void draw_search_mode();              //��������ģʽ����
void draw_search_mode_select(int &);  //��������ģʽѡ�����
void draw_group_select();             //����Ⱥ��ѡ�����
void draw_delete_window(const int&);  //����ɾ����ʾ��
#endif