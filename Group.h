#ifndef _GROUP_H_
#define _GROUP_H_
#include"PersonList.h"
#include<string>
class Group :public PersonList{
public:
	Group();
	void print_group(const int&,const int&);//打印群组选择
	string getgroup(const int&, const int&);//返回某序号的人所属群组
private:
	Person * Pivot;
};
#endif
