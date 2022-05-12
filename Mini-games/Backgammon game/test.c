#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//��Ϸ��ʼ
void game()
{
	//���ؽ��
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ��
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//��ʼ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//����Ƿ�Ӯ
		ret = IsWin(board, ROW,COL);
		if (ret != 'C')
		{
			break;
		}


		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
		printf("ƽ��");


}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n��ӭ������������Ϸ��\n");
			game();
			break;
		case 0:
			printf("\n��Ϸ�Ѿ��˳���\n");
			break;
		default:
			printf("\nѡ�����������ѡ��\n");
		}

	} while (input);

}

int main()
{
	test();

	return 0;
}