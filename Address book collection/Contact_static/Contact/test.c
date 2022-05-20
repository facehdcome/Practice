#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
#include <string.h>
#include<stdlib.h>
void menu()
{
	printf("\n*******************************************\n");
	printf("********** 1. add        2.insert *********\n");
	printf("********** 3. del        4.search *********\n");
	printf("********** 5. modify     6. show  *********\n");
	printf("********** 7. sort       0. exit  *********\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;//存放1000个人的信息
	//初始化通讯录录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case INSERT:
			InsertContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录");
		default:
			printf("选择错误\n");
			break;
		}
	} while (input != 0);

	return 0;
}