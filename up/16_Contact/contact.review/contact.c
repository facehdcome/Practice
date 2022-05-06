#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
#include <string.h>
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("\nͨѶ¼�������޷��ٴ����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("��������ϵ�绰:>");
		scanf("%s", ps->data[ps->size].contact);
		printf("�������ͥ��ַ:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;

		printf("��ӳɹ�\n");
	}
}

//ʵ��ɾ��
static int  FindByName(struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}

//ɾ��ĳһ�е����ݣ���������
void DelContact(struct Contact* ps)
{
	char name[MAX];
	int i = 0;
	printf("����������:>");
	scanf("%s", name);
	int respond = FindByName(ps,name);


	if (respond == -1)
	{
		printf("�Բ��𣬲��޴���:>");
	}
	else
	{
		int j = 0;
		for (j = i; j< ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\nɾ���ɹ�\n");
	}
}

//����ĳ�ˣ���������
void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("����������˵�����:>");
	scanf("%s", name);
	int respond = FindByName(ps, name);

	if (respond == -1)
	{
		printf("��Ǹ��û�д���:\n");
	}
	else
	{
		printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", 
			"����", "����", "�Ա�", "�绰", "��ַ");
		printf("\n%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n", 
			ps->data[respond].name,
			ps->data[respond].age,
			ps->data[respond].sex,
			ps->data[respond].contact,
			ps->data[respond].addr);
	}
}

//����ĳ����Ϣ
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("�������������:>");
	scanf("%s", name);
	int respond = FindByName(ps, name);

	if (respond == -1)
	{
		printf("��Ǹ��ͨѶ¼û��I����:>");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[respond].name);
		printf("����������:>");
		scanf("%d", &(ps->data[respond].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[respond].sex);
		printf("��������ϵ�绰:>");
		scanf("%s", ps->data[respond].contact);
		printf("�������ͥ��ַ:>");
		scanf("%s", ps->data[respond].addr);

		ps->size++;

		printf("�޸����\n");
	}
}

//��ʾ�������
void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("\nͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].contact,
				ps->data[i].addr);
		}
	}
}