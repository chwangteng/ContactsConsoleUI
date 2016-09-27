#ifndef _PERSONLIST_H_
#define _PERSONLIST_H_
#include<string>
#include"Person.h"
class PersonList{
public:
	PersonList(char*);                                //�Ӹ��ļ����������ڸ��ļ���ͨѶ¼����
	~PersonList();                                    //��������
	unsigned int record_number;                       //ͨѶ¼�����е��ڵ�����
	void Print_name(int &, int &, bool, const int&);  //��ӡ���������ֽ���
	void Print_search(const string&);
	void Print_edit(const int &, const int &);        //��ӡ�༭ĳ��ʱ�����ֽ���
	void Edit(const int &, const int &, Person*);     //ѡ�б༭������޸�
	void Restore(Person*);                            //�ڱ༭ģʽ��ʱ���ָ�����δ�༭֮ǰ������
	void BackUp(Person*, const int&);                 //�ڱ༭ģʽ���ǣ����ݸ���δ�༭֮ǰ������
	void Inject2File(const int&, const bool&, char*); //����Ӧ�ı�Žڵ����Ϣע���ļ�
	void Delete(const int &);                 //ɾ����
	void Insert(const int &);                 //�����ˣ�Ĭ����Ϣ��ʼ��ΪNULL
	void Rank();                              //����ƴ����������
	void BackUpFile();                        //����ͨѶ¼
	void RecoveryFile(PersonList &);          //�ָ�ͨѶ¼
	void MoveP();                             //ʹָ��ͷ����β����ָ��Ϊ�գ���Ϊ�������Ѳ���Ҫ����Ӧ�ñ�����
	int search_name(const char*);             //��ȷ��������
	int search_phone(const char*);            //��ȷ�����绰����
	bool search_address(const string&);       //ģ��������ַ
	void search_group(const string&);         //����Ⱥ��
	int get_ori_code(const int &);            //���ԭʼ���
	Person* begin();                          //����ͷָ��ĵ�ַ
	Person* end();                            //����βָ��ĵ�ַ
protected:
	Person * pBegin;
	Person * pEnd;
	Person * pTemp;
	Person * pCurrent;
};
#endif