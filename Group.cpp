#include"Group.h"
#include<iostream>
#include"Trivia.h"
#include"Color.h"
#include"GUIHelper.h"
Group::Group() :PersonList("test.txt"){
	pTemp = pBegin;
	pTemp = pTemp->next;
	while (pTemp != 0)
	{
		for (Pivot = pBegin; Pivot != pTemp; Pivot = Pivot->next)
			if (Pivot->group == pTemp->group)
			{
			pCurrent = pBegin;
			while (pCurrent->next != pTemp)
				pCurrent = pCurrent->next;
			if (pTemp->code == record_number)
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
			break;
			}
		pTemp = pTemp->next;
	}
}
void Group::print_group(const int& i,const int& fir)
{
	int last;
	if (record_number > 3)
		last = 18;
	else
		last = 6+record_number*3;
	pTemp = pBegin;
	while (pTemp->code != fir)
		pTemp = pTemp->next;
	cursor_position(42, 19);
	cout << record_number << "¸öÈº×é";
	for (int j = 6; j != last; ++j)
	{
		if (pTemp->code==(((i-6)/3)+fir))
			SetConsoleTextAttribute(outPutHandle, Bwhite_Bred);
		cursor_position(30, j);
		cout << "            ";
		cursor_position(30, j);
		cout << pTemp->group;
		j = j + 2;
		SetConsoleTextAttribute(outPutHandle, Bwhite_Bblue);
		pTemp = pTemp->next;
	}
	/*pTemp = pBegin;
	cursor_position(30, 6);
	cout << pTemp->group;
	cursor_position(30, 9);
	cout << pTemp->next->group;
	cursor_position(30, 12);
	cout << pTemp->next->next->group;
	cursor_position(30, 15);
	cout << pTemp->next->next->next->group;*/
}
string Group::getgroup(const int& i, const int&fir){
	pTemp = pBegin;
	while (pTemp->code != (((i - 6) / 3) + fir))
		pTemp = pTemp->next;
	return pTemp->group;
}