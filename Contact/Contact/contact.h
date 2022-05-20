#define _CRT_SECURE_NO_WARNINGS 1

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

enum Option
{
	EXIT,
	ADD,
	INSERT,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//ͨѶ¼����
struct Contact
{
	struct PeoInfo data[MAX];//���һ����Ϣ
	int size;
};

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//����ͨѶ¼��Ϣ
void AddContact(struct Contact* ps);
//��������
void InsertContact(struct Contact* ps);
//չʾ����ͨѶ¼��Ϣ
void ShowContact(const struct Contact* ps);
//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);
//���Ҵ���
void SearchContact(const struct Contact* ps);
//��������
void ModifyContact(struct Contact* ps);
//����
void SortContact(struct Contact* ps);