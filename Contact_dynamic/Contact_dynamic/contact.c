#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
#include <string.h>
//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	ps->data = malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	ps->size = 0;
	ps->capacity = DEFAULT;
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	LoadContact(ps);
}

//��������
void CheckCapacity(struct Contact* ps);

void LoadContact(struct Contact* ps)
{
	struct PeoInfo temp = { 0 };
	FILE* pfRead = fopen("Contact.data", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact: :%s\n", strerror(errno));
		return;
	}
	//��ȡ�ļ����ŵ�ͨѶ¼
	while (fread(&temp, sizeof(struct PeoInfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = temp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;

}



void CheckCapacity(struct Contact* ps)
{
	//�������
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));//�ͷſռ�
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("\n���ݳɹ�\n");
		}
		else
		{
			printf("\n����ʧ��\n");
		}
	}	
}

void AddContact(struct Contact* ps)
{

	//����������ӿռ䣬����ʲôҲ����

	//if (ps->size == MAX)
	//{
	//	printf("\nͨѶ¼�������޷��ٴ����\n");
	//}
	//else
	//{
	CheckCapacity(ps);//�������

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
			ps->data[i].contact,
			ps->data[i].addr);
	}
}



void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;//����Ұָ��
}

void SaveContact(struct Contact* ps)
{
	FILE* pfwrite = fopen("Contact.data", "wb");
	if (pfwrite == NULL)
	{
		printf("SaveContact: %s\n", strerror(errno));
		return ;
	}
	//���ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]),sizeof(struct PeoInfo),1,pfwrite);

	}

	fclose(pfwrite);
	pfwrite= NULL;

	printf("����ɹ���");
}