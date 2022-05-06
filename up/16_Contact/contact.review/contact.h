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
//枚举本身就是整形

//声明结构体数据
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char contact[MAX_CONTACT];
	char addr[MAX_ADDR];
};

//声明结构体数组(通讯录存储)
struct  Contact
{
	struct PeoInfo data[MAX];
	int size;
};


//声明函数
//声明添加ADD 函数
void InitContact(struct Contact* ps);
//添加内容
void AddContact(struct Contact* ps);
//删除某一行数据根据名字
void DelContact(struct Contact* ps);
//查找某一个人根据名字
void SearchContact(struct Contact* ps);
//更正某人的的信息
void ModifyContact(struct Contact* ps);
//显示表的数据
void ShowContact(struct Contact* ps);
