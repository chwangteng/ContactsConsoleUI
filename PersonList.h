#ifndef _PERSONLIST_H_
#define _PERSONLIST_H_
#include<string>
#include"Person.h"
class PersonList{
public:
	PersonList(char*);                                //从该文件名建立基于该文件的通讯录链表
	~PersonList();                                    //析构函数
	unsigned int record_number;                       //通讯录链表中的在档人数
	void Print_name(int &, int &, bool, const int&);  //打印姓名的文字界面
	void Print_search(const string&);
	void Print_edit(const int &, const int &);        //打印编辑某人时的文字界面
	void Edit(const int &, const int &, Person*);     //选中编辑对象的修改
	void Restore(Person*);                            //在编辑模式下时，恢复该人未编辑之前的资料
	void BackUp(Person*, const int&);                 //在编辑模式下是，备份该人未编辑之前的资料
	void Inject2File(const int&, const bool&, char*); //将对应的编号节点的信息注入文件
	void Delete(const int &);                 //删除人
	void Insert(const int &);                 //新增人，默认信息初始化为NULL
	void Rank();                              //按照拼音进行排序
	void BackUpFile();                        //备份通讯录
	void RecoveryFile(PersonList &);          //恢复通讯录
	void MoveP();                             //使指向头部和尾部的指针为空，因为该链表已不需要但不应该被析构
	int search_name(const char*);             //精确搜索姓名
	int search_phone(const char*);            //精确搜索电话号码
	bool search_address(const string&);       //模糊搜索地址
	void search_group(const string&);         //搜索群组
	int get_ori_code(const int &);            //获得原始编号
	Person* begin();                          //返回头指针的地址
	Person* end();                            //返回尾指针的地址
protected:
	Person * pBegin;
	Person * pEnd;
	Person * pTemp;
	Person * pCurrent;
};
#endif