
#include "game.h"
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//��ʼ��Ϸ
void  game()
{
	//1.�׵���Ϣ�洢
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/

	//����
	FindMine(mine, show, ROW, COL);
}

void test()
{
	//���û�ѡ����Ϸ
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ӭ������������Ϸ��\n");
			game();
			break;
		case 0:
			printf("��Ϸ�Ѿ��˳���\n");
			break;
		default:
			printf("û�д�ѡ�������ѡ��\n");
			break;
		}

	} while (input != 0);

}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}