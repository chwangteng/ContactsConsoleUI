#ifndef _PERSON_H_
#define _PERSON_H_
#include<string>
using namespace std;
struct Person
{
	int code;
	int oricode;
	string name;
	string sex;
	string phone;
	string address;
	string zip;
	string mail;
	string qq;
	string group;
	Person *next;
};
#endif