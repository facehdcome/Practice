#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
//通讯录实现
void menu()
{
	printf("\n*******************************************\n");
	printf("*****1. add       2. del     **************\n");
	printf("*****3. search    4. modify  **************\n");
	printf("*****5. show      6. sort    **************\n");
	printf("*****7. save      0. exit    **************\n");
}

int main()
{
	int input = 0;
	//创建1000人的通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		//打印菜单
		switch (input)
		{
		case ADD:
			AddContact(&con);
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
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			//销毁通讯录
			SaveContact(&con);
			DestroyContact(&con);
			printf("\n已退出通讯录\n");
			break;
		default:
			printf("\n没有此选项\n");
			break;
		}


	} while (input  !=  0);

		return 0;
}
