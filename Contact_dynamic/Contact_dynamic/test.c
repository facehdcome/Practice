#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
//ͨѶ¼ʵ��
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
	//����1000�˵�ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		//��ӡ�˵�
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
			//����ͨѶ¼
			SaveContact(&con);
			DestroyContact(&con);
			printf("\n���˳�ͨѶ¼\n");
			break;
		default:
			printf("\nû�д�ѡ��\n");
			break;
		}


	} while (input  !=  0);

		return 0;
}
