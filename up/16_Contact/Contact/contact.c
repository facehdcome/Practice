#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include "contact.h"

#include < stdio.h>
#include <string.h>
//初始化通讯录实现
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//设置通讯录只有零个元素
}

//增加通讯录信息实现
void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("\n通讯录已满,无法增加\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("\n添加成功\n");
	}
}

//展示增加通讯录信息实现
void ShowContact(const struct Contact* ps)
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
						ps->data[i].tele,
						ps->data[i].addr);

		}
	}
}

//实现del search
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




//删除指定的联系人
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	int i = 0;
	//1.查找要删除的人在的下标，找不到返回-1
	int respond = FindByName(ps, name);
	//2.删除
	if (respond == -1)
	{
		printf("查无此人:\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("\n删除成功:\n");
	}
}


	//查找指定人的信息
void SearchContact(struct Contact* ps)
	{
		char name[MAX_NAME];
		printf("请输入查找人的信息:\n");
		scanf("%s", name);
		int respond = FindByName(ps, name);
		if (respond == -1)
		{
			printf("查无此人:\n");
		}
		else
		{
			int i = 0;
			printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "名字", "年龄", "性别", "电话", "地址");
			for (i = 0; i < ps->size; i++)
			{
				printf("%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n",
					ps->data[respond].name,
					ps->data[respond].age,
					ps->data[respond].sex,
					ps->data[respond].tele,
					ps->data[respond].addr);

			}

     	}
}


//修改数据
void ModifyContact(struct Contact* ps)
{
		char name[MAX_NAME];
		printf("请输入要修改的人的名字:\n");
		scanf("%s", name);
		int respond = FindByName(ps, name);
		if (respond == -1)
			printf("查无此人:\n");
		else
		{
			printf("请输入名字:>");
			scanf("%s", ps->data[respond].name);
			printf("请输入年龄:>");
			scanf("%d", &(ps->data[respond].age));
			printf("请输入性别:>");
			scanf("%s", ps->data[respond].sex);
			printf("请输入电话:>");
			scanf("%s", ps->data[respond].tele);
			printf("请输入地址:>");
			scanf("%s", ps->data[respond].addr);

			printf("修改完成\n");
		}
}

int cmp(const void* a, const void* b)
{
	return ((struct PeoInfo*)a)->age-((struct PeoInfo*)b)->age;
}
//实现排序
//void SortContact(struct Contact* ps)
//{
//
//		qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp);
//	
//
//	int i = 0;
//	printf("\n%-20s\t %-4s \t%-5s \t%-12s\t %-20s\n", "名字", "年龄", "性别", "电话", "地址");
//	for (i = 0; i < ps->size; i++)
//	{
//		printf("%-20s\t %-4d \t%-5s \t%-12s\t %-20s\n",
//			ps->data[i].name,
//			ps->data[i].age,
//			ps->data[i].sex,
//			ps->data[i].tele,
//			ps->data[i].addr);
//	}
//}
