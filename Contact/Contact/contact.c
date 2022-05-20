#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include "contact.h"

#include < stdio.h>
#include <string.h>
//��ʼ��ͨѶ¼ʵ��
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//����ͨѶ¼ֻ�����Ԫ��
}






//����ͨѶ¼��Ϣʵ��β��
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("\nͨѶ¼����,�޷�����\n");
	}
	else
	{
		int k = 0;
		int i = 0;
		printf("�������������Ӽ�����Ϣ��");
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			printf("����������:>");
			scanf("%s", ps->data[ps->size].name);
			printf("����������:>");
			scanf("%d", &(ps->data[ps->size].age));
			printf("�������Ա�:>");
			scanf("%s", ps->data[ps->size].sex);
			printf("������绰:>");
			scanf("%s", ps->data[ps->size].tele);
			printf("�������ַ:>");
			scanf("%s", ps->data[ps->size].addr);

			ps->size++;
			printf("\n��ӳɹ�\n");
		}
	}
}



//��������
void InsertContact(struct Contact* ps)
{
	int pos = 0;
	int i = 0;
	printf("��������������λ�ã�");
	scanf("%d", &pos);
	if (pos < 0 || pos > ps->size)
	{
		pos = ps->size;
		printf("\n����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);

		ps->size++;
		printf("\n��ӳɹ�\n");
	}
	else
	{
		for (i = ps->size - 1; i >= pos; i--)
		{
			ps->data[i + 1] = ps->data[i];
		}
		printf("\n����������:>");
		scanf("%s", ps->data[pos-1].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos-1].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos-1].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos-1].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos-1].addr);

		ps->size++;
		printf("\n��ӳɹ�\n");
	}
}




//ʵ��del search
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0; 
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;

}



//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int i = 0;
	//1.����Ҫɾ�������ڵ��±꣬�Ҳ�������-1
	int respond = FindByName(ps, name);
	//2.ɾ��
	if (respond == -1)
	{
		printf("���޴���:\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\nɾ���ɹ�:\n");
	}
}


	//����ָ���˵���Ϣ
void SearchContact(struct Contact* ps)
	{
		char name[MAX_NAME];
		printf("����������˵���Ϣ:\n");
		scanf("%s", name);
		int respond = FindByName(ps, name);
		if (respond == -1)
		{
			printf("���޴���:\n");
		}
		else
		{
			int i = 0;
			printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
				printf("%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n",
					ps->data[respond].name,
					ps->data[respond].age,
					ps->data[respond].sex,
					ps->data[respond].tele,
					ps->data[respond].addr);
     	}
}



//�޸�����
void ModifyContact(struct Contact* ps)
{
		char name[MAX_NAME];
		printf("������Ҫ�޸ĵ��˵�����:\n");
		scanf("%s", name);
		int respond = FindByName(ps, name);
		if (respond == -1)
			printf("���޴���:\n");
		else
		{
			printf("����������:>");
			scanf("%s", ps->data[respond].name);
			printf("����������:>");
			scanf("%d", &(ps->data[respond].age));
			printf("�������Ա�:>");
			scanf("%s", ps->data[respond].sex);
			printf("������绰:>");
			scanf("%s", ps->data[respond].tele);
			printf("�������ַ:>");
			scanf("%s", ps->data[respond].addr);

			printf("�޸����\n");
		}
}




//չʾ����ͨѶ¼��Ϣʵ��
void ShowContact(const struct Contact* ps)
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
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}



//��������
int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

void SortContact(struct  Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_age);

	int i = 0;
	printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n",
			ps->data[i].name,
			ps->data[i].age,
			ps->data[i].sex,
			ps->data[i].tele,
			ps->data[i].addr);
	}
}

