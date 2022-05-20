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

//通讯录类型
struct Contact
{
	struct PeoInfo data[MAX];//存放一个信息
	int size;
};

//初始化通讯录
void InitContact(struct Contact* ps);
//增加通讯录信息
void AddContact(struct Contact* ps);
//插入数据
void InsertContact(struct Contact* ps);
//展示增加通讯录信息
void ShowContact(const struct Contact* ps);
//删除指定的联系人
void DelContact(struct Contact* ps);
//查找此人
void SearchContact(const struct Contact* ps);
//更正数据
void ModifyContact(struct Contact* ps);
//排序
void SortContact(struct Contact* ps);