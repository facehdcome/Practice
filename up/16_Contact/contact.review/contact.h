#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_CONTACT	 11
#define MAX_ADDR 50
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
//ö�ٱ����������

//�����ṹ������
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char contact[MAX_CONTACT];
	char addr[MAX_ADDR];
};

//�����ṹ������(ͨѶ¼�洢)
struct  Contact
{
	struct PeoInfo data[MAX];
	int size;
};


//��������
//�������ADD ����
void InitContact(struct Contact* ps);
//�������
void AddContact(struct Contact* ps);
//ɾ��ĳһ�����ݸ�������
void DelContact(struct Contact* ps);
//����ĳһ���˸�������
void SearchContact(struct Contact* ps);
//����ĳ�˵ĵ���Ϣ
void ModifyContact(struct Contact* ps);
//��ʾ�������
void ShowContact(struct Contact* ps);
