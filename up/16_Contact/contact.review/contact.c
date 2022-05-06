#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
#include <string.h>
//初始化通讯录
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("\n通讯录已满，无法再次添加\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入联系电话:>");
		scanf("%s", ps->data[ps->size].contact);
		printf("请输入家庭地址:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;

		printf("添加成功\n");
	}
}

//实现删除
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

//删除某一行的数据，根据名字
void DelContact(struct Contact* ps)
{
	char name[MAX];
	int i = 0;
	printf("请输入名字:>");
	scanf("%s", name);
	int respond = FindByName(ps,name);


	if (respond == -1)
	{
		printf("对不起，查无此人:>");
	}
	else
	{
		int j = 0;
		for (j = i; j< ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\n删除成功\n");
	}
}

//查找某人，根据姓名
void SearchContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入查找人的名字:>");
	scanf("%s", name);
	int respond = FindByName(ps, name);

	if (respond == -1)
	{
		printf("抱歉，没有此人:\n");
	}
	else
	{
		printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", 
			"名字", "年龄", "性别", "电话", "地址");
		printf("\n%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n", 
			ps->data[respond].name,
			ps->data[respond].age,
			ps->data[respond].sex,
			ps->data[respond].contact,
			ps->data[respond].addr);
	}
}

//根正某人信息
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("亲输入相关名字:>");
	scanf("%s", name);
	int respond = FindByName(ps, name);

	if (respond == -1)
	{
		printf("抱歉，通讯录没有I此人:>");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[respond].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[respond].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[respond].sex);
		printf("请输入联系电话:>");
		scanf("%s", ps->data[respond].contact);
		printf("请输入家庭地址:>");
		scanf("%s", ps->data[respond].addr);

		ps->size++;

		printf("修改完成\n");
	}
}

//显示表的数据
void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("\n通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "名字", "年龄", "性别", "电话", "地址");
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