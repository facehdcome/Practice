#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
#include <string.h>
//初始化通讯录
void InitContact(struct Contact* ps)
{
	ps->data = malloc(3 * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	ps->size = 0;
	ps->capacity = DEFAULT;
	//把文件中已经存放的通讯录中的信息加载到通讯录中
	LoadContact(ps);
}

//声明函数
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
	//读取文件，放到通讯录
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
	//检测容量
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(struct PeoInfo));//释放空间
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("\n增容成功\n");
		}
		else
		{
			printf("\n增容失败\n");
		}
	}	
}

void AddContact(struct Contact* ps)
{

	//如果满了增加空间，否则什么也不干

	//if (ps->size == MAX)
	//{
	//	printf("\n通讯录已满，无法再次添加\n");
	//}
	//else
	//{
	CheckCapacity(ps);//检测容量

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

int cmp_age(const void* e1, const void* e2)
{
	return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age;
}

void SortContact(struct  Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), cmp_age);

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



void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;//避免野指针
}

void SaveContact(struct Contact* ps)
{
	FILE* pfwrite = fopen("Contact.data", "wb");
	if (pfwrite == NULL)
	{
		printf("SaveContact: %s\n", strerror(errno));
		return ;
	}
	//数据到文件中
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]),sizeof(struct PeoInfo),1,pfwrite);

	}

	fclose(pfwrite);
	pfwrite= NULL;

	printf("保存成功！");
}