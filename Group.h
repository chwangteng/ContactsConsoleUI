#ifndef _GROUP_H_
#define _GROUP_H_
#include"PersonList.h"
#include<string>
class Group :public PersonList{
public:
	Group();
	void print_group(const int&,const int&);//��ӡȺ��ѡ��
	string getgroup(const int&, const int&);//����ĳ��ŵ�������Ⱥ��
private:
	Person * Pivot;
};
#endif
